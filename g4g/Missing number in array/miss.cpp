#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int temp, sum = (n*(n+1))/2;
        for(int i = 0; i < n - 1; i++)
        {
            cin >> temp;
            sum -= temp;
        }
        cout << sum << endl;
    }
    return 0;
}
