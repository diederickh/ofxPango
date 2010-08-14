#!/bin/sh
builddir=${PWD}/build
pwd=${PWD}
if [ "$1" = "reset" ]; then
	if [ ! -d download ] ; then
		mkdir download
		echo "created ownload dir"
	fi
	if [ ! -d build ] ; then 
		mkdir build
	fi
	cp download/*.tgz ${builddir}/
	
	# get sources
	if [ ! -f ${pwd}/download/pkgconfig.tgz ] ; then
		curl http://pkgconfig.freedesktop.org/releases/pkg-config-0.23.tar.gz -o download/pkgconfig.tgz
	fi
	
	if [ ! -f ${pwd}/download/libpng.tgz ] ; then
		curl ftp://ftp.simplesystems.org/pub/libpng/png/src/libpng-1.4.3.tar.gz -o download/libpng.tgz
		#curl ftp://ftp.simplesystems.org/pub/libpng/png/src/libpng-1.2.40.tar.gz -o download/libpng.tgz
	fi
	
	if [ ! -f ${pwd}/download/pixman.tgz ] ; then
		curl http://www.cairographics.org/releases/pixman-0.16.2.tar.gz -o download/pixman.tgz
	fi
	
	if [ ! -f ${pwd}/download/cairo.tgz ] ; then
		curl http://www.cairographics.org/releases/cairo-1.8.10.tar.gz -o download/cairo.tgz
	fi
	
	#if [ ! -f ${pwd}/download/cairomm.tgz ] ; then
	#	curl http://cairographics.org/releases/cairomm-1.8.4.tar.gz -o download/cairomm.tgz
	#fi
	
	#if [ ! -f ${pwd}/download/libsigc++.tgz ] ; then
	#	curl ftp://ftp.gnome.org/pub/GNOME/sources/libsigc++/2.2/libsigc++-2.2.8.tar.gz -o download/libsigc++.tgz
	#fi
	
	cp download/*.tgz ${builddir}/
	cd ${builddir}

	# extract 
	tar -zxvf pkgconfig.tgz
	tar -zxvf libpng.tgz
	tar -zxvf pixman.tgz
	tar -zxvf cairo.tgz
	if [ -f cairomm.tgz ] ; then 
		tar -zxvf cairomm.tgz
	fi
	if [ -f libsigc++.tgz ] ; then
		tar -zxvf libsigc++.tgz
	fi

	mv pkg-config-* pkgconfig
	mv libpng-* libpng
	mv pixman-* pixman
	mv cairo-* cairo
	#mv cairomm-* cairomm
	#mv libsigc++-* libsigc++
fi

if [ "$1" = "compile" ] ; then

	# compile pkgconfig
	if [ "$2" = "pkgconfig" ] ; then 
        	cd ${builddir}/pkgconfig
	        ./configure --prefix=${builddir}
	    make
        	make install
	fi

	# export system vars
	export PKG_CONFIG=${builddir}/bin/pkg-config
	export PKG_CONFIG_PATH=${builddir}/lib/pkgconfig
	export MACOSX_DEPLOYMENT_TARGET=10.6
	export CC="gcc-4.0"
	export LDFLAGS="-arch ppc -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
	export CFLAGS="-Os -arch ppc -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
	export PATH=${buildir}/bin:${PATH}
		
	# compile libpng
	if [ "$2" = "libpng" ] ; then
		cd ${builddir}/libpng
		./configure --prefix=${builddir} --disable-dependency-tracking --enable-static=yes
		make clean
		make 	
		make install
	fi

	#build cairomm
	#if [ "$2" = "cairomm" ] ; then
	#	
	#	cd ${builddir}/libsigc++
	#	./configure --prefix=${buildir} --enable-static
	#	make clean
	#	make 
	#	#make install
	#	#exit
	#	
    #    	cd ${builddir}/cairomm
    #    	export CAIROMM_LIBS="-arch ppc -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
    #    	export CAIROMM_CFLAGS="-Os -arch ppc -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
    #    	
    #    	./configure --prefix=${builddir} --disable-dependency-tracking --enable-static --disable-xlib  
    #    	make clean
    #    	make
    #    	make install
	#fi
	
	#build pixman
	if [ "$2" = "pixman" ] ; then
        	cd ${builddir}/pixman
        	./configure --prefix=${builddir} --disable-dependency-tracking --enable-static=yes
        	make clean
        	make
        	make install
	fi
	
	#build cairo
	if [ "$2" = "cairo" ] ; then 
		 cd ${builddir}/cairo
		./configure --prefix=${builddir} \
			--disable-xlib --disable-ft \
			--disable-dependency-tracking \
			--enable-static \
			--enable-png=no \
			--enable-svg=no
		make clean
		make
		make install
	fi
	
	# When using cairo-1.8.8 you need this (it does not check the libpng.pc file):		
	#		png_REQUIRES=png14 \
	#		png_LIBS="`${PKG_CONFIG} libpng --libs `" \
	#		png_CFLAGS="`${PKG_CONFIG} libpng --cflags `" 
	
fi


