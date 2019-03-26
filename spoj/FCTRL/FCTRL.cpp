// See NoteBook for proof

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int c = 0;
    for (int i = 5; i <= n; i *= 5)
    {
      c += floor(n / i);
    }
    cout << c << endl;
  }
  return 0;
}
