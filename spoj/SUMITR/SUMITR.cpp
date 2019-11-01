#include <iostream>

using namespace std;

main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n][n];

        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)
                cin >> a[i - 1][j];

        for(int i = n - 2; i >= 0; i--)
            for(int j = 0; j <= i; j++)
                a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);

        cout << a[0][0] << "\n";
    }
}
