// Wrong Answer?

#include <iostream>
 
using namespace std;

int checkprime(int num)
{
	for(int f = 2; f <= num / 2; f++)
	{
		if(num % f == 0)
		{
			return 0;
		}
		else
		{
			continue;
		}
		return 1;
	}
}

int genprime(int n1, int n2)
{
	for(int i = n1; i <= n2; i++)
	{
		int checkc = checkprime(i);
	    if(checkc == 0)
	    {
			continue;
		}
		else
		{
			cout << i << endl;
		}
	}
	cout << "\n";
}
 
 
int main(void)
{
	int test;
	cin >> test;
	for(int i = 0; i < test; i++)
	{
		int n1;
		cin >> n1;
		int n2;
		cin >> n2;
		genprime(n1, n2);
	}
	
	return 0;
}

