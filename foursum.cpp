#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> res;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<int> pos(nums.size(),0);
    vector<int> pos1(nums.size(),0);
    sort(nums.begin(),nums.end());
    int aa=nums.back();
    int p=nums.size()-1;
    for(int i=nums.size()-1;i>=0;i--){
        if(nums[i]!=aa){
            aa=nums[i];
            pos[i]=i;
            p=i;
        }else{
            pos[i]=p;
        }
    }

    aa=nums[0];
    p=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=aa){
            aa=nums[i];
            pos1[i]=i;;
            p=i;
        }else{
            pos1[i]=p;
        }
    }

    for(int i=0;i<nums.size();i=pos[i]+1){
        for(int j=i+1;j<nums.size();j=pos[j]+1){
            int k=j+1;
            int l=nums.size()-1;
            while(k<l){
                long long now=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(now==target){
                    res.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k=pos[k]+1;
                    l=pos1[l]-1;
                }else if(now>target){
                    l=pos1[l]-1;
                }else{
                    k=pos[k]+1;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums={0,8,0,0,1,1,4,3,1,5,2,2,2};
    int target=8;
    vector<vector<int>> vv=fourSum(nums,target);
    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++){
            cout<<vv[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}