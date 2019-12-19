#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    queue<int> q;

    int maxDepth = 0, curDepth = 0, maxfDepth = 0, curfDepth = 0;

    int maxSeq = 0, curSeq = 0, maxfSeq = 0, curfSeq = 0;

    int x;
    for(int i = 1; i <= n; i++)
    {
        cin >> x;
        if(x == 1)
        {
            curSeq++;
            if(q.empty())
            {
                curfSeq = i;
            }
            q.push(x);
            curDepth++;
            curfDepth = i;
        }
        else if(x == 2)
        {
            q.pop();
            curSeq++;
            if(q.empty())
            {
                if(curSeq > maxSeq)
                {
                    maxSeq = curSeq;
                    maxfSeq = curfSeq;
                }
                curSeq = 0;
            }
            if(curDepth > maxDepth)
            {
                maxDepth = curDepth;
                maxfDepth = curfDepth;
            }
            curDepth--;
        }
    }

    cout << maxDepth << " " << maxfDepth << " " << maxSeq << " " << maxfSeq << endl;
}
