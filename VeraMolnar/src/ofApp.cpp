#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(232, 232, 232);
	ofSetColor(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetLineWidth(2);
	ofNoFill();

	ofSeedRandom(mouseX);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			float x = ofMap(i, 0, 4, 192, 808);
			float y = ofMap(j, 0, 4, 192, 808);
			for (int k = 0; k < 9; k++) {
				float width = ofMap(k, 0, 9, 16, 161);
				if (ofRandom(0, 1) < 0.99) {
					ofDrawRectangle(x, y, width, width);
				}
			}
			
			


		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
