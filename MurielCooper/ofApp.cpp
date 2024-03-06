#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	font.load("framd.ttf", 100, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {

	//Adapted from recreation by Sam Spaulding

	ofBackground(0);
	int TEXT_OFFSET = 115;

	//Initialize vectors for names and topics
	vector<std::string> names;
	vector<std::string> topics;


	//Add new elements to the end of the vector
	names.push_back("Edith Ackerman");
	topics.push_back("Learning");

	names.push_back("Ken Haase");
	topics.push_back("Machine Understanding");

	names.push_back("Henry Lieberman");
	topics.push_back("Media That Learns");

	names.push_back("Patty Maes");
	topics.push_back("Autonomous Agents");

	names.push_back("Marvin Minsky");
	topics.push_back("Society of Mind");

	names.push_back("Seymour Papert");
	topics.push_back("School of the Future");

	names.push_back("Mitchell Resnick");
	topics.push_back("Tools to Think With");


	ofEnableDepthTest();

	//Initialize 3d camera
	cam.begin();
	//ofDrawAxis(200);

	//Test Values
	//ofDrawRectangle(0, 0, 100, 100);
	//ofSetColor(255, 255, 255);
	//font.drawString("Barry Vercoe", 0, 0);

	for (decltype(names.size()) i = 0; i < names.size(); i++) {
		ofPushMatrix(); //store the coordinate system we drew 'hello' in on a stack
		ofScale(1, -1);

		ofSetColor(153, 161, 168, 50);
		vector<ofPath> namePath = font.getStringAsPoints(names[i]);
		vector<ofPath> topicPath = font.getStringAsPoints(topics[i]);
		ofTranslate(0, i * TEXT_OFFSET);

		for (decltype(names.size()) j = 0; j < namePath.size(); j++) {
			ofEnableBlendMode(OF_BLENDMODE_SCREEN);
			namePath[j].draw();

			
			ofDisableBlendMode();

			// Get Outlines
            namePath[j].setPolyWindingMode(OF_POLY_WINDING_ODD);
            vector <ofPolyline> lines = namePath[j].getOutline();

            for (decltype(lines.size()) k = 0; k < lines.size(); k++) {
                lines[k].setClosed(true);
				ofSetColor(153, 161, 168);
                lines[k] = lines[k].getResampledBySpacing(1);

				for (decltype(lines.size()) l = 0; l < lines[k].size(); l++) {
                    lines[k][l].x += 1*sin(2*(ofGetElapsedTimef() + .05*lines[k][l].y + 10*j));
					ofSetLineWidth(2);
					lines[k].draw();

					ofPushMatrix();
					ofTranslate(-.1, -.1, 0);
					ofEnableBlendMode(OF_BLENDMODE_ALPHA);
					lines[k].draw();
					ofDisableBlendMode();
					ofPopMatrix();	
                }
            }
		}
		ofPopMatrix();
		

		//New coordinate frame to draw topics
		ofPushMatrix();
		ofScale(1, -1);
		ofRotateYDeg(75);
		ofSetColor(40, 64, 93);
		ofTranslate(0, i * TEXT_OFFSET);
		
		for (decltype(names.size()) j = 0; j < topicPath.size(); j++) {
			topicPath[j].draw();
		}
		ofPopMatrix();
	}
	cam.end();

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
