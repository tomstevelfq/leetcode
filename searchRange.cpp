#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.size()==0){
        return {-1,-1};
    }
    int i=0;
    int j=nums.size()-1;
    int mid;
    while(i<=j){
        mid=(i+j)/2;
        if(nums[mid]==target){
            break;
        }else if(nums[mid]>target){
            j-=1;
        }else{
            i+=1;
        }
    }
    if(nums[mid]==target){
        int a=0;
        int b=mid;
        int c=mid;
        int d=nums.size()-1;
        int m;
        int n;                                                                                                                                                                                                                                                                                                                                                   
        while(a<=b){
            m=(a+b)/2;
            if(nums[m]==target){
                if(m==0||nums[m-1]!=target){
                    break;
                }else{
                    b=m-1;
                }
            }else{
                a=m+1;
            }
        }

        while(c<=d){
            n=(c+d)/2;
            if(nums[n]==target){
                if(n==nums.size()-1||nums[n+1]!=target){
                    break;
                }else{
                    c=n+1;
                }
            }else{
                d=n-1;
            }
        }
        return {m,n};
    }
    return {-1,-1};
}

int main() {
  return 0;
}