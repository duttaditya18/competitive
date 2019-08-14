// TLE @ Test Case 63 lol

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    long long t;
    int n;

    // isSquareRootPrime
    bool flag = true;
    cin >> n;

    while(n--)
    {
        flag = true;
        cin >> t;
        long long f = sqrtl(t);

        // CheckPrime
        for(int i = 2; i*i <= f; i++)
        {
            if(f % i == 0)
            {
                flag = false;
                break;
            }
        }

        if(f*f == t and flag and t > 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
