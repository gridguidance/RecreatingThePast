#include "ofApp.h"
void ofApp::dilate(ofImage & imgSrc, ofImage & imgDest) {
	for (int i = 0; i < imgSrc.getWidth(); i++) {
		for (int j = 0; j < imgSrc.getHeight(); j++) {

			// step determines "thickness" of edge offsets
			int step = 2;
			int twostep = (step * 3);

			// constrain values to stay within canvas edges:
			// i_m_1 refers to i_minus_1, i_p_1 refers to i_plus_1
			int i_m_1 = ofClamp(i - step, 0, imgSrc.getWidth() - step);
			int i_p_1 = ofClamp(i + step, 0, imgSrc.getWidth() - step);
			int j_m_1 = ofClamp(j - step, 0, imgSrc.getHeight() - step);
			int j_p_1 = ofClamp(j + step, 0, imgSrc.getHeight() - step);

			int i_m_2 = ofClamp(((i_m_1)-twostep), 0, imgSrc.getWidth() - step);
			int i_p_2 = ofClamp(((i_p_1)+twostep), 0, imgSrc.getWidth() - step);
			int j_m_2 = ofClamp(((j_m_1)-twostep), 0, imgSrc.getHeight() - step);
			int j_p_2 = ofClamp(((j_p_1)+twostep), 0, imgSrc.getHeight() - step);


			// neighbour values
			ofColor n_ = imgSrc.getColor(i, j_p_1);
			ofColor ne = imgSrc.getColor(i_p_1, j_p_1);
			ofColor e_ = imgSrc.getColor(i_p_1, j);
			ofColor se = imgSrc.getColor(i_p_1, j_m_1);
			ofColor s_ = imgSrc.getColor(i, j_m_1);
			ofColor sw = imgSrc.getColor(i_m_1, j_m_1);
			ofColor w_ = imgSrc.getColor(i_m_1, j);
			ofColor nw = imgSrc.getColor(i_m_1, j_p_1);

			// Unused adjacent corner pixels:
			//sw.getBrightness() < 127 ||
			//ne.getBrightness() < 127 ||
			//se.getBrightness() < 127 ||
			//nw_.getBrightness() < 127 ||

			//If any directly adjacent pixel is black, set pixel color to black
			if (n_.getBrightness() < 127 ||
				e_.getBrightness() < 127 ||
				s_.getBrightness() < 127 ||
				w_.getBrightness() < 127) {
				imgDest.setColor(i, j, ofColor(0));

				//Specific conditions to modify erosion behavior

				//imgDest.setColor(i_p_2, j_m_2, ofColor(255));
				//imgDest.setColor(i_p_2, j_m_1, ofColor(255));
				//imgDest.setColor(i_p_2, j, ofColor(255));
				//imgDest.setColor(i_p_2, j_p_1, ofColor(255));
				//imgDest.setColor(i_p_2, j_p_2, ofColor(255));

				//imgDest.setColor(i_p_1, j_m_2, ofColor(255));
				//imgDest.setColor(i_p_1, j_m_1, ofColor(0));
				//imgDest.setColor(i_p_1, j, ofColor(0));
				//imgDest.setColor(i_p_1, j_p_1, ofColor(0));
				//imgDest.setColor(i_p_1, j_p_2, ofColor(255));
				
				//imgDest.setColor(i, j_m_2, ofColor(255));
				//imgDest.setColor(i, j_m_1, ofColor(0));
				//imgDest.setColor(i, j_p_1, ofColor(0));
				//imgDest.setColor(i, j_p_2, ofColor(255));

				//imgDest.setColor(i_m_1, j_m_2, ofColor(255));
				//imgDest.setColor(i_m_1, j_m_1, ofColor(0));
				//imgDest.setColor(i_m_1, j, ofColor(0));
				//imgDest.setColor(i_m_1, j_p_1, ofColor(0));
				//imgDest.setColor(i_m_1, j_p_2, ofColor(255));

				//imgDest.setColor(i_m_2, j_m_2, ofColor(255));
				//imgDest.setColor(i_m_2, j_m_1, ofColor(255));
				//imgDest.setColor(i_m_2, j, ofColor(255));
				//imgDest.setColor(i_m_2, j_p_1, ofColor(255));
				//imgDest.setColor(i_m_2, j_p_2, ofColor(255));

			}
			else {

				//Specific conditions to modify erosion behavior

				//imgDest.setColor(i_p_2, j_m_2, ofColor(0));
				//imgDest.setColor(i_p_2, j_m_1, ofColor(0));
				//imgDest.setColor(i_p_2, j, ofColor(0));
				//imgDest.setColor(i_p_2, j_p_1, ofColor(0));
				//imgDest.setColor(i_p_2, j_p_2, ofColor(0));

				//imgDest.setColor(i_p_1, j_m_2, ofColor(0));
				//imgDest.setColor(i_p_1, j_m_1, ofColor(255));
				//imgDest.setColor(i_p_1, j, ofColor(255));
				//imgDest.setColor(i_p_1, j_p_1, ofColor(255));
				//imgDest.setColor(i_p_1, j_p_2, ofColor(0));

				//imgDest.setColor(i, j_m_2, ofColor(0));
				//imgDest.setColor(i, j_m_1, ofColor(255));
				//imgDest.setColor(i, j_p_1, ofColor(255));
				//imgDest.setColor(i, j_p_2, ofColor(0));

				//imgDest.setColor(i_m_1, j_m_2, ofColor(0));
				//imgDest.setColor(i_m_1, j_m_1, ofColor(255));
				//imgDest.setColor(i_m_1, j, ofColor(255));
				//imgDest.setColor(i_m_1, j_p_1, ofColor(255));
				//imgDest.setColor(i_m_1, j_p_2, ofColor(0));

				//imgDest.setColor(i_m_2, j_m_2, ofColor(0));
				//imgDest.setColor(i_m_2, j_m_1, ofColor(0));
				//imgDest.setColor(i_m_2, j, ofColor(0));
				//imgDest.setColor(i_m_2, j_p_1, ofColor(0));
				//imgDest.setColor(i_m_2, j_p_2, ofColor(0));

				//default:
				imgDest.setColor(i, j, ofColor(255));

			}


		}
	}
	imgDest.update();
}
//--------------------------------------------------------------
void ofApp::setup() {
	imageRaw.load("pixillation_square.jpg");
	imageRaw.setImageType(OF_IMAGE_GRAYSCALE);
	imagePass1.allocate(imageRaw.getWidth(),imageRaw.getHeight(), OF_IMAGE_GRAYSCALE);
	imagePass2.allocate(imageRaw.getWidth(),imageRaw.getHeight(), OF_IMAGE_GRAYSCALE);
	imagePass1.update();
	dilate(imagePass1, imagePass2);
}


//--------------------------------------------------------------
void ofApp::update(){
	// invoke dilate function back & forth on image 1 & 2
	dilate(imagePass1, imagePass2);
	dilate(imagePass2, imagePass1);
	// use ofxCv absdiff to create a third image, the difference between 1 & 2
	absdiff(imagePass1, imagePass2, imagePass3);
	imagePass3.update();
	// use this difference to subtract from the original raw image to make the display image
	absdiff(imagePass3, imageRaw, imageDisplay);
	imageDisplay.update();
	// update the raw image before invoking the next dilate call
	absdiff(imageDisplay, imagePass1, imageRaw);
	imageRaw.update();



}

//--------------------------------------------------------------
void ofApp::draw() {
	ofScale(1, 1);

	//debugging:
	//imagePass1.draw(0, 0);
	//imagePass2.draw(imageRaw.getWidth(), 0);
	//imagePass3.draw(0, imageRaw.getHeight());
	//imageDisplay.draw(imageRaw.getWidth(), imageRaw.getHeight());


	//Final Display:
	imageDisplay.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//Reset Image
	for (int i = 0; i < imageRaw.getWidth(); i++) {
		for (int j = 0; j < imageRaw.getHeight(); j++) {
			ofColor c = imageRaw.getColor(i, j);
			if (c.getBrightness() > 127) {
				imagePass1.setColor(i, j, ofColor(255));
			}
			else {
				imagePass1.setColor(i, j, ofColor(0));
			}
		}
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
