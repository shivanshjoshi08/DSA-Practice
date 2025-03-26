#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr, int n)
{
    // BRUTE
    // just sort the array

    // BETTER
    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //         count0++;
    //     else if (arr[i] == 1)
    //         count1++;
    //     else
    //         count2++;
    // }
    // for (int i = 0; i < count0; i++)
    // {
    //     arr[i] = 0;
    // }
    // for (int i = count0; i < count1 + count0; i++)
    // {
    //     arr[i] = 1;
    // }
    // for (int i = count0 + count1; i < n; i++)
    // {
    //     arr[i] = 2;
    // }

    // OPTIMAL
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) // Dutch National Flag Algorithm
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void TwoSum(vector<int> &arr, int n, int k)
{
    // BRUTE

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)             // TC : O(n^2)
    //     {
    //         if (arr[i] + arr[j] == k)
    //             cout << i << " " << j;
    //     }
    // }

    // BETTER

    // unordered_map<int, int> mp;
    // for (int i = 0; i < n; i++)
    // {
    //     int rem = k - arr[i];
    //     if (mp.find(rem) != mp.end())              // TC : O(n*log(n))
    //     {                                         // SC : O(n)
    //         cout << mp[rem] << " " << i;
    //     }
    //     mp[arr[i]] = i;
    // }

    // OPTIMAL

    int l = 0, r = 0;
    int sum = 0;
    while (r < n) // this approach has too many limitations, like only a pair will return as answer, don't handle duplicates, works on only positive numbers
    {
        sum += arr[r];
        while (sum > k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum == k)
        {
            cout << l << " " << r;
        }
        r++;
    }
}

int longest_subarray_with_sum_k(vector<int> arr, int n, int k)
{
    // BRUTE APPROACH

    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == k)
    //             ans = max(ans, j - i + 1);
    //     }
    // }
    // return ans;

    // BETTER APPROACH  (zeroes should not be in the array)

    // unordered_map<int, int> preSumMap;                  // TC : O(n*1)
    // int maxlen = 0;                                     // SC : O(n)
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];
    //     if (sum == k)
    //         maxlen = max(maxlen, i + 1);
    //     int rem = sum - k;
    //     if (preSumMap.find(rem) != preSumMap.end())
    //     {
    //         int len = i - preSumMap[rem];
    //         maxlen = max(maxlen, len);
    //     }
    //     if (preSumMap.find(sum) == preSumMap.end())
    //     {
    //         preSumMap[sum] = i;
    //     }
    // }
    // return maxlen;

    // OPTIMAL APPROACH (only for no negative numbers)

    int l = 0, r = 0;
    int sum = 0;
    int maxlen = 0;
    while (r < n)
    {
        sum += arr[r];
        while (l <= r && sum > k)
        {
            sum -= arr[l];
            l++;
        }
        if (sum == k)
            maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

void intersection_of_2_sorted_arrays(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // BRUTE FORCE APPROACH

    // set<int> st;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)             // TC : O(n*m + number of intersected elements)
    //     {                                       // SC : O(number of intersected elements)
    //         if (arr1[i] == arr2[j])
    //         {
    //             st.insert(arr1[i]);
    //         }
    //     }
    // }
    // for (auto it : st)
    // {
    //     cout << it << " ";
    // }

    // BETTER APPROACH

    // unordered_map<int, bool> mp;
    // for (int num : arr1)                                 // TC : O(n+m)
    // {                                                    // SC : O(min(n,m))
    //     mp[num] = true;
    // }
    // for (int num : arr2)
    // {
    //     if (mp[num])
    //     {
    //         cout << num << " ";
    //         mp[num] = false;
    //     }
    // }

    // OPTIMAL APPROACH
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j]) // TC : O(n+m)
            i++;               // SC : O(1)
        else if (arr1[i] > arr2[j])
            j++;
        else
            cout << arr1[i] << " ";
        i++;
        j++;
    }
}

void move_all_zeroes_to_end(vector<int> &arr, int n)
{
    // BRUTE-FORCE

    // vector<int> temp(n);
    // int k = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         temp[k] = arr[i];
    //         k++;
    //     }
    // }
    // for (int j = k; j < n; j++)
    // {
    //     temp[j] = 0;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // BETTER APPROACH

    // int zero_count = 0;
    // for (int i = 0; i < n; i++)            // TC : O(n)
    // {
    //     if (arr[i] != 0)
    //     {
    //         arr[zero_count] = arr[i];           // Total TC : O(2n-k)
    //         zero_count++;
    //     }
    // }
    // while (zero_count < n)               // TC : O(n-k)
    // {
    //     arr[zero_count++] = 0;
    // }

    // OPTIMAL APPROACH
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

void left_rotate_by_k(vector<int> &arr, int n, int k)
{
    // k = k % n;
    // vector<int> temp(k);
    // for (int i = 0; i < k; i++)    //TC : O(k)
    // {
    //     temp[i] = arr[i];
    // }
    // for (int j = k; j < n; j++)     // TC : O(n-k)       // Total TC : O(n+k)
    // {                                                    // Total SC : O(k)
    //     arr[j - k] = arr[j];
    // }
    // int s = 0;
    // for (int t = n - k; t < n; t++)   // TC : O(k)
    // {
    //     arr[t] = temp[s];
    //     s++;
    // }

    k = k % n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.begin() + n);
    reverse(arr.begin(), arr.begin() + n);
}

void left_rotate_by_1(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

int remove_duplicates_in_place(vector<int> &arr, int n)
{
    // set<int> st;
    // for (int i = 0; i < n; i++)            // TC : O(n)  ,  SC : O(n)
    // {
    //     st.insert(arr[i]);
    // }
    // int k = 0;
    // for (auto it : st)
    // {
    //     arr[k] = it;
    //     k++;
    // }
    // return k;

    int i = 0;
    for (int j = 1; j < n; j++) // TC : O(n)   ,  SC : O(1)
    {                           // Two pointer approach
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int second_largest(vector<int> arr, int n)
{
    // int largest = INT_MIN;
    // int sec_largest = INT_MIN;
    // for (int i = 0; i < n; i++)              //TC : O(2n)
    // {
    //     if (arr[i] > largest)
    //         largest = arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > sec_largest && arr[i] != largest)
    //         sec_largest = arr[i];
    // }
    // return sec_largest;

    int largest = INT_MIN;
    int sec_largest = INT_MIN;

    for (int i = 0; i < n; i++) // TC : O(n)
    {
        if (arr[i] > largest)
        {
            sec_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > sec_largest && arr[i] != largest)
        {
            sec_largest = arr[i];
        }
    }
    return (sec_largest == INT_MIN) ? -1 : sec_largest;
}


int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    // vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int k;
    // cin >> k;
    // TwoSum(arr, n, k);
    // for (int i = 0; i < m; i++)
    // {
    //     cin >> arr2[i];
    // }

    // cout << longest_subarray_with_sum_k(arr, n, k) << " ";
    // cout << second_largest(arr, n);
    // int k = remove_duplicates_in_place(arr, n);
    sort012(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // int k;
    // cin >> k;
    // left_rotate_by_k(arr, n, k);
    // move_all_zeroes_to_end(arr, n);
    // intersection_of_2_sorted_arrays(arr1, arr2, n, m);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << ans[i] << " ";
    // }
}