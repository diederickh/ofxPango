#ifndef OFXPANGOH
#define OFXPANGOH
/**
 * Wrapper for Pango & Cairo for advance text rendering.
 * If you want to use this addon, you need to add the search paths
 * to your compiler settings. For XCode this means adding:
 *
 * ../../../addons_diederick/ofxPango/libs/
 * or ..../../../addons/ofxPango/libs/
 *
 * .. with the [x] recursive flag set.
 *
 * @author	Diederick Huijbers <diederick@apollomedia.nl>
 * @version	0.0.1 2010.07.03
 */

#include <pango/pangocairo.h>
#include "ofxPCContext.h"
#include "ofxPCSurface.h"
#include "ofxPCPangoLayout.h"
#include "ofxPCPangoFontDescription.h"

class ofxPango {
public:
	ofxPango();
	ofxPCContext* createContextWithSurface(float fWidth, float fHeight);
	ofxPCPangoLayout* createLayout(float fWidth, float fHeight);
private:
};
#endif