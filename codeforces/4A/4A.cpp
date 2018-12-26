#include <iostream>

using namespace std;

int main(void)
{
  int i;
  cin >> i;

  if ((i % 2) == 0 && i > 2)
  {
    cout << "YES";
  }
  else
  {
    cout << "NO";
  }

  return 0;
}