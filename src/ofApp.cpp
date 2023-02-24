#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetColor(255);
	myButton.set(100,100,50,50);
	//Image stuff:
	/*myImage.load("100.jpg");
	myImage.resize(800, 272);
	myPixels = myImage.getPixels();*/
	//Other stuff:
	ofBackground(0);
	string file_name = "vec_text8.bin";
	embed.load_binary(file_name);
	string f = "";
	string s = "";
	/*string s = "dog+ tree";
	vector<int> used_indices;
	ofxWord2VecVector Vec = embed.words_to_vec(s, &used_indices);*/
}

//--------------------------------------------------------------
void ofApp::update(){
	/*string s = "dog + tree";
	vector<int> used_indices;
	ofxWord2VecVector Vec = embed.words_to_vec(s, &used_indices);*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofDrawRectangle(myButton);
	//activate = false;
	//ofPushMatrix();
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, -100);
	string f = "man + dog + snow + plow + hello + my + name + is + eagle";
	ofDrawBitmapString(f, 300, 400);
	//if (activate) {
	s=f;

		vector<int> used_indices;
		ofxWord2VecVector Vec = embed.words_to_vec(s, &used_indices);
		//string vectorString = ofToString(Vec);
		//string vectorString=ofToString(Vec.print_console("a", "a", 2));
		/*for (int i = 0; i < 500; i++)
		{
			ofToString(Vec[i]) = myStrings[i];
		}
		 string vectorString=ofToString(Vec.print_console("a", "a", 2));*/
		 //ofDrawBitmapString(vectorString,100,100);
		 // ofDrawCircle(50, 50, 50);
		  //path.arc();
		vector <ofPoint> points;
		//poly.translate(ofPoint(1000, 1000, 0));
		for (int i = 0; i < 200; i++) {
			/*for (int j = 0; j < 200; j++) {
				for (int k = 0; k < 200; k++)
				{
					ofSetColor(255 - i, 150 + ((j + 2)), 100 + k, 90);
					path.lineTo(Vec.v[i], Vec.v[j], Vec.v[k]);
				}

			}*/
			//ofSetColor(255 - i, 150 + ((i + 2)), 100 + i, 50);'

			// points.push_back((ofPoint((Vec.v[i] * i), (Vec.v[i + 1] * i), (Vec.v[i + 2] * i))));
				//path.lineTo(Vec.v[i], Vec.v[i+1], Vec.v[i+2]);
			/* for (int x = 0; x < myImage.getWidth(); x++) {
				 for (int y = 0; y < myImage.getHeight(); y++) {
					 ofSetColor(myPixels.getColor(x, y));
					 ofDrawTriangle((Vec.v[i] * i), (Vec.v[i] * i) + 30, (Vec.v[i + 1] * i), (Vec.v[i + 1] * i) + 30, (Vec.v[i + 2] * i), (Vec.v[i + 2] * i) + 30);
				 }
			 }*/
			ofPushMatrix();
			ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5, (-i) * 2);
			//Some CRAZY STUFF:
			 //ofSetColor(int(ofRandom(0, 255) + Vec.v[i]), int(ofRandom(0, 255) + Vec.v[i + 1]), int(ofRandom(0, 255) + Vec.v[i]));
			ofSetColor(i, i, i, 20);
			poly.addVertex(ofPoint((Vec.v[i] * i), (Vec.v[i + 1] * i), (Vec.v[i + 2] * i)));
			poly.close();
			poly.draw();
			ofPopMatrix();
			// points.push_back(ofPoint((Vec.v[i]*i), (Vec.v[i+1]*i), (Vec.v[i + 2]*i)));
	//path.lineTo(Vec.v[i]*i, Vec.v[i + 1]*i, Vec.v[i + 2]*i);
				 //ofDrawLine(Vec.v[i] * 10, Vec.v[j] * 10, Vec.v[i] * 10, Vec.v[j] * 10);


			cout << "Vector" << Vec.v[i] << endl;
		}

		// path.close();
		// path.draw();
		//poly.close();
		//poly.getVertices();
		/*for (int x = 0; x < myImage.getWidth(); x++) {
			for (int y = 0; y < myImage.getHeight(); y++) {

				ofSetColor(myPixels.getColor(x, y));
				poly.draw();
			}
		}*/
		//poly.draw();

		// ofSetFrameRate(5);


		// poly.draw();
		 //line.close();
		cout << "End" << endl;

	//}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '\n') { //press enter to calculate vector

		activate == true;

	}

	if (key == '8' && s.size() > 0) { // backspace
		f = f.substr(0, f.size() - 1); // delete one character
	}
	else { //send characters to screen
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
	if(myButton.inside(x,y))activate==true;
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
