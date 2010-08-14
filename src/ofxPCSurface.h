#ifndef OFXPCSURFACEH
#define OFXPCSURFACEH

#include <pango/pangocairo.h>
#include <string> // tmp
class ofxPCSurface {
public:
	ofxPCSurface(
			float fWidth
			,float fHeight
			,cairo_format_t nType = CAIRO_FORMAT_ARGB32
	);
	~ofxPCSurface();
	int getWidth();
	int getHeight();
	unsigned char* getPixels();
	void ref(std::string s = "");
	cairo_surface_t* cr_surface;
private:
	
};
#endif