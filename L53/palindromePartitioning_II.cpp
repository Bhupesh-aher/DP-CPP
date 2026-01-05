#include<bits/stdc++.h>
using namespace std;

// Front Partition


// Recursion Solution

bool isPalindrome(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i ++;
        j --;
    }
    return true;
}
int f(int ind, int n, string &s){
    if(ind == n) return 0;

    int minCost = INT_MAX;
    for(int j = ind; j < n; j++){
        if(isPalindrome(ind, j, s) == true){
            int cost =  1 + f(j + 1, n, s);
            minCost = min(minCost, cost);                
        }
    }
    return minCost;
}
int minCut(string s) {
    int n = s.size();
    return f(0, n, s) - 1;
}


// TC - exponential
// SC - O(N)  Auxillary stack space





// DP Memization

bool isPalindrome1(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i ++;
        j --;
    }
    return true;
}
int f1(int ind, int n, string &s, vector<int> &dp){
    if(ind == n) return 0;

    if(dp[ind] != -1) return dp[ind];

    int minCost = INT_MAX;
    for(int j = ind; j < n; j++){
        if(isPalindrome1(ind, j, s) == true){
            int cost =  1 + f1(j + 1, n, s, dp);
            minCost = min(minCost, cost);                
        }
    }
    return dp[ind] = minCost;
}
int minCut1(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return f1(0, n, s, dp) - 1;
}


// TC - O(N * N)
// SC - O(N) + O(N)     Auxillary stack space  +  dp



// Tabulation 

bool isPalindrome2(int i, int j, string &s){
    while(i < j){
        if(s[i] != s[j]) return false;
        i ++;
        j --;
    }
    return true;
}
int minCut2(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);

    dp[n] = 0;
    for(int ind = n - 1; ind >= 0; ind --){
        int minCost = INT_MAX;
        for(int j = ind; j < n; j++){
            if(isPalindrome2(ind, j, s) == true){
            int cost =  1 + dp[j + 1];
            minCost = min(minCost, cost);                
            }
        }
        dp[ind] = minCost;
    }
    return dp[0] - 1;
}



// TC - O(N * N) 
// SC - O(N)      dp





int main(){

    string s = "aab";
    
    cout << minCut(s);
}
