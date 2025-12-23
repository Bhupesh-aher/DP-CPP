#include<bits/stdc++.h>
using namespace std;


// Cooldown - means you cannot buy the stock right after sell
// this means right after selling the stock next day you can't buy stock after that day you can but stock
// You can buy and sell the stock as many times as you want (DP - 36)

// for example - [4, 9, 0, 4, 10]
            //    0  1  2  3  4         index

// if buy at index 0 and sell at index 1 then i can't buy on index 2 
// i can buy at 3rd index 



// Important -

// so we just need to change in the DP - 36 code in sell condition 
// inseatd of ind + 1 we will do ind + 2
// and will do slight chnage in the base case as we are going ind + 2 in sell condition
// instead of ind == n we will write ind >= n





// Recursion Solution

int f(int ind, int buy, vector<int>& prices, int n){
    if(ind >= n) return 0;

    int profit = 0;
    if(buy == 1){
        profit = max(-prices[ind] + f(ind + 1, 0, prices, n), 0 + f(ind + 1, 1, prices, n));
    }
    else {
        profit = max(prices[ind] + f(ind + 2, 1, prices, n), 0 + f(ind + 1, 0, prices, n));
    }                            // here we did the change 
    return profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return f(0, 1, prices, n);
}

// TC - O(2 ^ N) exponential
// SC - O(N)  Auxillary stack space



// DP Memization

int f1(int ind, int buy, vector<int> &prices, int n, vector<vector<int>> &dp){
    if(ind >= n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy == 1){                   // this means you can buy the stock
        profit = max(-prices[ind] + f1(ind + 1, 0, prices, n, dp),      0 + f1(ind + 1, 1, prices, n, dp));
                            // you buy  the stock                   you did not buy the stock 
    }
    else {
        profit = max(prices[ind] + f1(ind + 2, 1, prices, n, dp),       0 + f1(ind + 1, 0, prices, n, dp));
    }           // you sell it and now you can buy in next round    you did not sell so you can't buy in next round
    return dp[ind][buy] = profit;
}

int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f1(0, 1, prices, n, dp);
}


// TC - O(N * 2) 
// SC - O(N) + O(N * 2)     Auxillary stack space  +  dp



// Because base case is returning 0 and we initialize the DP with 0. so no need to write base case




// Tabulation 

int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for(int ind = n - 1; ind >= 0; ind --){
        for(int buy = 0; buy <= 1; buy ++){
            int profit = 0;
            if(buy == 1){
                profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
            }
            else {
                profit = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
            }
        }
    return dp[0][1];
}

// TC - O(N * 2) 
// SC - O(N * 2)      dp




// We will not do space optimizatation
// because in problems we solve in DP series we carrry 2 arrays 
// but in this because we are doing ind + 2 
// we will need 3 arrays for space optimization, and that's not good solution so that's why will not do space optimizatation




// You can do one thing which is you can remove the inner buy for loop 
// because one time if is executing and one time else condition is executing 


int maxProfit3(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for(int ind = n - 1; ind >= 0; ind --){
        dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        
        dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);         
    }
    return dp[0][1];
}

// TC - O(N) 
// SC - O(N * 2)      dp


// and Now you can do the space optimization by carriying 3 arrays of size 2

int maxProfit4(vector<int>& prices) {
    int n = prices.size();
    vector<int> prev1(2, 0);
    vector<int> prev2(2, 0);
    vector<int> curr(2, 0);

    for(int ind = n - 1; ind >= 0; ind --){
        curr[1] = max(-prices[ind] + prev1[0], 0 + prev1[1]);
        
        curr[0] = max(prices[ind] + prev2[1], 0 + prev1[0]);  

        prev2 = prev1;
        prev1 = curr;       
    }
    return prev1[1];
}


// TC - O(N) 
// SC - O(6)      dp

int main(){
    vector<int> prices = {4, 9, 0, 4, 10};
    
    cout << maxProfit1(prices);

                          
    
}
