#include <bits/stdc++.h>
using namespace std;
int partition_index(vector<int> arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[i]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int part_idx = partition_index(arr, low, high);
    quick_sort(arr, low, part_idx - 1);
    quick_sort(arr, part_idx + 1, high);
}

void merge_sort_helper(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] < arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);

    merge_sort_helper(arr, low, mid, high);
}

vector<int> insertion_sort(vector<int> arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
        }
    }
    return arr;
}

vector<int> bubble_sort(vector<int> arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])

                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}

vector<int> selection_sort(vector<int> arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])

                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
    return arr;
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
    // vector<int> ans = selection_sort(arr, n);
    // vector<int> ans = bubble_sort(arr, n);
    // vector<int> ans = insertion_sort(arr, n);
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}