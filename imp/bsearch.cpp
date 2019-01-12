#include <iostream>

using namespace std;

int bsearch(int k, int a[], int l, int r)
{
  cout << "starting for " << l << " to " << r << endl;
  if (l == r)
    return -1;

  int mid = (l + r) / 2;

  if (k == a[mid])
    return mid;
  if (k < a[mid])
    bsearch(k, a, l, mid);
  else
    bsearch(k, a, mid, r);
}

int main(void)
{
  int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  cout << bsearch(7, a, 0, 8);
  return 0;
}