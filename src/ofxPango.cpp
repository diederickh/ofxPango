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

ofxPCPangoLayout* ofxPango::createLayout(float fWidth, float fHeight) {
	ofxPCContext* context = createContextWithSurface(fWidth, fHeight);
	ofxPCPangoLayout* layout = context->createPangoLayout();
	layout->setWidth(fWidth);
	return layout;
}
