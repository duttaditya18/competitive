// inserting into a string
#include <iostream>
#include <string>

using namespace std;

int main()
{
  string str;
  cin >> str;

  string newStr;
  int c = 0;
  for (int i = 0; i < str.size(); i++)
  {
    cout << i << " : " << str[i] << " : " << newStr << endl;
    if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' || str[i] == 'Y'))
    {
      newStr.insert((c), ".");
      newStr.push_back(str[i]);
      c += 2;
    }
  }
  cout << newStr;
}