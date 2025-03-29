#include <bits/stdc++.h>
using namespace std;
void rearrange_elements_by_sign_part_2(vector<int> &arr, int n)
{
    // vector<int> ans(n);
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int idx = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[idx] = pos[i];
            idx++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int idx = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[idx] = neg[i];
            idx++;
        }
    }

    // int k = 0;
    // for (int num : ans)
    // {
    //     arr[k] = num;
    //     k++;
    // }
}

void rearrange_elements_by_sign(vector<int> &arr, int n)
{
    // optimal
    int posIdx = 0;
    int negIdx = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[posIdx] = arr[i];
            posIdx += 2;
        }
        else
        {
            ans[negIdx] = arr[i];
            negIdx += 2;
        }
    }
    int k = 0;
    for (int num : ans)
    {
        arr[k] = num;
        k++;
    }
}

int best_time_to_buy_and_sell_stocks(vector<int> &arr, int n)
{
    int minPrice = arr[0];
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = arr[i] - minPrice;
        maxProfit = max(maxProfit, cost);
        minPrice = min(minPrice, arr[i]);
    }
    return maxProfit;
}

int maximum_subarray_sum_length_kadanes_algorithm(vector<int> &arr, int n)
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
    // cout << maximum_subarray_sum_length_kadanes_algorithm(arr, n);
    // cout << best_time_to_buy_and_sell_stocks(arr, n) << endl;
    rearrange_elements_by_sign_part_2(arr, n);
    for (int num : arr)
    {
        cout << num << " ";
    }
}