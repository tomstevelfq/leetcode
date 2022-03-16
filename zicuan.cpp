#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

multiset<string> st;
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    for(int i=0;i<words.size();i++){
        st.insert(words[i]);
    }
    multiset<string> ss;
    int len=words[0].size();
    for(int i=0;i<len;i++){
        ss=st;
        int j=i;
        int end=j;
        while(j<=s.size()-words.size()*len){
            if(st.find(s.substr(end,end+len))!=st.end()){
                    ss.erase(st.find(s.substr(end,end+len)));
                    end+len;
                }else{
                    ss=st;
                    end+=len;
                    j=end;
            }
            if((end-j)/len==words.size()){
                res.push_back(j);
                ss.erase(ss.find(s.substr(j,j+len)));
                j+=len;
            }
        }
    }
    return res;
}
int main(){
    return 0;
}