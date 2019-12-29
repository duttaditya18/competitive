#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	int n; cin >> n;
	int a[n + 1] = {}, b[n + 1] = {};
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]] = i;
	}

	int i = 1, j = 1;
	int xo[n + 1] = {};
	for(int x = 1; x <= n; x++)
	{
		if(xo[x]) continue;
		int c = x;
		while (!xo[c])
		{
			xo[c] = 1;
			if(a[c] != 0)
			{
				c = a[c];
				continue;
			}

			while(j <= n)
			{
				if (!b[j] and j != c and !xo[j])
				{
					b[j] = c;
					a[c] = j;
					c = j;
					break;
				}
				j++;
			}

		}
	}

	for (int i = 1; i <= n; i++)
	{
		if(a[i] != 0) cout << a[i] << " ";
		else
		{
			for (int k = 1; k <= n; k++)
				if (!b[k]) cout << k << " ";
		}
	}
	cout << endl;
}
