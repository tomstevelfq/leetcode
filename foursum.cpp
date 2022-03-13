#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> res;
set<vector<int>> s;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int k=j+1;
            int l=nums.size()-1;
            while(k<l){
                long long now=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                if(now==target){
                    vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                    if(s.find(temp)==s.end()){
                        s.insert(temp);
                        res.push_back(temp);
                    }
                    k++;
                    l--;
                }else if(now>target){
                    l--;
                }else{
                    k++;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums={1000000000,1000000000,1000000000,1000000000};
    int target=0;
    vector<vector<int>> vv=fourSum(nums,target);
    for(int i=0;i<vv.size();i++){
        for(int j=0;j<vv[i].size();j++){
            cout<<vv[i][j]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}