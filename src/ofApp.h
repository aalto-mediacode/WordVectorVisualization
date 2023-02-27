#pragma once

#include "ofMain.h"
#include "ofxWord2Vec.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		ofxWord2VecEmbedding embed;
		ofxWord2VecVector Vec;
		ofPolyline poly;
		string f;
		string s;
		string n;
		bool calculate;
		bool visualize;
		ofRectangle myButton;
		ofTrueTypeFont myFont;
		int zoom;
		
		
};
