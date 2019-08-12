#include <iostream>
#include <cmath>

using namespace std;

int gcd(int x, int y)
{
	if (y==0)
	{
		return x;
	}
	return gcd(y, x%y);
}
int countPoints (int p1, int q1, int p2, int q2) {
	// p is x and q is z
	// slope = rise / run
	if (p2 < p1)
	{
		int temp = p2;
		p2 = p1;
		p1 = temp;
	}
	if (q2 < q1)
	{
		int temp = q2;
		q2=q1;
		q1 = temp;
	}

	int count=gcd (p2-p1, q2-q1) - 1;
	
	/*
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
	    if (floor(y) == y) {
	    	//count++;
	        cout << "(" << x << ", " << y << ")\n";
	    }
	}
	*/
	return count;
}

int main (void) {
	
	int t;
	cin >> t;
	
	while(t--){
		
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << x1 << y1 << x2 << y2 << x3 << y3;
	
	int a = countPoints(x1, y1, x2, y2);
	int b = countPoints(x2, y2, x3, y3);
	int c = countPoints(x3, y3, x1, y1);
	
	
	cout<<a<<" "<<b<<" "<<c<<endl;
	}
	//cout << countPoints(1, 6, 4, 4) <<endl;
}
