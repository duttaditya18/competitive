#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, c = 1;
    cin >> n;

    while(n != 1)
    {
        if(n % 2)
        {
            n = (n * 3) + 1;
        }
        else
        {
            n = n / 2;
        }
        c++;
    }

    cout << c;
    return 0;
}
