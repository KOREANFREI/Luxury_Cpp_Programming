#include <iostream>
#include "box.h"
using namespace std;

Box::Box(int w, int h) { setSize(w, h); fill = '*'; }

void Box::setfill(char f) { fill = f; }

void Box::setSize(int w, int h) { width = w; height = h; }

void Box::draw() {
	for (int n = 0; n < height; n++) {
		for (int m = 0; m < width; m++) cout << fill;
		cout << endl;
	}
}