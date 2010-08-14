The scripts compile_cairo.sh and compile_pango.sh are used to create a system 
specific cairo and pango installation. For now these scripts have been created
for **Mac OS 10.6**.

Installation
=============
$ ./compile_cairo.sh reset
$ ./compile_cairo.sh compile pkgconfig
$ ./compile_cairo.sh compile pixman
$ ./compile_cairo.sh compile cairo

$ ./compile_pango.sh reset iconv
$ ./compile_pango.sh reset gettext
$ ./compile_pango.sh reset glib
$ ./compile_pango.sh reset pango
$ ./compile_pango.sh compile gettext
$ ./compile_pango.sh compile iconv
$ ./compile_pango.sh compile glib


      

