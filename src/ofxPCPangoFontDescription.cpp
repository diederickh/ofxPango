#include "ofxPCPangoFontDescription.h"
ofxPCPangoFontDescription::ofxPCPangoFontDescription() 
:pa_description(NULL)
{

}


// pass i.e. "Hiragino Maru Gothic ProN 15" 
void ofxPCPangoFontDescription::createFromString(std::string sFontSpec) {
	createFromString(sFontSpec.c_str());
}
void ofxPCPangoFontDescription::createFromString(const char* pFontSpec) {
	pa_description = pango_font_description_from_string(pFontSpec);
}


/**
 *
 * @param	PangoStyle		 
 * - PANGO_STYLE_NORMAL
 * - PANGO_STYLE_OBLIQUE
 * - PANGO_STYLE_ITALIC
 */
void ofxPCPangoFontDescription::setStyle(PangoStyle nStyle) {
	if(pa_description == NULL)	return;
	 pango_font_description_set_style(pa_description, nStyle);
}

/**
 * @param	PangoVariant:
 *
 * - PANGO_VARIANT_NORMAL
 * - PANGO_VARIANT_SMALL_CAPS
 */
void ofxPCPangoFontDescription::setVariant(PangoVariant nVariant) {
	if(pa_description == NULL); return;
	pango_font_description_set_variant(pa_description, nVariant);
}

/**
 * @param PangoWeight
 *
 * - PANGO_WEIGHT_THIN
 * - PANGO_WEIGHT_ULTRALIGHT
 * - PANGO_WEIGHT_LIGHT
 * - PANGO_WEIGHT_BOOK
 * - PANGO_WEIGHT_NORMAL
 * - PANGO_WEIGHT_MEDIUM
 * - PANGO_WEIGHT_SEMIBOLD
 * - PANGO_WEIGHT_BOLD
 * - PANGO_WEIGHT_ULTRABOLD
 * - PANGO_WEIGHT_HEAVY
 * - PANGO_WEIGHT_ULTRAHEAVY
 */
void ofxPCPangoFontDescription::setWeight(PangoWeight nWeight) {
	if(pa_description == NULL); return;
	pango_font_description_set_weight(pa_description, nWeight);
}

/**
 * @param	PangoStretch
 * - PANGO_STRETCH_ULTRA_CONDENSED
 * - PANGO_STRETCH_EXTRA_CONDENSED
 * - PANGO_STRETCH_CONDENSED
 * - PANGO_STRETCH_SEMI_CONDENSED
 * - PANGO_STRETCH_NORMAL
 * - PANGO_STRETCH_SEMI_EXPANDED
 * - PANGO_STRETCH_EXPANDED
 * - PANGO_STRETCH_EXTRA_EXPANDED
 * - PANGO_STRETCH_ULTRA_EXPANDED
 */
void ofxPCPangoFontDescription::setStretch(PangoStretch nStretch) {
	if(pa_description == NULL); return;
	pango_font_description_set_stretch(pa_description, nStretch);
}