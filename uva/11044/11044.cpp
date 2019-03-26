#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  int TC, a, b, ans = 0;
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d %d", &a, &b);
    printf("%d\n", (int)(ceil((double)(a - 2) / 3)) * (int)(ceil((double)(b - 2) / 3)));
  }
}