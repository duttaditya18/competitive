#include<bits/stdc++.h>
using namespace std;

// n, m
long long dp[101][101];

class AvoidRoads
{
    public:
    long long numWays(int n, int m, vector<string> bad)
    {
        vector<pair<int, int>> bd[n + 1][m + 1];

        int ix, iy, jx, jy;

        for(auto u : bad)
        {
            stringstream s(u);
            s >> ix >> iy >> jx >> jy;
            bd[ix][iy].push_back(make_pair(jx, jy));
            bd[jx][jy].push_back(make_pair(ix, iy));
        }


        dp[0][0] = 1ll;

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 && j == 0) continue;

                int nx = true;
                if(i != 0)
                {
                    for(auto u : bd[i][j]) if(u.first == i - 1 && u.second == j) nx = false;
                    if(nx) dp[i][j] += dp[i - 1][j];
                }
                int ny = true;
                if(j != 0)
                {
                    for(auto u : bd[i][j]) if(u.first == i && u.second == j - 1) ny = false;
                    if(ny) dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[n][m];
	}
};

int main(void)
{
    AvoidRoads x;
    cout << x.numWays(24, 24, {"20 13 21 13", "13 21 13 20", "0 20 0 21", "5 17 6 17", "6 23 5 23", "23 7 23 8", "11 24 12 24", "1 12 2 12", "6 20 6 19", "17 10 17 11", "8 2 8 3", "6 17 6 16", "17 20 17 21", "12 15 11 15", "21 0 22 0", "17 8 17 9", "21 1 21 0", "13 21 13 22", "22 12 22 13", "19 1 20 1", "13 4 14 4", "13 6 13 5", "6 4 7 4", "10 19 11 19", "11 7 12 7", "10 8 10 9", "4 20 4 19", "21 10 20 10", "3 15 3 16", "1 20 1 21", "7 13 7 14", "24 1 24 0", "7 15 8 15", "13 0 13 1", "21 23 22 23", "7 1 7 2", "21 5 21 4", "18 23 17 23", "2 17 2 18", "4 22 5 22", "11 4 12 4", "8 20 8 21", "1 5 1 4", "1 1 1 0", "4 19 5 19", "18 11 17 11", "23 18 23 17", "12 3 11 3", "1 16 1 17", "21 11 20 11"});
}
