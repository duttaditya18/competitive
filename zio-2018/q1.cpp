#include <iostream>

using namespace std;
int search(int [],int,int);

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)

		// Last i elements are already in place   
		for (j = 0; j < n-i-1; j++) 
			if (arr[j] > arr[j+1])
 				swap(&arr[j], &arr[j+1]);
}

int main (void)
{
	
	int n;
	cin >> n;
	int a[n];
	int arrLen = 0;

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int k;
	cin >> k;
	int ans[5];

	bubbleSort(a, n);
	cout<<endl<<endl;
	
	int rem[5];
	
	for (int i = n; i > 0; i--)
	{
		int r = a[i] % 5;
		int temp = search(rem,r+1,arrLen);
		cout << temp;
		if (temp == 0)
		{	
			ans[arrLen] = a[i];
			rem[arrLen] = r;
			arrLen++;
		}
		cout << endl;
	}

	cout << "rem : ";

	for (int i = 0; i < arrLen; i++)
	{
		cout<<rem[i]<<" ";
	}

	for (int i = 0; i < arrLen; i++)
	{
		// cout<<ans[i] << " ";
	}
}

int search(int arr[], int x, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == x)
		{
			return 1;
			break;
		}
	}
	return 0;
}
