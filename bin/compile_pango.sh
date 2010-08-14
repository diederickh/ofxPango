#!/bin/sh

# interesting read: 
# http://x11.gp2x.de/personal/google/
# http://cocoawithlove.com/2009/09/building-for-earlier-os-versions-in.html
# make sure you compile against 10.5 in xcode
# example on using pango_layout: http://paps.sourceforge.net/doxygen-html/
# http://x11.gp2x.de/personal/google/ # examples!!	
# http://paps.sourceforge.net/doxygen-html/
# reset from top to bottom then
# compile from top to bottom.
builddir=${PWD}/build

if [ "$1" = "reset" ]; then
	#libiconv
	if [ "$2" = "iconv" ]; then 
		rm -r ${builddir}/gettext
		if [ ! -f download/iconv.tgz ] ; then 
			curl http://ftp.gnu.org/pub/gnu/libiconv/libiconv-1.13.1.tar.gz -o iconv.tgz
			cp iconv.tgz download/
		fi
		
		cp download/iconv.tgz ${builddir}
		
		# extract and rename dirs.
		cd ${builddir}
		tar -zxvf iconv.tgz
		mv libiconv-* iconv
	fi
	
	#gettext
	if [ "$2" = "gettext" ]; then 
		rm -r ${builddir}/gettext
		if [ ! -f download/gettext.tgz ] ; then 
			curl http://ftp.gnu.org/pub/gnu/gettext/gettext-0.18.1.1.tar.gz -o gettext.tgz
			cp gettext.tgz download/
		fi
		
		cp download/gettext.tgz ${builddir}
		
		# extract and rename dirs.
		cd ${builddir}
		tar -zxvf gettext.tgz
		mv gettext-* gettext
	fi

	#glib
	if [ "$2" = "glib" ]; then 
		rm -r ${builddir}/glib
		if [ ! -f download/glib.tgz ] ; then
			curl ftp://ftp.gtk.org/pub/glib/2.25/glib-2.25.9.tar.gz -o glib.tgz
			cp glib.tgz ${builddir}
		fi
		
		# extract and rename dirs.
		cd ${builddir}
		tar -zxvf glib.tgz
		mv glib-* glib
	fi
	
	#pango
	if [ "$2" = "pango" ]; then 
		rm -r ${builddir}/pango
		
		if [ ! -f download/pango.tgz ] ; then
			curl ftp://ftp.gnome.org/pub/GNOME/sources/pango/1.28/pango-1.28.1.tar.gz -o download/pango.tgz
			cp download/pango.tgz ${builddir}/pango.tgz
		fi
		
		# extract and rename dirs.
		cd ${builddir}
		tar -zxvf pango.tgz
		mv pango-* pango
	fi
	
	
fi

if [ "$1" = "compile" ] ; then
	export PKG_CONFIG=${builddir}/bin/pkg-config
	export PKG_CONFIG_PATH=${builddir}/lib/pkgconfig
	export MACOSX_DEPLOYMENT_TARGET=10.6
	export CC="gcc-4.0"
	if [ "$2" = "pango" ] ; then 
		export LDFLAGS="-arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
		export CFLAGS="-Os -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
	else
		 # I compiled everything with these arch flags, but only pango with above!
		export LDFLAGS="-arch ppc -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
		export CFLAGS="-Os -arch ppc -arch i386 -isysroot /Developer/SDKs/MacOSX10.6.sdk"
	fi
	
	# note that I could not compile gettext with -arch ppc, after I compiled gettext
	# i removed the -arch ppc again, and continued
	export PATH=${builddir}/bin:${PATH}
	
	
	#compile gettext
	if [ "$2" = "gettext" ]; then
		cd ${builddir}/gettext
		./configure --prefix=${builddir} --disable-dependency-tracking --enable-static=yes
		make clean
		make 	
		make install
	fi
	
	# compile iconv
	if [ "$2" = "iconv" ]; then
		cd ${builddir}/iconv
		./configure --prefix=${builddir} --disable-dependency-tracking --enable-static=yes
		make clean
		make 	
		make install
	fi
	
	
	#compile glib
	if [ "$2" = "glib" ]; then
		cd ${builddir}/glib
		./configure --prefix=${builddir} \
			--disable-dependency-tracking \
			CFLAGS="-I${builddir}/include/ -L${builddir}/lib/" \
			LDFLAGS="-L${builddir}/lib" \
			CPPFLAGS="-I${builddir}/include" \
			--disable-dtrace \
			--enable-static=yes
		make clean
		make 	
		make install
	fi
	
	# compile pango
	if [ "$2" = "pango" ]; then
		cd ${builddir}/pango
		./configure --prefix=${builddir} \
			--disable-dependency-tracking \
			--enable-static \
			--with-included-modules=yes
		make clean
		make 	
		make install
	fi
	
fi


