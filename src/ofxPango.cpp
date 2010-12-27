#include "ofxPango.h"
#include "ofxPCContext.h"
#include "ofxPCSurface.h"

ofxPango::ofxPango() {
}

ofxPCContext* ofxPango::createContextWithSurface(float fWidth, float fHeight) {
	ofxPCSurface* surface = new ofxPCSurface(fWidth, fHeight);
	ofxPCContext* context = new ofxPCContext(surface);
	return context;
}

/**
 * A layout is used to align text onto a surface. For example if you want to 
 * right align text, you can use a layout together with a surface. This method
 * sets up exactly what you need for this.
 *
 */
ofxPCPangoLayout* ofxPango::createLayout(float fWidth, float fHeight) {
	ofxPCContext* context = createContextWithSurface(fWidth, fHeight);
	ofxPCPangoLayout* layout = context->createPangoLayout();
	layout->setWidth(fWidth);
	return layout;
}
