#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//UI Setup
	myFont.load("AGENCYB.ttf", 32);
	ofBackground(0);
	myButton.set(100, 70, 300, 70);
	

	//Load the embeddings file:
	string file_name = "vec_text8.bin";
	embed.load_binary(file_name);
	
	//Strings for text:
	string f = " ";
	string s = " ";
	
	//Set animation zooming speed:

	zoom = -2;
}

//--------------------------------------------------------------
void ofApp::update() {
	//Calculate the vector
	if (calculate) {
		s = f;
		vector<int> used_indices;
		Vec = embed.words_to_vec(s, &used_indices);
		if (!Vec.empty()) {

			auto match = embed.match_cos(Vec, 1, used_indices); //Get new vector that is closest to the calculated one
			n = ofToString(match[0].word);

		}
		visualize = true;
	}
}

	//--------------------------------------------------------------
	void ofApp::draw() {

		if (visualize) {

			//Go through the values in vector:
			for (int i = 0; i < 200; i++) {
				ofPushMatrix();
				
				//Animate:
				ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5, i* (zoom));
				
				//Colour the shape:
				ofSetColor(i, i, i, 20);
				//Alternative colour schemes:
				//ofSetColor(Vec.v[i]+i, Vec.v[i + 1]+i, Vec.v[i + 1]+i,10); //Vector based
				//ofSetColor(int(ofRandom(0, 255) + Vec.v[i]), int(ofRandom(0, 255) + Vec.v[i + 1]), int(ofRandom(0, 255) + Vec.v[i])); //Trippy

				//Draw the shape:
				poly.addVertex(ofPoint((Vec.v[i] * i), (Vec.v[i + 1] * i), (Vec.v[i + 2] * i)));
				poly.close();
				poly.draw();
				ofPopMatrix();

				//Display vector in console:
				cout << "Vector" << Vec.v[i] << endl;
			}
		}
		//Draw UI:
		ofNoFill();
		ofSetColor(255, 0, 0);
		ofDrawRectangle(myButton);
		myFont.drawString("Calculate vector", 120, 120);
		myFont.drawString(f, 300, 400);
		if (visualize) {
			myFont.drawString("= " + n, 300, 500);
		}

	}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	//Keyboard inputs:
	if (key == 8 && f.size() > 0) { // backspace
		f = f.substr(0, f.size() - 1); // delete one character
	}
	else { //send characters to that get vectorized
		f.append(1, (char)key);
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
	//Button
	if (myButton.inside(x, y)) {
		calculate = true;
	}
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
