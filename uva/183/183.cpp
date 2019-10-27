#include <bits/stdc++.h>

using namespace std;

int prf[202][202] = {};

int x = 0;

void convertToD(int, int, int, int);
void convertToB(int, int, int, int);

int main(void)
{
    char type;
    while(1)
    {
        x = 0;
        cin >> type;
        if(type == '#') break;

        if(type == 'B')
        {
            int r, c;
            cin >> r >> c;
            char inp;
            int x;

            for(int i = 0; i < 202; i++) { prf[i][0] = 0; prf[0][i] = 0; }

            for(int i = 1; i <= r; i++)
            {
                for(int j = 1; j <= c; j++)
                {
                    cin >> inp;
                    x = (inp == '1');
                    prf[i][j] = x + prf[i - 1][j] + prf[i][j - 1] - prf[i - 1][j - 1];
                }
            }

            cout << "D";
            cout << setw(4);
            cout << r;
            cout << setw(4);
            cout << c << endl;

            convertToD(1, 1, r, c);
            cout << endl;

            //for(int i = 0; i <= r; i++) { for(int j = 0; j <= c; j++) cout << prf[i][j] << " "; cout << endl; }
        }
        else if(type == 'D')
        {
            int r, c;
            cin >> r >> c;

            convertToB(1, 1, r, c);

            cout << "B";
            cout << setw(4);
            cout << r;
            cout << setw(4);
            cout << c << endl;

            for(int i = 1; i <= r; i++)
            {
                for(int j = 1; j <= c; j++)
                {
                    if(x == 50)
                    {
                        cout << endl;
                        x = 0;
                    }
                    cout << prf[i][j];
                    x++;
                }
            }
            cout << endl;
        }
    }
}

void convertToB(int r0, int c0, int r, int c)
{
    char f;
    cin >> f;

    if(f == '0' || f == '1')
    {
        for(int i = r0; i <= r; i++)
        {
            for(int j = c0; j <= c; j++)
            {
                prf[i][j] = (f == '1');
            }
        }
        return;
    }

    int rx = ((r - r0 + 1) / 2) + ((r - r0 + 1) % 2) - 1;
    int cx = ((c - c0 + 1) / 2) + ((c - c0 + 1) % 2) - 1;
    //cout << rx << " " << cx << endl;

    convertToB(r0, c0, r0 + rx, c0 + cx);
    if(c0 != c) convertToB(r0, c0 + cx + 1, r0 + rx, c);
    if(r0 != r) convertToB(r0 + rx + 1, c0, r, c0 + cx);
    if(c0 != c && r0 != r) convertToB(r0 + rx + 1, c0 + cx + 1, r, c);


}
void convertToD(int r0, int c0, int r, int c)
{
    if(x == 50)
    {
        cout << endl;
        x = 0;
    }
    //cout << r0 << " " << c0 << " " << r << " " << c << endl;
    int sm = prf[r][c] - prf[r0 - 1][c] - prf[r][c0 - 1] + prf[r0 - 1][c0 - 1];
    //cout << sm << endl;

    if(sm == (r - r0 + 1) * (c - c0 + 1))
    {
        cout << 1;
        x++;
        return;
    }

    if(sm == 0)
    {
        cout << 0;
        x++;
        return;
    }
    cout << "D";
    x++;

    int rx = ((r - r0 + 1) / 2) + ((r - r0 + 1) % 2) - 1;
    int cx = ((c - c0 + 1) / 2) + ((c - c0 + 1) % 2) - 1;
    //cout << rx << " " << cx << endl;

    convertToD(r0, c0, r0 + rx, c0 + cx);
    if(c0 != c) convertToD(r0, c0 + cx + 1, r0 + rx, c);
    if(r0 != r) convertToD(r0 + rx + 1, c0, r, c0 + cx);
    if(c0 != c && r0 != r) convertToD(r0 + rx + 1, c0 + cx + 1, r, c);
}
