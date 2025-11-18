#include<bits/stdc++.h>
using namespace std;

// Fiboncci Number


// Recrusion Solution

int f(int n){
    if( n <= 1) {
        return n;
    }

    return f(n - 1) + f(n - 2);
}


// TC - O(2 ^ N) SC - O(N) Auxillary stack space 




// DP Memoization 

int f1(int n, vector<int> &dp){
    if( n <= 1) {
        return n;
    }

    if(dp[n] != -1) return dp[n];
 
    return dp[n] = f1(n - 1, dp) + f1(n - 2, dp);
}

// TC - O(N) 
// SC - O(N) + O(N)    Auxillary stack space + DP array 








int main(){
   
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << f(n, dp);
}



// Tabulation

int n = 5;
vector<int> dp(n + 1, -1);

dp[0] = 0;
dp[1] = 1;

for(int i = 2; i <=n; i++){
    dp[i] = dp[i-1] + dp[i - 2];
}

cout << dp[n];


// TC - O(N) 
// SC - O(N) DP Array, and no auxillary space 





// Space Optimization 

int prev2 = 0;
int prev = 1;

for(int i = 2; i <= n; i++){
    int curri = prev + prev2;
    prev2 = prev;
    prev = curri
}

cout << prev;


// TC - O(N) 
// SC - O(1)    we just used 2 variables, that's why don't need any space