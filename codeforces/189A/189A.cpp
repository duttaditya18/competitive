#include <iostream>

using namespace std;
int main()
{
  int n, a, b, c;
  cin >> n >> a >> b >> c;

  int px = 0;
  int py = 0;
  int pz = 0;
  for (int x = 0; x <= n; x++)
  {
    for (int y = 0; y <= n; y++)
    {
      int z = (n - (a * x) - (b * y)) / c;
      if ((((a * x) + (b * y) + (c * z)) == n) && ((x + y + z) > (px + py + pz)) && x >= 0 && y >= 0 && z >= 0)
      {
        px = x;
        py = y;
        pz = z;
      }
    }
  }

  cout << (px + py + pz);

  return 0;
}
