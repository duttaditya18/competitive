#include <cstdio>

using namespace std;

int main()
{
  int k, n, m, x, y;
  scanf("%d", &k);
  while (k)
  {
    scanf("%d %d", &n, &m);
    while (k--)
    {
      scanf("%d %d", &x, &y);
      if (x == n || y == m)
        printf("divisa\n");
      else
      {
        printf((y > m) ? "N" : "S");
        printf((x > n) ? "E\n" : "O\n");
      }
    }
    scanf("%d", &k);
  }
  return 0;
}