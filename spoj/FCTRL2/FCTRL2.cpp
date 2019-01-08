// To think

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
  int a = 99;
  int b = 98;
  int temp[2];
  int x = 0;
  for (int i = 0; i < 2; i++)
  {
    temp[2 - i - 1] = (((a % 10) * (b % 10)) + x) % 10;
    a /= 10;
    x = (a % 10 * b % 10 + x) / 10;
  }
  cout << endl;
  for (int i = 0; i < 2; i++)
  {
    cout << temp[i];
  }
  return 0;
}
