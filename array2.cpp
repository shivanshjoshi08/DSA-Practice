#include <bits/stdc++.h>
using namespace std;

int best_time_to_buy_and_sell_stocks(vector<int> &arr, int n)
{
    
}

int maximum_subarray_sum_length_kadanes_algo(vector<int> &arr, int n)
{
    // optimal
    int maxSum = INT_MIN, currSum = 0, start = 0, end = 0, tempStart = 0;
    if (n == 0)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
            tempStart = i + 1;
        }
        if (currSum > maxSum)
        {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }
    return end - start + 1;
}

int maximum_subarray_sum_kadanes_algo(vector<int> &arr, int n)
{
    // optimal
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
            currSum = 0;
        if (currSum > maxSum)
            maxSum = currSum;
    }
    return maxSum;
}

int majority_element(vector<int> &arr, int n)
{
    // Brute
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[j] == arr[i])
    //         {
    //             count++;
    //         }
    //     }
    //     if (count > n / 2)
    //         return arr[i];
    // }
    // return 0;

    // Better
    // unordered_map<int, int> freq;
    // for (int i = 0; i < n; i++)
    // {
    //     freq[arr[i]]++;
    // }
    // for (auto it : freq)
    // {
    //     if (it.second > (n / 2))
    //         return it.first;
    // }
    // return 0;

    // Moor's voting Algorithm is Optimal

    int candidate = 0, count = 0;
    // Phase 1: Find the candidate
    for (int num : arr)
    {
        if (count == 0)
        {
            candidate = num;
            count = 1;
        }
        else if (num == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int num : arr)
    {
        if (num == candidate)
            count++;
    }
    if (count > (n / 2))
        return candidate;
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << majority_element(arr, n) << endl;
    // cout << maximum_subarray_sum_length_kadanes_algo(arr, n);

    cout << best_time_to_buy_and_sell_stocks(arr, n) << endl;
}