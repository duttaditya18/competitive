#include <iostream>
#include <cstdio>

using namespace std;

void insertionSort(int a[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int c = i;
    while (c > 0 && a[c] < a[c - 1])
    {
      swap(a[c], a[c - 1]);
      c--;
    }
  }
}

int main(void)
{
  int a[8] = {9, 5, 4, 6, 1, 10, 7, 4};

  insertionSort(a, sizeof(a) / sizeof(a[0]));

  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    printf("%d ", a[i]);
  return 0;
}