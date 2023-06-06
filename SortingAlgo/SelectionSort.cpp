#include <iostream>
using namespace std;

void DisArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void SelectionSort(int nums[], int numSize)
{
    int i;
    for (i = 0; i < numSize - 1; i++)
    {
        /* code */ int min = i;
        for (int j = i+1; j < numSize; j++)
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

int main(int argc, char const *argv[])
{
    /* code */
    int arr[] = {1,2,3,4,5};
    //int arr[] = {5, 1, 2, 3, 4};
    SelectionSort(arr, 5);
    return 0;
}
