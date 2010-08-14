#ifndef OFXPCCONTEXT
#define OFXPCCONTEXT

#include <pango/pangocairo.h>

/**
 * Representation of the Cairo Context. A context is used
 * together with a surface. The context keeps tracks of several
 * settings used to draw onto the surface.
 *
 * @author	Diederick Huijbers <diederick@apollomedia.nl>
 * @version	2010.07.04 - 0.0.1
 */
class ofxPCPangoLayout;
class ofxPCSurface;
class ofxPCContext {
public:
	ofxPCContext(ofxPCSurface* pSurface);
	~ofxPCContext();
	void color4f(float fR, float fG, float fB, float fA);
	void color3f(float fR, float fG, float fB);
	void paint();
	void destroy();
	void translate(double nX, double nY);
	
	ofxPCPangoLayout* createPangoLayout();
	ofxPCSurface* getSurface();
	
	cairo_t* cr_context;
	ofxPCSurface* surface;
private:
	
	
};
#endif