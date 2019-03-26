#include <iostream>

using namespace std;

bool prime(int n)
{
	if (n == 0 || n == 1)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m, n;
		cin >> m >> n;
		for (int i = m; i <= n; i++)
			if (prime(i))
				cout << i << endl;
	}

	return 0;
}
