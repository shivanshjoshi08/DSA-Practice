#include <bits/stdc++.h>
using namespace std;

bool palindrome2(string s, int i)
{
    int n = s.size();
    if (i >= n / 2)
        return true;
    if (s[i] != s[n - i - 1])
        return false;
    return palindrome2(s, i + 1);
}

bool palindrome(string s, int start, int end) // palindrome
{
    if (start >= end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }
    return palindrome(s, start + 1, end - 1);
}

string rev_string(string s) // reverse string
{
    if (s.size() <= 1)
        return s;
    return rev_string(s.substr(1)) + s[0];
}

int pow(int x, int n) // power function
{
    if (n == 0)
    {
        return 1;
    }
    return x * pow(x, n - 1);
}

int fact(int n) // factorial
{
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    // int n, x;
    // cin >> n >> x;
    // cout << fact(n);
    // cout << endl;
    // cout << pow(x, n);

    string s;
    cin >> s;

    // cout << rev_string(s);
    if (palindrome2(s, 0))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    // if (palindrome(s, 0, s.size() - 1))
    // {
    //     cout << "True" << endl;
    // }
    // else
    // {
    //     cout << "False" << endl;
    // }
}