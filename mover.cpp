//
//  mover.cpp
//  20261115_week9
//
//  Created by Aissatu Bah on 11/17/26.
//

#include "mover.hpp"

mover::mover(){
	
	r = floor(ofRandom(0,100));
	g = floor(ofRandom(200,255));
	b = floor(ofRandom(100,255));
	
	
	x = ofRandom(ofGetWidth());
	y = ofRandom(ofGetHeight());
	
	xDir = ofRandom(-1,1);
	yDir = ofRandom(-1,1);
	
	offSetX = ofRandom(-5,5);
	offSetY = ofRandom(-5,5);
	
}

//-------------------------------
void mover::display(int numShapes, float diam){
	
	for (int i = numShapes; i > 0; i--){
		
		ofFill();
		ofSetColor(r,g,b);
		ofDrawCircle(x+offSetX*i,y+offSetY*i,diam*i);
		
		ofNoFill();
		ofSetColor(ofColor::yellow);
		ofDrawCircle(x+offSetX*i,y+offSetY*i,diam*i);
		
	}
	
}

//-------------------------------
void mover::update(){
	
	x += xDir;
	y += yDir;
	
}
//-------------------------------
void mover::keepInCanvas(){
	
	if((x > ofGetWidth())||(x < 0)){
			
			xDir = -xDir;
		}
	if((y > ofGetHeight())||(y < 0)){
			
			yDir = -yDir;
		}
}
