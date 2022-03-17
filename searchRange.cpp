#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int i=0;
    int j=nums.size()-1;
    int mid;
    while(i<=j){
        mid=(i+j)/2;
        if(nums[mid]==target){
            break;
        }else if(nums[mid]>target){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    if(nums[mid]==target){
        return mid;
    }else if(nums[mid]>target){
        return mid;
    }else{
        return mid+1;
    }
}

int main() {
    vector<int> nums={1};
    int target=1;
    cout<<searchInsert(nums,target)<<endl;
  return 0;
}