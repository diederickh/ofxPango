#ifndef OFXPCPANGOFONTDESCRIPTIONH
#define OFXPCPANGOFONTDESCRIPTIONH

#include <pango/pangocairo.h>
#include <string>
class ofxPCPangoFontDescription {
public:
	ofxPCPangoFontDescription();
	void createFromString(std::string sFont);
	void createFromString(const char* pFontSpec);
	
	void setStyle(PangoStyle nStyle = PANGO_STYLE_NORMAL);
	void setVariant(PangoVariant nVariant = PANGO_VARIANT_NORMAL);
	void setWeight(PangoWeight nWeight = PANGO_WEIGHT_NORMAL);
	void setStretch(PangoStretch nStretch = PANGO_STRETCH_NORMAL);
	PangoFontDescription* pa_description;
	
private:
};
#endif