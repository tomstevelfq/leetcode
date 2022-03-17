#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<vector<int>> st;

int longestValidParentheses(string s) {
  if (s.size() == 0) {
    return 0;
  }
  int res = 0;
  int i = 0;
  while (i < s.size()) {
    if (s[i] == '(') {
      st.push({1, 0});
      break;
    }
    i++;
  }
  while (i < s.size()) {
    if (s[i] == '(') {
      st.push({1, 0});
    } else {
      if (!s.empty()) {
        if (st.top()[0] == 1) {
          st.pop();
          if (!st.empty() && st.top()[0] == 0) {
            int n = st.top()[1];
            st.pop();
            st.push({0, n + 2});
          } else {
            st.push({0, 2});
          }
        } else {
          int n = st.top()[1];
          st.pop();
          if (!st.empty()) {
            st.pop();
            if (!st.empty() && st.top()[0] == 0) {
              st.push({0, st.top()[1] + n + 2});
            } else {
              st.push({0, n + 2});
            }
          }
        }
        res = max(res, st.top()[1]);
      }
    }
  }
}

int main() {
  cout << longestValidParentheses("((()())(()))") << endl;
  return 0;
}