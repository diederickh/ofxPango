#include "ofxPCSurface.h"
#include "ofMain.h"

ofxPCSurface::ofxPCSurface(float fWidth, float fHeight, cairo_format_t nType) {
	cr_surface = cairo_image_surface_create(nType, fWidth, fHeight);
}

ofxPCSurface::~ofxPCSurface() {
	cairo_surface_destroy(cr_surface);
	cairo_surface_finish(cr_surface);
}

void ofxPCSurface::ref(std::string s) {
	cout << "+ ofxPCSurface ("
		<< s << ")"
		<< "ref count: " 
		<< cairo_surface_get_reference_count(cr_surface) 
		<< " on this: " 
		<< this
		<< std::endl;
}

int ofxPCSurface::getWidth() {
	return cairo_image_surface_get_width(cr_surface);
}

int ofxPCSurface::getHeight() {
	return cairo_image_surface_get_height(cr_surface);
}


unsigned char* ofxPCSurface::getPixels() {
	uint32_t* data = (uint32_t*)cairo_image_surface_get_data(cr_surface);
	int pixels = getWidth()*getHeight(); // we assume RGBA for now!
	unsigned char* new_data = new unsigned char[pixels * 4];
	for(int i = 0; i < getWidth(); ++i) {
		for(int j = 0; j < getHeight(); ++j) {
			int pos = (j * getWidth()) + i;
			int dest = (j * getWidth()*4) + i * 4;
			uint32_t p = data[pos];
			int r,g,b,a;
			a = (unsigned char)((p & 0xFF000000) >> 24);
			r = (unsigned char)((p & 0x00FF0000) >> 16);
			g = (unsigned char)((p & 0x0000FF00) >> 8);
			b = (unsigned char)((p & 0x000000FF));
			new_data[dest] = r;
			new_data[dest+1] = g;
			new_data[dest+2] = b;
			new_data[dest+3] = a;
		}
	}
	return new_data;
}

