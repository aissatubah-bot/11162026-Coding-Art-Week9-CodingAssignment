//
//  mover.hpp
//  20261115_week9
//
//  Created by Aissatu Bah on 11/17/26.
//

#ifndef mover_hpp
#define mover_hpp

#include "ofMain.h"
#include <stdio.h>

class mover {
	
	public:
		mover();
	
		int r;
		int g;
		int b;
	
		float x;
		float y;
	
		float xDir;
		float yDir;
	
		float offSetX;
		float offSetY;
	
		void setup();
		void display(int numShapes, float diam);
		void update();
		void keepInCanvas();
	
};


#endif /* mover_hpp */
