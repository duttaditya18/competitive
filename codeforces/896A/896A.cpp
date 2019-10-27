#include <bits/stdc++.h>

using namespace std;

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string s1 = "What are you doing while sending \"";
string s2 = "\"? Are you busy? Will you send \"";
string s3 = "\"?";

#define ma 100000

long long inf = 1e18 + 1;
long long f[ma + 1] = {};

int main(void)
{
    f[0] = f0.size();

    for(int i = 1; i <= ma; i++)
    {
        f[i] = min(inf, (2 * f[i-1]) + s1.size() + s2.size() + s3.size());
    }

    // for(int i=0; i<=ma; i++) cout << i << " " << f[i] << "\n";

    int q;
    cin >> q;

    int n;
    long long k;

    string ans = "";
    while(q--)
    {
        cin >> n >> k;
        if(f[n] < k)
        {
            ans += ".";
            continue;
        }
        for(int i = n; i >= 0; i--)
        {
            //cout << i << endl;
            if(i == 0)
            {
                ans += f0[k - 1];
                break;
            }

            if(k <= s1.size())
            {
                ans += s1[k - 1];
                break;
            }
            k -= s1.size();

            if(k <= f[i - 1]) continue;
            k -= f[i - 1];

            if(k <= s2.size())
            {
                ans += s2[k - 1];
                break;
            }
            k -= s2.size();

            if(k <= f[i - 1]) continue;
            k -= f[i - 1];

            ans += s3[k - 1];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
