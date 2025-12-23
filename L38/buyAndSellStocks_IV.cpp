#include<bits/stdc++.h>
using namespace std;


// in this question you can do k transactions  
// this problem is exact sane as previous problem (DP - 37) buyAndSellStocks_III
// instead of cap = 2 we will just send the k that's the only change and this problem is easily solved

// so i have done the modified Space optimization of (DP - 37) buyAndSellStocks_III for this problem
// instead of cap limit as 2 i just put the limit k
// so you can check that below 
// you can write Recursion Solution, DP Memization, Tabulation in same way by replacing cap with k
// that's the only change you need to make and this problem is solved


// Space optimization - from DP - 37 with modifucation of by replacing cap with k



int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(k+1, 0));
    vector<vector<int>> curr(2, vector<int>(k+1, 0));


    for(int ind = n - 1; ind >= 0; ind --){
        for(int buy = 0; buy <= 1; buy ++){
            for(int cap = 1; cap <= k; cap ++){
                int profit = 0;
                if(buy == 1){                   
                    profit = max(-prices[ind] + prev[0][cap], 0 + prev[1][cap]);
                                                
                }
                else {                    
                    profit = max(prices[ind] + prev[1][cap - 1],  0 + prev[0][cap]);
                }           
                curr[buy][cap] = profit;
            }
        }
        prev = curr;
    }
    return prev[1][k];
}



// In (DP - 37) buyAndSellStocks_III 
// we discuss the the 2nd approach where we write recursion and DP memoization solution 
// and we can do it here by using exact same code by just passing k in paramters
// and we will also see tabulation and space optimization as well which we didn't disucss in DP - 37 for the 2nd approach



// Recursion Solution

int f(int ind, int transaction, vector<int> &prices, int n, int k){
    if(transaction == k * 2) return 0;
    if(ind == n) return 0;

    int profit = 0;
     // buy
    if(transaction % 2 == 0){                  
        profit = max(-prices[ind] + f(ind + 1, transaction + 1, prices, n, k), 0 + f(ind + 1, transaction, prices, n , k));
    }
    // sell
    else {                                      
        profit = max(prices[ind] + f(ind + 1, transaction + 1, prices, n, k), 0 + f(ind + 1, transaction, prices, n, k));
    }
    return profit;
}

int maxProfit1(int k, vector<int>& prices) {
    int n = prices.size();
    return f(0, 0, prices, n, k);
}

// why k * 2 beacuse if k = 2 this means B S B S
// so buy sell can be done 2 times (2 transactions)
// if k = 3 then  B S B S B S 

// TC - O(2 ^ N) exponential
// SC - O(N)  Auxillary stack space



// DP Memization

int f1(int ind, int transaction, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
    if(transaction == k * 2) return 0;
    if(ind == n) return 0;

    if(dp[ind][transaction] != -1) return dp[ind][transaction];

    int profit = 0;
    if(transaction % 2 == 0){
        profit = max(-prices[ind] + f1(ind + 1, transaction + 1, prices, n, k, dp), 0 + f1(ind + 1, transaction, prices, n , k, dp));
    }
    else {
        profit = max(prices[ind] + f1(ind + 1, transaction + 1, prices, n, k, dp), 0 + f1(ind + 1, transaction, prices, n, k, dp));
    }
    return dp[ind][transaction] = profit;
}
int maxProfit2(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 *k, -1));
    return f1(0, 0, prices, n, k, dp);
}


// TC - O(N * 2k) 
// SC - O(N) + O(N * 2k)     Auxillary stack space  +  dp




// Tabulation 

int maxProfit3(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n +1, vector<int>(2 * k + 1, 0));

    for(int ind = n - 1; ind >= 0; ind --){
        for(int transaction = 2 * k - 1; transaction >= 0; transaction --){
            int profit = 0;
            if(transaction % 2 == 0){
                profit = max(-prices[ind] + dp[ind + 1][transaction + 1], 0 + dp[ind + 1][transaction]);
            }
            else {
                profit = max(prices[ind] + dp[ind + 1][transaction + 1], 0 + dp[ind + 1][transaction]);
            }
            dp[ind][transaction] = profit;
        }
    }
    return dp[0][0];
}

// No need to write base cases beacuse we are already initializing the DP with 0 and our base cases are also returns 0

// TC - O(N * 2k) 
// SC - O(N * 2k)    dp



// Space optimization

int maxProfit4(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int> prev(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);

    for(int ind = n - 1; ind >= 0; ind --){
        for(int transaction = 2 * k - 1; transaction >= 0; transaction --){
            int profit = 0;
            if(transaction % 2 == 0){
                profit = max(-prices[ind] + prev[transaction + 1], 0 + prev[transaction]);
            }
            else {
                profit = max(prices[ind] + prev[transaction + 1], 0 + prev[transaction]);
            }
            curr[transaction] = profit;
        }
        prev = curr;
    }
    return prev[0];
}

// TC - O(N * 2k) 
// SC - O(2k)     prev and curr



// These codes will work for evey case no need to write anything different this will work on every test case


int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2;
    
    cout << maxProfit1(k, prices);

                          
    
}
