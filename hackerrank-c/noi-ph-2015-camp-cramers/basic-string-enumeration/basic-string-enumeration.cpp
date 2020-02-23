#include <bits/stdc++.h>

using namespace std;

int k;
void f(int n, string s)
{
    if(n==0)
    {
        map<int, int> m;
        int k=s.size();
        for(int i=0; i<k; i++) m[s[i]-'a']++;
        for(int i=0; i<26; i++)
        {
            if(m[i] == 1) return;
        }
        cout<<s<<"\n";
        return;
    }
    for(int i=0; i<k; i++)
    {
        f(n-1, s + char(i+'a'));
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);

    int n, q; cin >> q;

    while(q--)
    {
        cin>>n>>k;
        f(n, "");
        cout<<"---\n";;
    }
}
