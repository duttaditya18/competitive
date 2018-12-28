#include <iostream>

using namespace std;
int main()
{
  // Test Cases
  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    int x;
    cin >> x;

    int c = (x / 7);
    if (x % 7)
    {
      c++;
    }

    cout << c << endl;
  }
}
