#include "ofxPCPangoLayout.h"
#include "ofxPCContext.h"
#include "ofxPCPangoFontDescription.h"
#include "ofxPCSurface.h"
#include <iostream>

ofxPCPangoLayout::ofxPCPangoLayout(ofxPCContext* pContext) 
:context(pContext)
{
	pa_layout = pango_cairo_create_layout(pContext->cr_context);
}

ofxPCPangoLayout::~ofxPCPangoLayout() {
	//std::cout << "~~~~ ofxPCPangoLayout" << std::endl;
	delete context;
	g_object_unref(pa_layout);
}

void ofxPCPangoLayout::setJustify(bool bJustify) {
	pango_layout_set_justify(pa_layout, true);
}

void ofxPCPangoLayout::setWidth(int nWidth) {
	pango_layout_set_width(pa_layout, nWidth * PANGO_SCALE);
}


void ofxPCPangoLayout::setText(std::string sText) {
	setText(sText.c_str());
}

void ofxPCPangoLayout::setText(const char* pText, int nLen) {
	pango_layout_set_text(pa_layout, pText, nLen);
}

void ofxPCPangoLayout::setMarkup(std::string sText) {
	setMarkup(sText.c_str());
}

void ofxPCPangoLayout::setMarkup(const char* pText, int nLen) {
	pango_layout_set_markup(pa_layout, pText, nLen);
}

void ofxPCPangoLayout::show() {
	pango_cairo_show_layout(context->cr_context,pa_layout);
}

float ofxPCPangoLayout::getTextHeight() {
	PangoRectangle rect = getPixelExtents();
	return rect.height;
}

void ofxPCPangoLayout::setFontDescription(ofxPCPangoFontDescription oFont) {
	pango_layout_set_font_description(pa_layout, oFont.pa_description);
}

unsigned char* ofxPCPangoLayout::getPixels() {
	return context->getSurface()->getPixels();
}

ofImage ofxPCPangoLayout::getImage() {
	unsigned char* pix = getPixels();
	ofImage img;
	img.allocate(getWidth(),getHeight(), OF_IMAGE_COLOR_ALPHA);
	img.setFromPixels(pix, img.width, img.height, OF_IMAGE_COLOR_ALPHA);
	delete[] pix;
	return img;
}

int ofxPCPangoLayout::getWidth() {
	return context->getSurface()->getWidth();
}

int ofxPCPangoLayout::getHeight() {
	return context->getSurface()->getHeight();
}

void ofxPCPangoLayout::setFont(std::string sFontDesc) {
	ofxPCPangoFontDescription fd;
	fd.createFromString(sFontDesc);
	setFontDescription(fd);
}

void ofxPCPangoLayout::fill(float fR, float fG, float fB, float fA) {
	context->color4f(fR, fG, fB, fA);
    context->paint();
}

void ofxPCPangoLayout::setTextColor(float fR, float fG, float fB, float fA) {
	context->color4f(fR, fG, fB, fA);
}

void ofxPCPangoLayout::setAlignLeft() {
	pango_layout_set_alignment(pa_layout, PANGO_ALIGN_LEFT);
}

void ofxPCPangoLayout::setAlignCenter() {
	pango_layout_set_alignment(pa_layout, PANGO_ALIGN_CENTER);
}

void ofxPCPangoLayout::setAlignRight() {
	pango_layout_set_alignment(pa_layout, PANGO_ALIGN_RIGHT);
}

PangoRectangle ofxPCPangoLayout::getPixelExtents() {
	PangoRectangle rect;
	pango_layout_get_pixel_extents(pa_layout,&rect, NULL);
	return rect;
}