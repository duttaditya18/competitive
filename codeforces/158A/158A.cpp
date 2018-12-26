#include <iostream>
#include <string>

using namespace std;
int main()
{
  int n, k;
  cin >> n >> k;

  int ar[n];
  for (int i = 0; i < n; i++)
  {
    cin >> ar[i];
  }
  int c = 0;
  int barely = ar[k - 1];
  while (c < n && ar[c] >= barely && ar[c] > 0)
  {
    c++;
  }
  cout << c;
  return 0;
}
