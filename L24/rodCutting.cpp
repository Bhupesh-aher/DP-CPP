#include<bits/stdc++.h>
using namespace std;


// Recursion Solution

int f(int ind, int N, vector<int> &price){
    if(ind == 0){
        return (N * price[0]);
    }

    int notTake = 0 + f(ind - 1, N, price);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if(rodLength <= N) take = price[ind] + f(ind, N - rodLength, price);
    return max(notTake, take);
}

int rodCutting(int n, vector<int> &price) {
    return f(n - 1, n, price);
}

// TC - >> O(2 ^ N)             (>> this means greater than 2 ^ N) beacuse we are standing at same index so that means there are not 2 ways on the index. There multiple ways on index
// SC - O(N)  Auxillary stack space (>> this means greater than  N)
// Therotically it is not possible to to tell the exact TC so just say exponential.
// same goes to SC as well.



// DP Memization

int f1(int ind, int N, vector<int> &price, vector<vector<int>> &dp){
    if(ind == 0){
        return (N * price[0]);
    }

    if(dp[ind][N] != -1) return dp[ind][N];

    int notTake = 0 + f1(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if(rodLength <= N) take = price[ind] + f1(ind, N - rodLength, price, dp);
    return dp[ind][N] = max(notTake, take);
}

int rodCutting1(int n, vector<int> &price) {
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f1(n - 1, n, price, dp);
}


// TC - O(N * N) 
// SC - O(N) + O(N * N)     Auxillary stack space  +  dp




// Tabulation 


int rodCutting2(int n, vector<int> &price) {
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for(int N = 0; N <= n; N++) dp[0][N] = N * price[0];

    for(int ind = 1; ind < n; ind ++){
        for(int N = 0; N <= n; N++){
            int notTake = 0 + dp[ind - 1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= N) take = price[ind] + dp[ind][N - rodLength];
            dp[ind][N] = max(notTake, take);
        }
    }

    return dp[n - 1][n];
}

// TC - O(N * N) 
// SC - O(N * N)      dp




// Space optimization

int rodCutting3(int n, vector<int> &price) {
    vector<int> prev(n + 1, 0);

    for(int N = 0; N <= n; N++) prev[N] = N * price[0];

    for(int ind = 1; ind < n; ind ++){
        vector<int> curr(n + 1, 0);
        for(int N = 0; N <= n; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= N) take = price[ind] + curr[N - rodLength];
            curr[N] = max(notTake, take);
        }
        prev = curr;
    }

    return prev[n];
}

// TC - O(N * N) 
// SC - O 2(N)     prev and curr










// Space optimization - Single Array Space Optimised 


int rodCutting4(int n, vector<int> &price) {
    vector<int> prev(n + 1, 0);

    for(int N = 0; N <= n; N++) prev[N] = N * price[0];

    for(int ind = 1; ind < n; ind ++){
        for(int N = 0; N <= n; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(rodLength <= N) take = price[ind] + prev[N - rodLength];
            prev[N] = max(notTake, take);
        }
    }

    return prev[n];
}

// TC - O(N * N) 
// SC - O(N)     prev 





int main(){
    int n = 5;
    vector<int> price = {2, 5, 7, 8, 10};
    
    cout << rodCutting4(n, price);

                          
 
}
