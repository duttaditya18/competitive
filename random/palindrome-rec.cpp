#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string a, int n, int i)
{
    if(i == n - i - 1) return true;
    if(a[i] != a[n - i - 1]) return false;
    if(isPalindrome(a, n, i + 1)) return true;
    return false;
}

int main(void)
{
    string a = "daabaad";
    int n = a.size();
    cout << isPalindrome(a, n, 0);
}
