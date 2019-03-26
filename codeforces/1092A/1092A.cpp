#include <iostream>

using namespace std;
int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, k;
    cin >> n >> k;

    if (!(n % k))
      for (int i = 0; i < k; i++)
        for (int j = 0; j < n / k; j++)
          cout << (char)('a' + i);
    else
    {
      int x = n % k;
      for (int i = 0; i < k; i++)
      {
        if (x)
        {
          for (int j = 0; j < n / k + 1; j++)
            cout << (char)('a' + i);
          x--;
        }
        else
          for (int j = 0; j < n / k; j++)
            cout << (char)('a' + i);
      }
    }
    cout << endl;
  }
  return 0;
}
