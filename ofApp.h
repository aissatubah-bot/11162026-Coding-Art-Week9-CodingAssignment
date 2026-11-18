#pragma once

#include "ofMain.h"
#include "mover.hpp"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	// Store shape positions and sizes
	vector<ofVec2f> positions;
	vector<float> sizes;

	// Color palette
	vector<ofColor> colors;

	// Wave variables
	float wave = 5;
	float waveHeight = 40;

	// Noise walker variables
	float noiseTime = 0;
	float walkerX = 0;
	float walkerY = 0;
};
