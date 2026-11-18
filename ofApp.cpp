#include "ofApp.h"

// SETUP
void ofApp::setup() {

	ofSetWindowShape(1000, 800);
	ofSetFrameRate(60);

	// Bright color palette
	colors.push_back(ofColor(255, 0, 100));
	colors.push_back(ofColor(255, 220, 0));
	colors.push_back(ofColor(0, 255, 200));
	colors.push_back(ofColor(150, 0, 255));
	colors.push_back(ofColor(0, 180, 255));

	// Generate the grid
	for (int x = 20; x < ofGetWidth(); x += 30) {
		for (int y = 20; y < ofGetHeight(); y += 30) {

			positions.push_back(ofVec2f(x, y));
			sizes.push_back(ofRandom(10, 25));

		}
	}
}


// UPDATE
void ofApp::update() {

	// Advance the wave
	wave += 0.07;

	// Move the noise walker smoothly
	noiseTime += 0.005;

	walkerX = ofNoise(noiseTime) * ofGetWidth();
	walkerY = ofNoise(noiseTime + 100) * ofGetHeight();

}


// DRAW
void ofApp::draw() {

	// Transparent black background creates trails
	ofSetColor(0, 55);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	// Draw the original grid
	for (int i = 0; i < positions.size(); i++) {

		float x = positions[i].x;

		float y = positions[i].y
			+ sin(x * 0.03 + wave) * waveHeight;

		// Alternate colors
		if (i % 2 == 0) {
			ofSetColor(colors[i % colors.size()]);
		} else {
			ofSetColor(colors[(i + 2) % colors.size()]);
		}

		// Pulsing shape size
		float size = sizes[i] + sin(wave + i) * 5;

		// Alternate between circles and squares
		if (i % 3 == 0) {
			ofDrawCircle(x, y, size / 2);
		} else {
			ofDrawRectangle(x - size / 2, y - size / 2,
							size, size);
		}
	}

	// DRAW THE NOISE WALKER
	ofSetColor(255);
	ofDrawCircle(walkerX, walkerY, 12);

	// Add a small center point
	ofSetColor(0);
	ofDrawCircle(walkerX, walkerY, 4);
}


// KEYBOARD INTERACTION
void ofApp::keyPressed(int key) {

	if (key == OF_KEY_DOWN) {

		wave += 3;
		waveHeight += 3;

		// Reset wave height
		if (waveHeight > 60) {
			waveHeight = 15;
		}
	}
}
