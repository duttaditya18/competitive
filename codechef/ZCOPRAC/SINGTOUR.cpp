#include <iostream>
#include <cstdint>

using namespace std;

int main(void)
{
  cout << UINTPTR_MAX;

  // Test Cases
  uint64_t t;
  cin >> t;

  for (uintptr_t k = 0; k < t; k++)
  {
    uintptr_t n;
    cin >> n;

    uintptr_t a[n][2];
    uintptr_t p[n];

    for (uintptr_t i = 0; i < n; i++)
    {
      cin >> a[i][0] >> a[i][1];
      p[i] = 0;
    }

    for (uintptr_t i = 0; i < n; i++)
    {
      for (uintptr_t j = i + 1; j < n; j++)
      {
        if (((a[i][0] < a[j][0]) && (a[i][1] > a[j][1])) || ((a[i][0] <= a[j][0]) && (a[i][1] > a[j][1])) || ((a[i][0] < a[j][0]) && (a[i][1] >= a[j][1])))
        {
          p[i] += 2;
          // cout << i << "'th singer wins" << endl;
        }
        else if (((a[i][0] > a[j][0]) && (a[i][1] < a[j][1])) || ((a[i][0] >= a[j][0]) && (a[i][1] < a[j][1])) || ((a[i][0] > a[j][0]) && (a[i][1] <= a[j][1])))
        {
          p[j] += 2;
          // cout << j << "'th singer wins" << endl;
        }
        else
        {
          p[i]++;
          p[j]++;
          // cout << "draw b/w " << i << "'th and " << j << "'th" << endl;
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      cout << p[i] << " ";
    }
    cout << endl;
  }
}