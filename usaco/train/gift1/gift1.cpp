/*
ID: duttadi1
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
  ifstream cin("gift1.in");
  ofstream cout("gift1.out");

  int NP, amt, frs, share, i, j;
  cin >> NP;

  map<string, int> sums;
  string names[10];
  string name, frName;

  for (i = 0; i < NP; i++)
  {
    cin >> names[i];
    sums[names[i]] = 0;
  }

  for (i = 0; i < NP; i++)
  {
    cin >> name;
    cin >> amt >> frs;

    if (frs == 0)
    {
      continue;
    }
    else
    {
      share = amt / frs;
      sums[name] -= share * frs;
      for (int j = 0; j < frs; j++)
      {
        cin >> frName;
        sums[frName] += share;
      }
    }
  }

  for (i = 0; i < NP; i++)
  {
    cout << names[i] << " " << sums[names[i]] << endl;
  }

  return 0;
}