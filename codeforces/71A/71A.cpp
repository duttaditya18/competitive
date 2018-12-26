#include <iostream>
#include <string>

using namespace std;
int main()
{
  int n;
  cin >> n; // Test Cases

  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
    if (str.size() > 10)
    {
      cout << str[0] << str.size() - 2 << str.back();
    }
    else
    {
      cout << str;
    }
    cout << endl;
  }
  return 0;
}
