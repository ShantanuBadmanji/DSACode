
#include <iostream>
using namespace std;

int* MergeSort(int arr[], int start, int end)
{
    if (start == end)
    {
        int *arr1 = new int[1];
        arr1[0] = arr[start];
        return arr1;
    }

    int mid = start + (end - start) / 2;
    // first
    int *arr1 = MergeSort(arr, start, mid);
    // right
    int *arr2 = MergeSort(arr, mid + 1, end);
    // merging array
    int *arr3 = new int[end - start + 1];

    int l1 = mid - start + 1,
        l2 = end - mid;

    int i = 0,
        j = 0,
        k = 0;

    while (i < l1 && j < l2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    if (j < l2)
    {
        while (j < l2)
        {
            arr3[k] = arr2[j];
            j++;
            k++;
        }
    }

    else if (i < l1)
    {
        while (i < l1)
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
    }
    return arr3;
}

void MergeSortInplace(int *arr, int start, int end)
{
    if (start == end)
    {
        int *arr3 = new int[1];
        arr3[0] = arr[start];
        arr[start] = arr3[0];
        return;
    }

    int mid = start + (end - start) / 2;
    // first
    MergeSortInplace(arr, start, mid);
    // right
    MergeSortInplace(arr, mid + 1, end);
    // merging array

    int l1 = mid - start + 1,
        l2 = end - mid,
        l3 = end - start + 1;

    int *arr3 = new int[l3];

    int i = start,
        j = mid + 1,
        k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            arr3[k] = arr[i];
            i++;
        }
        else
        {
            arr3[k] = arr[j];
            j++;
        }
        k++;
    }

    if (j <= end)
    {
        while (j <= end)
        {
            arr3[k] = arr[j];
            j++;
            k++;
        }
    }

    else if (i <= mid)
    {
        while (i <= mid)
        {
            arr3[k] = arr[i];
            i++;
            k++;
        }
    }

    for (int i = 0; i < l3; i++)
    {
        arr[start + i] = arr3[i];
    }
}

void display(int arr[], int l)
{
    for (int i = 0; i < l; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(int argc, char const *argv[])
{
    int arr[] = {5, 4, 3, 2, 1};
    int l = 5;

    int *arr2 = MergeSort(arr, 0, l - 1);
    display(arr, l);
    display(arr2, l);

    MergeSortInplace(arr, 0, l - 1);
    cout << "Inplace mergesort: ";
    display(arr, l);
    return 0;
}
