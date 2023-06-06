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
void BubbleSort(int nums[], int numSize)
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
int main(int argc, char const *argv[])
{
    /* code */
    //int arr[] = {5, 1, 2, 3, 4};
    int arr[] = {1,2,3,4,5};
    BubbleSort(arr, 5);
    return 0;
}
