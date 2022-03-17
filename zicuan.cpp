#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    if(s.size()==0){
        return 0;
    }
    int res=0;
    vector<int> vec(s.size(),0);
    vector<int> num(s.size(),0);
    if(s[0]=='('){
        vec[0]=1;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            vec[i]=vec[i-1]+1;
        }else{
            if(vec[i-1]>0){
                vec[i]=vec[i-1]-1;
                if(s[i-1]=='('){
                    if(i>=2&&s[i-2]==')'){
                        num[i]=num[i-2]+2;
                    }else{
                        num[i]=2;
                    }
                }else{
                    if(i-2-num[i-1]>=0&&s[i-2-num[i-1]]==')'){
                        num[i]=num[i-1]+num[i-2-num[i-1]]+2;
                    }else{
                        num[i]=num[i-1]+2;
                    }
                }
            }
        }
        res=max(res,num[i]);
    }
}

int main() {
    cout<<longestValidParentheses("(()()(())")<<endl;
  return 0;
}