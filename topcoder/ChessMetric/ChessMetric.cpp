#include<bits/stdc++.h>
using namespace std;

// size, size, numMoves
long long dp[101][101][51];

class ChessMetric
{
    public:
    long long howMany(int s, vector <int> st, vector <int> en, int moves)
    {
        int posX[] = {1, -1, 1, -1, 1, 0, -1, 0, 1, 2, 1, -2, -1, 2, -1, -2};
        int posY[] = {1, -1, -1, 1, 0, 1, 0, -1, 2, 1, -2, 1, 2, -1, -2, -1};
        int posZ = sizeof(posX)/sizeof(posX[0]);

        dp[st[0]][st[1]][0] = 1;

        int newX = 0, newY = 0;

        for(int x = 1; x <= moves; x++)
        {
            for(int i = 0; i < s; i++)
            {
                for(int j = 0; j < s; j++)
                {
                    for(int k = 0; k < posZ; k++)
                    {
                        newX = i + posX[k];
                        newY = j + posY[k];
                        if(newX < s && newX >= 0 && newY < s && newY >= 0) dp[i][j][x] += dp[newX][newY][x - 1];
                    }
                }
            }
        }

        return dp[en[0]][en[1]][moves];

	}
};

int main(void)
{
    ChessMetric x;
    cout << x.howMany(100 ,{0,0}, {0, 99}, 50);
}
