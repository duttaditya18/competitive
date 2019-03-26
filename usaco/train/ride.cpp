/*
ID: duttadi1
TASK: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string a, b;
  int counta = 1, countb = 1;
  fin >> a >> b;
  for (int i = 0; i < a.size(); i++)
  {
    counta *= (a[i] - 64);
  }
  for (int i = 0; i < b.size(); i++)
  {
    countb *= (b[i] - 64);
  }
  if ((counta % 47) == (countb % 47))
  {
    fout << "GO" << endl;
  }
  else
  {
    fout << "STAY" << endl;
  }
  return 0;
}