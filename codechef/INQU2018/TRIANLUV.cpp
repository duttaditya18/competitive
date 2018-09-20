#include <iostream>
#include <cmath>

using namespace std;

int countPoints (int p1, int q1, int p2, int q2) {
	// p is x and q is z
	// slope = rise / run
	
	int count;
	int rise  = q1 - q2;
	int run = p1 - p2;
	float m = ((float) rise) / ((float) run);
	
	// y = mx + c => c = y - mx
	float c = q1 - (m * p1);
	
	for (int x = p1; x <= q2; x++)
	{
		cout << x << "\n";
	    // solve for y
	    float y = (m * x) + c;
		cout << y << "\n";
		
		// check if y is an int
	    if ((int) y == y) {
	    	count++;
	        cout << "(" << x << ", " << y << ")\n";
	    }
	}
	
	return count;
}

int main (void) {
	/*
	int t;
	cin >> t;
	
	for (int c = 0; c < t; c++) {
		
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << x1 << y1 << x2 << y2 << x3 << y3;
	
	int a = countPoints(x1, y1, x2, y2);
	int b = countPoints(x2, y2, x3, y3);
	int c = countPoints(x3, y3, x1, y1);
	
	}
	*/
	cout << countPoints(1, 6, 4, 4);
}
