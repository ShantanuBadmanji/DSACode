#include <iostream>
using namespace std;

int length = 7;
void display(int nums[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
void swap(int nums[], int index1, int index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}
int getpivotIndex(int *nums, int s, int e)
{
    int mid = s + (e - s) / 2;
    int pindex = s;
    for (int i = s; i <= e; i++)
    {
        if (nums[i] < nums[mid])
            pindex++;
    }
    swap(nums, pindex, mid);
    display(nums, length);
    return pindex;
}
void QuickSort(int nums[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int pindex = getpivotIndex(nums, s, e); // get pivot after swaping
    int pivot = nums[pindex];
    int i = s,
        j = e;
    while (i < pindex && j > pindex)
    {
        while (i < pindex && nums[i] < nums[pindex])
        {
            i++;
        }
        while (nums[j] >= nums[pindex] && j > pindex)
        {
            j--;
        }
        swap(nums, i, j);
        display(nums, length);
    }

    QuickSort(nums, s, pindex - 1);
    QuickSort(nums, pindex + 1, e);
}

int main()
{
    int nums[] = {1, 8, 6, 4, 2, 7, 5};
    display(nums, length);
    QuickSort(nums, 0, length - 1);
    display(nums, length);
    cout << "Hello World";

    return 0;
}
