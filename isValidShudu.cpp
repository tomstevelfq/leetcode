#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    vector<bool> yan(9,0);
    vector<bool> yan1(9,0);
    for(int i=0;i<9;i++){
        yan.assign(9,0);
        yan1.assign(9,0);
        for(int j=0;j<9;j++){
            if(yan[board[i][j]-1]||yan1[board[j][i]-1]){
                return false;
            }
            yan[board[i][j]-1]=true;
            yan1[board[j][i]-1]=true;
        }
    }

    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            yan.assign(9,0);
            for(int m=0;m<3;m++){
                for(int n=0;n<3;n++){
                    if(yan[board[i+m][j+n]-1]){
                        return false;
                    }
                    yan[board[i+m][j+n]-1]=true;
                }
            }
        }
    }
    
    return true;
}

int main() {
  return 0;
}