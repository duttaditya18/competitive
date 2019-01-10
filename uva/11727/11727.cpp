#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int t, a[3], i = 1;
  scanf("%d", &t);

  while (t--)
  {
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    sort(a, a + 3);
    printf("Case %d: %d\n", i++, a[1]);
  }
  return 0;
}