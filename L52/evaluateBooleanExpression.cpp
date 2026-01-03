#include<bits/stdc++.h>
using namespace std;

// Partition DP 


// Recursion Solution

 int f(int i, int j, int isTrue, string &exp){
    if(i > j) return 0;

    if(i == j){
        if(isTrue == 1) return exp[i] == 'T';
        else return exp[j] = 'F';
    }

    int ways = 0;
    for(int ind = i + 1; ind <= j - 1; ind ++){
        int lT = f(i, ind - 1, 1, exp);
        int lF = f(i, ind - 1, 0, exp);
        int rT = f(ind + 1, j, 1, exp);
        int rF = f(ind + 1, j, 0, exp);

        if(exp[ind] == "&"){
            if(isTrue == 1) ways = ways + (rT * lT);
            else ways = ways + (rT * lF) + (rF * lT) + (rF * lF);
        }
        else if(exp[ind] == '|'){
            if(isTrue == 1) ways = ways + (lT * rT) + (lT * rF) + (lF * rT);
            else ways = ways + (lF * rF);
        }
        else {
            // T ^ F = T,  F ^ T = T,  F ^ F = F,  T ^ T = T
            if(isTrue == 1){
                ways = ways + (lT * rF) + (lF * rT);
            }
            else ways = ways + (lT * rT) + (lF * rF);
        }
    }
    return ways;
    
}
int evaluateExprssion(int n, vector<string>& exp) {
    return f(0, n - 1, 1, exp);
}


// TC - exponential
// SC - O(N)  Auxillary stack space





// DP Memization

int f1(int i, int j, int isTrue, string &exp, vector<vector<vector<int>>> &dp){
    if(i > j) return 0;

    if(i == j){
        if(isTrue == 1) return exp[i] == 'T';
        else return exp[j] = 'F';
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for(int ind = i + 1; ind <= j - 1; ind += 2){
        int lT = f1(i, ind - 1, 1, exp, dp);
        int lF = f1(i, ind - 1, 0, exp, dp);
        int rT = f1(ind + 1, j, 1, exp, dp);
        int rF = f1(ind + 1, j, 0, exp, dp);

        if(exp[ind] == "&"){
            if(isTrue == 1) ways = ways + (rT * lT);
            else ways = ways + (rT * lF) + (rF * lT) + (rF * lF);
        }
        else if(exp[ind] == '|'){
            if(isTrue == 1) ways = ways + (lT * rT) + (lT * rF) + (lF * rT);
            else ways = ways + (lF * rF);
        }
        else {
            // T ^ F = T,  F ^ T = T,  F ^ F = F,  T ^ T = T
            if(isTrue == 1){
                ways = ways + (lT * rF) + (lF * rT);
            }
            else ways = ways + (lT * rT) + (lF * rF);
        }
    }
    return dp[i][j][isTrue] = ways;
    
}
int evaluateExprssion1(int n, vector<string>& exp) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return f1(0, n - 1, 1, exp, dp);
}


// TC - O(N * N * 2) * N 
// SC - O(N) + O(N * N * 2)     Auxillary stack space  +  dp








int main(){

    string exp = "F|T^F";
    int n = exp.size();
    
    cout << evaluateExprssion(n, exp);
}
