#include <iostream>
#include <vector>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

void DisArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void DisVec(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int nums[], int numSize)    //O(n^2) & stable & breaks asoon as the array is sort.
{
    int i;
    for (i = 0; i < numSize - 1; i++)
    {
        bool swap = false;
        for (int j = 1; j < numSize - i; j++)
        {
            if (nums[j] < nums[j - 1])
            {
                int temp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = temp;
                swap = true;
            }
        }
        cout << "pass " << i + 1 << ": ";
        DisArr(nums, numSize);
        if (swap != true)
            break; // array is done sorting.
    }
    cout << "no of turns:  " << i + 1 << endl;
}
void SelectionSort(int nums[], int numSize) //O(N^2) unstable
{
    int i;
    for (i = 0; i < numSize - 1; i++)
    {
        /* code */ int min = i;
        for (int j = i; j < numSize; j++)
        {
            /* code */
            if (nums[min] > nums[j])
                min = j;
        }
        if (nums[min] < nums[i])
        {
            int temp = nums[min];
            nums[min] = nums[i];
            nums[i] = temp;
        }
        cout << "pass " << i + 1 << ": ";
        DisArr(nums, numSize);
    }
    cout << "no of turns:  " << i + 1 << endl;
}
void InsertionSort(vector<int> nums)    //O(n^2) for partially solved array.
{
    int numSize = nums.size();
    for (int i = 0 + 1; i < numSize; i++)
    {
        for (int j = i - 1; j > -1 /*!out of bound*/; j--)
        {

            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
            }
            else
                break;
        }
        cout << "pass " << i << ": ";
        DisVec(nums);
    }
}
void CyclicSort(vector<int> nums)   //O(n)
{
    int i = 0;
    while (i < nums.size())
    {
        if (nums[nums[i] - 1] != nums[i] && nums[i] < nums.size())
            swap(nums[nums[i] - 1], nums[i]);
        else
            i++;
        cout << "pass " << i << ": ";
        DisVec(nums);
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    // int arr[] = {5, 1, 2, 3, 4};
    // int arr[] = {1,2,3,4,5};
    vector<int> vec = {5, 1, 2, 3, 4};
    vector<int> v = {1, 2, 3, 4};
    // BubbleSort(arr, 5);
    // SelectionSort(arr, 5);
    // InsertionSort(vec);
    CyclicSort(vec);
    return 0;
}
