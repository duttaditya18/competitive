#include <bits/stdc++.h>

using namespace std;

int minPushBox(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    // T = Target, B = Box, S = Player
    int Ti, Tj, Bi, Bj, Si, Sj;

    int gr[n + 1][m + 1] = {};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == '.') gr[i + 1][j + 1] = 1;
            else if(grid[i][j] == '#') gr[i + 1][j + 1] = 0;
            else if(grid[i][j] == 'T')
            {
                gr[i + 1][j + 1] = 1;
                Ti = i + 1;
                Tj = j + 1;
            }
            else if(grid[i][j] == 'B')
            {
                gr[i + 1][j + 1] = 1;
                Bi = i + 1;
                Bj = j + 1;
            }
            else if(grid[i][j] == 'S')
            {
                gr[i + 1][j + 1] = 1;
                Si = i + 1;
                Sj = j + 1;
            }
        }
    }

    // cout << Ti << ' ' << Tj << endl;

    // for(int i = 1; i <= n; i++) { for(int j = 1; j <= m; j++) cout << gr[i][j] << ' "; cout << endl;

    int Di[] = {1, -1, 0, 0};
    int Dj[] = {0, 0, 1, -1};

    // Bi, Bj, Si, Sj, Moves
    queue<tuple<int, int, int, int, int>> q;
    q.push(make_tuple(Bi, Bj, Si, Sj, 0));

    int visited[n + 1][m + 1][n + 1][m + 1] = {};
    visited[Bi][Bj][Si][Sj] = 1;

    int ans = INT_MAX;

    while(!q.empty())
    {
        int CurBi = get<0>(q.front());
        int CurBj = get<1>(q.front());
        int CurSi = get<2>(q.front());
        int CurSj = get<3>(q.front());
        int CurDs = get<4>(q.front());
        if(CurBi == 3 && CurBj == 2)
        {
            cout << CurBi << ' ' << CurBj << ' ' << CurSi << ' ' << CurSj << ' ' << CurDs << endl;
        }

        q.pop();

        if(CurBi == Ti && CurBj == Tj)
        {
            //cout << CurBi << ' ' << CurBj << ' ' << CurSi << ' ' << CurSj << ' ' << CurDs << endl;
            ans = min(ans, CurDs);
            continue;
        }

        for(int i = 0; i < 4; i++)
        {
            int NewSi = CurSi + Di[i];
            int NewSj = CurSj + Dj[i];
            if(NewSi == CurBi && NewSj == CurBj)
            {
                int NewBi = CurBi + Di[i];
                int NewBj = CurBj + Dj[i];
                if(NewBi <= n && NewBi >= 1 && NewBj <= m && NewBj >= 1 && !visited[NewBi][NewBj][NewSi][NewSj] && gr[NewBi][NewBj] && gr[NewSi][NewSj])
                {
                    q.push(make_tuple(CurBi + Di[i], CurBj + Dj[i], NewSi, NewSj, CurDs + 1));
                    visited[NewBi][NewBj][NewSi][NewSj] = 1;
                }
            }
            else if(NewSi <= n && NewSi >= 1 && NewSj <= m && NewSj >= 1 && !visited[CurBi][CurBj][NewSi][NewSj] && gr[NewSi][NewSj])
            {
                q.push(make_tuple(CurBi, CurBj, NewSi, NewSj, CurDs));
                visited[CurBi][CurBj][NewSi][NewSj] = 1;
            }
        }
    }

    return (ans == INT_MAX ? -1 : ans);
}

int main(void)
{
    vector<vector<char>> gr =
    {
    {'#','#','#','#','#','#'},
    {'#','T','#','#','#','#'},
    {'#','.','.','B','.','#'},
    {'#','.','#','#','.','#'},
    {'#','.','.','.','S','#'},
    {'#','#','#','#','#','#'}
    };

    vector<vector<char>> gr1 =
    {
    {'.','.','.','.'},
    {'#','B','#','.'},
    {'.','.','T','.'},
    {'.','.','.','.'},
    {'#','.','.','#'},
    {'.','#','.','.'},
    {'S','.','.','.'},
    };
    cout << minPushBox(gr1);
}
