#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int BS_infiniteArr(int arr[],int target){
    //Initial two sized array
    int s =0,e=1;

    cout << "start: "<<s<<" end: "<<e<<endl;
    //find the range with target in it.
    while(arr[e]<target){
        int size = e-s+1;
        s = e+1;
        e = e + size*2;
        cout << "start: "<<s<<" end: "<<e<<" size: "<<size<<endl;
    }

    //normal binary
    while (s<=e)
    {
        int mid = s+(e-s)/2;

        if(arr[mid]<target)
            s= mid+1;
        else if(arr[mid]>target)
            e = mid-1;

        else
            return mid;
    }
    return -1;
}

int BinarySearch(int *arr, int start,int end,int key){
    if(start>end)
        return -1;

    int mid = start+ (end-start)/2;

    if(arr[mid] == key)
        return mid;
    
    if(arr[mid] <key)
        return BinarySearch(arr,mid+1, end, key);
    
    else if(arr[mid]>key)
        return BinarySearch(arr,start, mid-1,key);
    
}
int LowerBound(int *arr,int start,int end,int key){
    if(start>end)
        return start;

    int mid = start+ (end-start)/2;

    if(arr[mid] == key){
            while(arr[mid-1] == arr[mid] && mid>=0){
                mid--;
            }
            return mid;
        }
    
    if(arr[mid] <key)
        return LowerBound(arr,mid+1, end, key);
    
    else if(arr[mid]>key)
        return LowerBound(arr,start, mid-1,key);
}


class Solution {
bool binarySearch(vector<int> &nums,int s,int e,int target){
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<target){
                s = mid+1;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }

    int helper(vector<int>& nums, int target,bool isfirst) {
    int ans = -1;
        int s = 0;
        bool found = false;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]<target){
                s= mid+1;
            }
            else if(nums[mid]>target){
                e = mid-1;
            }
            else{
                found =true;
                if(isfirst){
                    e = mid-1;
                }
                else{
                    s = mid+1;
                }
            }
        }
        if(!found){
            return ans;
        }
        if(isfirst ){
                   ans = s;
                }
                else{
                    ans = e;
                }
            
        return ans;
    }
  int findPivot(vector<int>nums){
        int s = 0,e = nums.size()-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mid<nums.size()-1 && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(mid>0 && nums[mid]<nums[mid-1]){
                return mid-1;
            }
            while(s<=e &&nums[mid]==nums[s] && nums[mid]==nums[e] ){
                s = (s+1);//%nums.size();
                e = (e-1);
            }
            if(nums[mid]<nums[s]){
                e = mid-1;
            }
            else if(nums[mid]>nums[e]){
                s = mid+1;
            }
        }
        return -1;
    }
public:

    bool search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        if(pivot==-1){
            return binarySearch(nums,0,nums.size()-1,target);
        }
        else if(nums[pivot]==target){
            return true;
        }
        else{
            if(nums[0]<=target)
                return binarySearch(nums,0,pivot,target);
            else{
                return binarySearch(nums,pivot+1,nums.size()-1,target);
            }
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans= {-1,-1};
        ans[0] = helper(nums,target,true);
        if(ans[0]==-1){
            return ans;
        }
        ans[1] = helper(nums,target,false);
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    // int arr[] = {1,2,3,5,6};
    int arr[] = {6,6,6,6,6};
    int arrSize = 5;
    int key = 5;
    cout<<BinarySearch(arr,0,arrSize-1,key)<<endl;
    cout<<LowerBound(arr,0,arrSize-1,key)<<endl;
    vector<int> vec = {};
    Solution s;
    vector<int> ans = s.searchRange(vec,10);
    cout<<ans[0]<<" "<<ans[1]<<endl;


    //for infinite array
    int num[100] = {1,2,8,12,16,20,21,23,32,56,76,80,85,89,91,93,97,100,43,43};
    cout<<BS_infiniteArr(num,91)<<endl;

    //rotated array
    vector<int> nums = {1};
    cout<<s.search(nums,0)<<endl;
    return 0;
}

