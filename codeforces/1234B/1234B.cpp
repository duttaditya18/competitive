#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    int a;

    set<int> s;
    deque<int> d;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(s.count(a)) continue;

        d.push_front(a);
        s.insert(a);

        if(cnt == k)
        {
            s.erase(d.back());
            d.pop_back();
            continue;
        }
        cnt++;
    }


    cout << d.size() << "\n";
    for(deque<int>::iterator i = d.begin(); i != d.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
    return 0;
}
