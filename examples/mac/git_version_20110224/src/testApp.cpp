#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
ofEnableAlphaBlending();
    ofBackground(255,255,255);

    pango = new ofxPango();
    context = pango->createContextWithSurface(450.0f, 800.0f);
    context->color4f(1.0f, 1.0f, 1.0f, 0.0f);
    context->paint();

    layout = context->createPangoLayout();
    layout->setText("ライブラリーでは、所蔵資料の中からテーマにそった小さな展示を行っています。6月から始まったミニ展示「明治・大正時代の日本ガイドブック」、2回目の7月は「古都の旅」と題し、外国人旅行者のために書かれた京都や奈良のガイドブックを展示します。\n\n 한국에서 발매할 PS3는3월에 유럽에서 발매한 PS3와 동일한 최신 모델을 사용하여 새롭게 의 대용량 HDD(하드디스크 드라이브)를 표준 탑재하고 있다.  대용량HDD를 탑재함으로써 PS3발매와 동시에 실시할 온라인 서비스 “PLAYSTATION®Network”로 선보이게 될 다양한 엔터테인먼트 콘텐츠 다운로드와 온라인 게임 및 온라인 서비스를 보다 쾌적하게 사용할 수 있도록 하였다.\n\nHovedgruppen må være på minimum 10 personer, men deltakere kan knytte seg til hovedgruppen fra forskjellige destinasjoner. Tilknytningsbillett er gyldig inntil 24 timer før avreise hovedgruppe.\n\nUnicef said 3m people had been affected and more than 1,400 had been killed. The government said some 27,000 people remained trapped and awaiting help.");
    layout->setWidth(450.0f);
    layout->setJustify(true);
    context->color4f(0.1f, 0.1f, 0.1f, 1.0f);

    ofxPCPangoFontDescription* fd = new ofxPCPangoFontDescription();
	fd->createFromString("Arial Unicode MS 11");
	layout->setFontDescription(*fd);
	layout->show();

    text_image.allocate(context->getSurface()->getWidth(), context->getSurface()->getHeight(), OF_IMAGE_COLOR_ALPHA);
    text_image.setFromPixels(context->getSurface()->getPixels(), text_image.width, text_image.height, OF_IMAGE_COLOR_ALPHA, true);
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	text_image.draw(10,10);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}