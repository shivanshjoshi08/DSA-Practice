#include <bits/stdc++.h>
using namespace std;
int sum2n(int n) // functional recursion
{
    if (n == 0)
        return 0;
    return n + sum2n(n - 1);
}

void sumToN(int i, int sum) // parameterised recursion
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    sumToN(i - 1, sum + i);
}

int main()
{
    int n;
    cin >> n;
    sumToN(n, 0);
    cout << endl;
    cout << sum2n(n);
}