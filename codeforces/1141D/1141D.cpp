// TLE

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  int n;
  vector<pair<int, int>> vect;
  cin >> n;

  string l, r;
  cin >> l >> r;

  bool lCount[n] = {0}, rCount[n] = {0};

  // l-defined to r-defined
  for (int i = 0; i < n; i++)
  {
    if (l[i] != '?')
    {
      for (int j = 0; j < n; j++)
      {
        if (rCount[j] == 0)
        {
          if (l[i] == r[j])
          {
            lCount[i] = 1;
            rCount[j] = 1;
            vect.push_back(make_pair(i, j));
            break;
          }
        }
      }
    }
  }

  // l-undefined to r-defined
  for (int i = 0; i < n; i++)
  {
    if (l[i] == '?')
    {
      for (int j = 0; j < n; j++)
      {
        if (rCount[j] == 0)
        {
          if (r[j] != '?')
          {
            lCount[i] = 1;
            rCount[j] = 1;
            vect.push_back(make_pair(i, j));
            break;
          }
        }
      }
    }
  }

  // r-undefined to l-defined
  for (int i = 0; i < n; i++)
  {
    if (r[i] == '?')
    {
      for (int j = 0; j < n; j++)
      {
        if (lCount[j] == 0)
        {
          if (l[j] != '?')
          {
            rCount[i] = 1;
            lCount[j] = 1;
            vect.push_back(make_pair(j, i));
            break;
          }
        }
      }
    }
  }

  // l-undefined to r-undefined
  for (int i = 0; i < n; i++)
  {
    if (l[i] == '?' && lCount[i] == 0)
    {
      for (int j = 0; j < n; j++)
      {
        if (rCount[j] == 0)
        {
          if (r[j] == '?')
          {
            lCount[i] = 1;
            rCount[j] = 1;
            vect.push_back(make_pair(i, j));
            break;
          }
        }
      }
    }
  }
  cout << vect.size() << endl;
  for (int i = 0; i < vect.size(); i++)
  {
    cout << vect[i].first + 1 << " "
         << vect[i].second + 1 << endl;
  }
}