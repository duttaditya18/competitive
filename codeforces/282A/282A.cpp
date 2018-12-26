#include <iostream>
#include <cstring>

using namespace std;
int main()
{
  int n;
  cin >> n;

  string b[n];
  int c = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> b[i];
    if (b[i].find("+") < b[i].length())
    {
      c++;
    }
    else
    {
      c--;
    }
  }

  cout << c;

  return 0;
}
