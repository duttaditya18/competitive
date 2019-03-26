#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
  int TC, a, b;
  scanf("%d", &TC);
  while (TC--)
  {
    scanf("%d %d", &a, &b);
    if (a > b)
      printf(">\n");
    else if (a < b)
      printf("<\n");
    else if (a == b)
      printf("=\n");
  }
}