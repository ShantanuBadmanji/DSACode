#include<iostream>
using namespace std;

void swap(int *arr,int index1,int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int pivotPosi(int arr[], int arrSize, int pivotEle){
    int posi = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if(arr[i] < pivotEle)
            posi++;
    }
    return posi;    
}

void QuickSort(int* arr,int s,int e){
    if(s>=e){
        return;
    }
    
    int m = s + (e-s)/2;
    int pivotEle = arr[m];
    int pivotIndex = pivotPosi(arr,e-s+1,pivotEle);
    swap(arr,pivotIndex,m);

    int i = s,
        j = e;
    
    while(i<pivotIndex && j>pivotIndex){
        while (i<pivotIndex)
        {
            if(arr[i]>pivotEle)
                break;
            i++;
        }
        
        while(j>pivotIndex){
            if(arr[j]<pivotEle)
                break;
            
            j--;
        }
        swap(arr, i++,j--);
        // i++;j--;
    }
    // fisrt
    QuickSort(arr,s,m-1);
    //sec
    QuickSort(arr,m+1,e);
}
void display(int arr[],int arrSize){
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    int arr[] = {5,4,3,2,1};
    int l = 5;
    display(arr,l);
    QuickSort(arr,0,l-1);
    display(arr,l);
    return 0;
}


