#include <iostream>
#include <cstdio>

using namespace std;

int selectionSort(int a[], int n)
{
  int minI, i, j;
  for (i = 0; i < n; i++)
  {
    minI = i;
    for (j = i; j < n; j++)
      if (a[j] < a[minI])
        minI = j;
    swap(a[i], a[minI]);
  }
}
                            
int main(void)
{
  int a[8] = {9, 5, 4, 6, 1, 10, 7, 4};
  selectionSort(a, sizeof(a) / sizeof(a[0]));
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    printf("%d ", a[i]);
  return 0;
}