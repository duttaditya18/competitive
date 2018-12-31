#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
  int n;
  cin >> n;

  int a[n];
  int l1 = 0, l2 = 0, s1 = INT32_MAX, s2 = INT32_MAX;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];

    // Largest and 2nd Largest
    if (a[i] > l1)
    {
      l2 = l1;
      l1 = a[i];
    }
    else if (a[i] > l2)
    {
      l2 = a[i];
    }

    // Smallest and 2nd Smallest
    if (a[i] < s1)
    {
      s2 = s1;
      s1 = a[i];
    }
    else if (a[i] < s2)
    {
      s2 = a[i];
    }
  }

  cout << min((l2 - s1), (l1 - s2));
  return 0;
}
