#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s, ri, rj ,rk;
    cin >> s;
    int l = s.size();

    for(int i = 0; i < l; i++)
    {
        string ri = s.substr(i, 1);
        //cout << stoi(ri) << endl;
        if(stoi(ri) % 8 == 0)
       {
            cout << "YES" << endl << ri;
            return 0;
       }
        for(int j = i + 1; j < l; j++)
        {
            string rj = ri + s.substr(j, 1);
            //cout << stoi(rj) << endl;
            if(stoi(rj) % 8 == 0)
           {
                cout << "YES" << endl << rj;
                return 0;
           }
            for(int k = j + 1; k < l; k++)
            {
                string rk = rj + s.substr(k, 1);
                //cout << stoi(rk) << endl;
                if(stoi(rk) % 8 == 0)
               {
                    cout << "YES" << endl << rk;
                    return 0;
               }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
