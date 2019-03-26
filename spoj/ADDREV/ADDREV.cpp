#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

int main(void)
{
  int n;
  cin >> n;
  while (n--)
  {
    string a, b;
    cin >> a >> b;
    int na = a.length();
    int nb = b.length();
    // Reverse Them
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string x = to_string(stoi(a) + stoi(b));
    reverse(x.begin(), x.end());
    int sum = stoi(x);
    cout << sum << endl;
  }
}
