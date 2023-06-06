#include<iostream>
#include <algorithm>

using namespace std;
void DisArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort(int* nums,int numSize)    //O(n^2) for partially solved array.
{   
    int i;
    for (i = 0 + 1; i < numSize; i++)
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
    }
        
        DisArr(nums,numSize);
}

void Merge(int *arr,int s,int e){
    InsertionSort(&arr[s],e-s+1);
}

void MergeSort(int *arr,int s, int e){
    if(s>=e)
        return;

    int mid = s+(e-s)/2;
    
    //LEFT SIDE
    MergeSort(arr,s,mid);

    //RIGHT SIDE
    MergeSort(arr,mid+1,e);

    Merge(arr,s,e);
    
}
int main(int argc, char const *argv[])
{
    int arr[] = {10,1,6,5,3,8};
    MergeSort(arr,0,6-1);
    /* code */
    return 0;
}
