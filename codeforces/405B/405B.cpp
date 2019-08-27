#include <iostream>

using namespace std;

int main(void)
{
	int n;
	string s;
	cin >> n;
    cin >> s;

    int counter = 0;
    char pre = 'N';
    int ans = 0;

    for(int i = 0; i <= n; i++)
    {
        if(s[i] == '.')
        {
            counter++;
        }
        if(s[i] == 'L')
        {
            if(pre == 'R')
            {
                ans += (counter % 2);
            }
            pre = 'L';
            counter = 0;
        }
        if(s[i] == 'R')
        {
            if(pre == 'N')
            {
                ans += counter;
            }
            if(pre == 'L')
            {
                ans += (counter);
            }
            pre = 'R';
            counter = 0;
        }
        if(s[i] == '\0')
        {
            if(pre == 'N')
            {
                ans += n;
            }
            if(pre == 'L')
            {
                ans += counter;
            }
        }
    }
    cout << ans;

}
