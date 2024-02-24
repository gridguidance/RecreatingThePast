#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//graphic modifiers
	ofBackground(0, 0, 0, 255);
	ofSetLineWidth(5);

	ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	for (int i = 0; i < 40; i++) {
		// set reference variables for angle modifiers
		float VarA = 2;
		float VarB = 3.7;
		float VarC = .5;
		float VarD = 3.8;


		//Set up base path

		float xorig = 500;
		float yorig = 500;
		float radius = ofMap(sin(ofGetElapsedTimef()*.300), -1, 1, 250, 400);
		float radiusB = ofMap(sin(ofGetElapsedTimef()*.700), -1, 1, 250, 400);
		float angle = (ofGetElapsedTimef()) + (.01*i);


		////// SHAPE 1 //////

		//Shape 1_(+/+) (positive radius, positive angle)
		ofSetColor(231, 154, 123, 35);

		float x = xorig + radius * cos(angle * VarA);
		float y = yorig + radius * sin(angle* VarB);
		ofDrawCircle(x, y, 2);

		float w = xorig + radius * cos(angle * VarC);
		float v = yorig + radius * sin(angle*VarD);
		ofDrawCircle(w, v, 2);


		ofPoint pta;
		pta.set(x, y);
		ofPoint ptb;
		ptb.set(w, v);
		//ofDrawLine(pta, ptb);

		// Shape 1 Style Transforms
		ofPushMatrix();
		ofTranslate(1, 1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

		ofDrawLine(pta, ptb);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(2, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofDrawLine(pta, ptb);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(1, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(pta, ptb);
		ofPopMatrix();


		ofPushMatrix();
		ofTranslate(-1, -1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

		ofDrawLine(pta, ptb);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-1, -2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(pta, ptb);
		ofPopMatrix();

		ofPushMatrix();
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofTranslate(-2, -2, 0);
		ofDrawLine(pta, ptb);
		ofPopMatrix();

		// Shape 1 Draw + Reset
		ofSetLineWidth(6);
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofDrawLine(pta, ptb);
		ofSetLineWidth(5);
		ofDisableBlendMode();

		////// SHAPE 2 //////

		//Shape 2_(-/-) (negative radius, negative angle)
		ofSetColor(217, 215, 166, 35);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);

		float xA = xorig - radiusB * cos(angle * -VarA);
		float yA = yorig - radiusB * sin(angle*-VarB);
		ofDrawCircle(xA, yA, 2);

		float wA = xorig - radiusB * cos(angle * -VarC);
		float vA = yorig - radiusB * sin(angle*-VarD);
		ofDrawCircle(wA, vA, 2);

		ofPoint ptc;
		ptc.set(xA, yA);
		ofPoint ptd;
		ptd.set(wA, vA);
		//ofDrawLine(ptc, ptd);

		// Shape 2 Style Transforms
		ofPushMatrix();
		ofTranslate(1, 1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
		ofDrawLine(ptc, ptd);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(2, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofDrawLine(ptc, ptd);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(1, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(ptc, ptd);
		ofPopMatrix();


		ofPushMatrix();
		ofTranslate(-1, -1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

		ofDrawLine(ptc, ptd);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-1, -2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(ptc, ptd);
		ofPopMatrix();

		ofPushMatrix();
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofTranslate(-2, -2, 0);
		ofDrawLine(ptc, ptd);
		ofPopMatrix();

		// Shape 2 Draw + Reset
		ofSetLineWidth(6);
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofDrawLine(ptc, ptd);
		ofSetLineWidth(5);
		ofDisableBlendMode();


		////// SHAPE 3 //////

		// Shape 3_(+/-) (positive radius, negative angle)
		ofSetColor(146, 72, 80, 35);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);

		float xB = xorig + radiusB * cos(angle * -VarA);
		float yB = yorig + radiusB * sin(angle*-VarB);
		ofDrawCircle(xB, yB, 2);

		float wB = xorig + radiusB * cos(angle * -VarC);
		float vB = yorig + radiusB * sin(angle*-VarD);
		ofDrawCircle(wB, vB, 2);

		ofPoint pte;
		pte.set(xB, yB);
		ofPoint ptf;
		ptf.set(wB, vB);
		//ofDrawLine(pte, ptf);


		// Shape 3 Style Transforms
		ofPushMatrix();
		ofTranslate(1, 1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
		ofDrawLine(pte, ptf);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(2, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofDrawLine(pte, ptf);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(1, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(pte, ptf);
		ofPopMatrix();


		ofPushMatrix();
		ofTranslate(-1, -1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

		ofDrawLine(pte, ptf);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-1, -2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(pte, ptf);
		ofPopMatrix();

		ofPushMatrix();
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofTranslate(-2, -2, 0);
		ofDrawLine(pte, ptf);
		ofPopMatrix();

		// Shape 3 Draw + Reset
		ofSetLineWidth(6);
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofDrawLine(pte, ptf);
		ofSetLineWidth(5);
		ofDisableBlendMode();

		////// SHAPE 4 //////

		// Shape 4_(-/+) (negative radius, positive angle)
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofSetColor(191, 210, 214, 35);

		float xC = xorig - radius * cos(angle * VarA);
		float yC = yorig - radius * sin(angle*VarB);
		ofDrawCircle(xC, yC, 2);



		float wC = xorig - radius * cos(angle * VarC);
		float vC = yorig - radius * sin(angle*VarD);
		ofDrawCircle(wC, vC, 2);

		ofPoint ptg;
		ptg.set(xC, yC);
		ofPoint pth;
		pth.set(wC, vC);


		// Shape 4 Style Transforms
		ofPushMatrix();
		ofTranslate(1, 1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

		ofDrawLine(ptg, pth);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(2, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofDrawLine(ptg, pth);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(1, 2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(ptg, pth);
		ofPopMatrix();


		ofPushMatrix();
		ofTranslate(-1, -1, 0);
		ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

		ofDrawLine(ptg, pth);
		ofPopMatrix();

		ofPushMatrix();
		ofTranslate(-1, -2, 0);
		ofEnableBlendMode(OF_BLENDMODE_ALPHA);
		ofDrawLine(ptg, pth);
		ofPopMatrix();

		ofPushMatrix();
		ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);
		ofTranslate(-2, -2, 0);
		ofDrawLine(ptg, pth);
		ofPopMatrix();

		// Shape 4 Draw + Reset
		ofSetLineWidth(6);
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		ofDrawLine(ptg, pth);
		ofSetLineWidth(5);
		ofDisableBlendMode();









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
