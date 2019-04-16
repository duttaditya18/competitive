#include <iostream>

using namespace std;

void merge(int A[], int l, int m, int r)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = A[l + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = A[m + 1 + i];
  }

  // Current index in L[] , R[] and A[] respectively
  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2)
  {
    // Case 1: Move head of L[] into A[]
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i++;
    }
    // Case 2: Move head of R[] into A[]
    else if (L[i] > R[j])
    {
      A[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy remaining elements of L[]
  while (i < n1)
  {
    A[k] = L[i];
    i++;
    k++;
  }

  // Copy remaining elements of R[]
  while (j < n2)
  {
    A[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int A[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;

    mergeSort(A, l, m);
    mergeSort(A, m + 1, r);

    merge(A, l, m, r);
  }
}

// Printing an array
void print(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

int main()
{
  int A[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(A) / sizeof(A[0]);

  print(A, n);

  mergeSort(A, 0, n - 1);

  print(A, n);
  return 0;
}