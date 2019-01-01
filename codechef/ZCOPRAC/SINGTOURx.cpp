#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main()
{
  // test cases
  int t;
  cin >> t;

  for (int k = 0; k < t; k++)
  {
    // singers
    int n;
    cin >> n;

    // upper and lower limits
    vector<pair<long, long>> l;
    vector<pair<long, long>> u;

    // points
    long long p[n];

    for (long i = 0; i < n; i++)
    {
      long a, b;
      cin >> a >> b;

      l.push_back({a, i});
      u.push_back({b, i});
      p[i] = 0;
    }

    // sorting l descending
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());

    // sorting u ascending
    sort(u.begin(), u.end());

    // calc points
    for (long i = 0; i < n; i++)
    {
      /*cout << "l[" << i << "]: " << l[i].second << " ";
			cout << "u[" << i << "]: " << u[i].second << " ";*/
      p[l[i].second] += i;
      p[u[i].second] += i;
      /*for (int j = 0; j < n; j++)
			{
				cout << "p[" << j << "]: " << p[j] << " ";
			}*/
      cout << endl;
    }

    // final print
    for (long i = 0; i < n; i++)
    {
      cout << p[i] << " ";
    }

    cout << endl;
  }

  return 0;
}
