#include <bits/stdc++.h>

using namespace std;

#define N 1000010
int n, a[N];
int le[N], ri[N];

int main()
{
	cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
	a[0] = -1e9 - 7;
	a[n+1] = 1e9+7;
	le[0] = 0;
	for (int i = 1; i <= n; i ++)
    {
		if (a[i] > a[i-1]) le[i] = le[i-1]+1;
		else le[i] = 1;
	}
	ri[n+1] = 0;
	for (int i = n; i >= 1; i --) {
		if (a[i] < a[i+1]) ri[i] = ri[i+1]+1;
		else ri[i] = 1;
	}

	for(int i = 0; i <= n + 1; i++) cout << a[i] << " ";
	cout << endl;

	for(int i = 0; i <= n + 1; i++) cout << le[i] << " ";
	cout << endl;

	for(int i = 0; i <= n + 1; i++) cout << ri[i] << " ";
	cout << endl;

	int S = 0;
	for (int i = 1; i <= n; i ++) {
		S = max(S, le[i]);
		S = max(S, ri[i]);
		S = max(S, le[i-1]+1);
		S = max(S, ri[i+1]+1);
		if (a[i-1]+1 <= a[i+1]-1)
        {
            S = max(S, le[i-1]+1+ri[i+1]);
            cout << i << " " << S << endl;
        }
	}
	cout << S << endl;
	return 0;
}
