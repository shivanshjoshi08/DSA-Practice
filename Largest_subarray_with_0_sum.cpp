#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr)
{
    int maxLength = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i ; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }
    return maxLength;
}

int main()
{
    vector<int> v;
    int n, input;
    // cout << "Enter number of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }
    cout << maxLen(v);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << endl;
    // }
}