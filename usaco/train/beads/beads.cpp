/*
ID: duttadi1
TASK: beads
LANG: C++                 
*/

// Brute Force : O(n^2)

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(void)
{
  ifstream cin("beads.in");
  ofstream cout("beads.out");

  int n, currMax, maxAns = 0;
  cin >> n;

  bool switched = false;
  char curr, currClr = 'w';

  string s;
  cin >> s;

  for (int i = 0; i < n; i++)
  {
    currMax = 0;
    switched = false;
    currClr = 'w';
    for (int j = 0; j < n; j++)
    {
      curr = s[(i + j) % n];
      if (curr != 'w')
      {
        if (currClr == 'w')
        {
          currClr = curr;
        }
        else if (currClr != curr)
        {
          if (switched)
          {
            break;
          }
          else
          {
            currClr = curr;
            switched = true;
          }
        }
      }
      currMax++;
    }
    maxAns = max(currMax, maxAns);
  }
  cout << maxAns << endl;
  return 0;
}