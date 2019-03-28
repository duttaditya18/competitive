/*
ID: duttadi1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>

using namespace std;

bool isLeap(int year)
{
  if (!(year % 100))
  {
    if (!(year % 400))
    {
      return true;
    }
  }
  else if (!(year % 4))
  {
    return true;
  }
  return false;
}

int main()
{
  ifstream cin("friday.in");
  ofstream cout("friday.out");

  int monthsOddDay[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
  int counter[7] = {};
  int n, i, j;

  // 13 Jan 1900 was Saturday
  int current = 6;
  bool leap = false;

  cin >> n;
  for (i = 1900; i < 1900 + n; i++)
  {
    if (isLeap(i))
    {
      monthsOddDay[1] = 1;
    }
    else
    {
      monthsOddDay[1] = 0;
    }
    for (j = 0; j < 12; j++)
    {
      counter[current]++;
      current = (current + monthsOddDay[j]) % 7;
    }
  }

  for (i = 6; i < 13; i++)
  {
    cout << counter[i % 7];
    if (i < 12)
      cout << " ";
    else
      cout << endl;
  }
  return 0;
}