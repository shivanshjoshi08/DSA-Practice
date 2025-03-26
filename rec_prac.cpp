#include <bits/stdc++.h>
using namespace std;
void func4(int n) // recusrion print n to 1
{
    if (n < 1)
        return;
    cout << n << " ";
    func4(n - 1);
}
void func3(int n) // recusrion print 1 to n
{
    if (n < 1)
        return;
    func3(n - 1);
    cout << n << " ";
}

void func2(int i, int n) // backtracking print n to 1
{
    if (i < 1)
        return;
    cout << i << " ";
    func2(i - 1, n);
}

void func1(int i, int n) // backtracking print 1 to n
{
    if (i < 1)
    {
        return;
    }
    func1(i - 1, n);
    cout << i << " ";
}
int main()
{
    int n;
    cin >> n;
    func1(n, n);
    cout << endl;
    func2(n, n);
    cout << endl;
    func3(n);
    cout << endl;
    func4(n);
}