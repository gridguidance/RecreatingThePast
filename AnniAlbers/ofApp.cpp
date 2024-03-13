#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(254, 110, 37);
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	ofEnableDepthTest();
	//cam.begin();
	const float a = 11;
	const float b = 13;
	const int pointNo = 127;
	const float amp = 36;

	ofNoFill();
	ofPushMatrix();
	ofTranslate(500, 500, 0);
    float dt = 2 * PI / pointNo;
    float dia = 10;
    float margin = 100;
	float A = 500;
	float B = 500;
    float delta = PI / 4;

	//ofDisableDepthTest();

    for (int j = 0; j < 4; j++) {	
		//ofSetColor(255);
        ofSetColor(abs(((j % 2) * 232)-232));
        float strokeW;
        if (j == 0) strokeW = 40;
        else if (j == 1) strokeW = 24;
        else if (j == 2) strokeW = 18;
        else strokeW = 4;
        ofSetLineWidth(strokeW);
		//ofEnableSmoothing();
		//ofSetLineWidth(4);
		ofSetPolyMode(OF_POLY_WINDING_ODD);
		ofSetCurveResolution(1200);
		//ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        ofBeginShape();
        for (int i = 0; i <= pointNo + 1; i++) {
            ofSeedRandom(i);
            float x = (A - margin) * sin(a * dt * i + delta);
            float y = (B - margin) * sin(b * dt * i);
            float dx = a * cos(a * dt * i + delta);
            float dy = b * cos(b * dt * i);
            dx = dx / sqrt(dx * dx + dy * dy);
            dy = dy / sqrt(dx * dx + dy * dy);
            float noise_ = (i % pointNo == 1 || i % pointNo == 0) ? 0 : amp * pow(-1, i) * ofNoise(i / (pointNo * PI));
            x = x + noise_ * dy;
            y = y - noise_ * dx;
            ofCurveVertex(x, y, i+j);
        }
        //ofCurveVertex((A - margin) * sin(delta) + A, B, 0);
        ofEndShape(bClose = true);
		ofDisableBlendMode();
    }
	ofPopMatrix();
	//cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's' || key == 'S') {
		ofSaveScreen("screenshot.png");
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
