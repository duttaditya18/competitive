#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int q;
    cin >> q;

    while(q--)
    {
        long long n;
        cin >> n;

        long long cur = n;
        int x = 0;

        vector<int> tri;

        while(cur != 0)
        {
            tri.push_back(cur % 3);
            cur /= 3;
            x++;
        }
        tri.push_back(0);

        reverse(tri.begin(), tri.end());

        //for(int i = 0; i <= x; i++) cout << tri[i];
        //cout << "\n";

        bool px  = false;
        int py = 0;
        int f = -1;
        bool found = false;
        bool fz = false;
        for(int i = 0; i <= x; i++)
        {
            if(tri[i] == 2)
            {
                px = true;
                if(f == -1) f = i;
                for(int j = f; j <= x; j++)
                {
                    tri[j] = 0;
                }
                tri[py] = 1;
                break;
            }
            else if(tri[i] == 0)
            {
                py = i;
                if(py > f)
                {
                    f = -1;
                    found = false;
                }
            }
            else if(tri[i] == 1 and !found)
            {
                f = i;
                found = true;
            }
        }


        //for(int i = 0; i <= x; i++) cout << tri[i];
        //cout << "\n";

        if(!px) cout << n;
        else
        {
            long long curr = 1;
            long long ans = 0;
            for(int i = x; i >= 0; i--)
            {
                //cout << curr << endl;
                if(tri[i]) ans += curr;
                curr *= 1ll*3;
            }
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}
