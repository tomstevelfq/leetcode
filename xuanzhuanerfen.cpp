#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int i=0;
    int j=nums.size();
    int mid;
    while(i<=j){
        mid=(i+j)/2;
        if(nums[mid]>nums[0]){
            if(nums[mid]>target){
                if(nums[0]>target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }else{
                i=mid+1;
            }
        }else{
            if(nums[mid]>target){
               j=mid-1; 
            }else{
                if(nums[0]>target){
                    i=mid+1;
                }else{
                    j=mid-1;
                }
            }
        }
    }
    if(nums[mid]==target){
        return mid;
    }
    return -1;
}

int main() {
  return 0;
}