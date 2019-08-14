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
        int arr[n], max = -INFINITY, curr = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            curr += arr[i];
            if(curr > max)
            {
                max = curr;
            }
            if(curr < 1)
            {
                curr = 0;
            }
        }
        cout << max << endl;

    }
    return 0;
}
