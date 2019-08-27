#include <iostream>

using namespace std;

int main(void)
{
    string s;
    int temp, maxi = 0;
    int c = 0;
    cin >> s;

    if(s == "0")
    {
        cout << 0 << endl;
        return 0;
    }

    while(stoi(s) != 0)
    {
        temp = stoi(s);
        maxi = 0;
        for(int i = 0, l = s.size(); i < l; i++)
        {
            if(temp % 10 > maxi)
            {
                maxi = (temp % 10);
            }
            temp /= 10;
        }

        s = to_string(stoi(s) - maxi);
        c++;
    }

    cout << c << endl;

    return 0;
}
