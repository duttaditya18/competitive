#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  int TC, a, c, d, e;
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d", &a);
    c = 0, d = 1, e = 0;
    while (true)
    {
      if (a == c)
      {
        printf("Yes\n");
        break;
      }
      else if (c > a)
      {
        printf("No\n");
        break;
      }
      c = d + e;
      d = e;
      e = c;
    }
  }
}