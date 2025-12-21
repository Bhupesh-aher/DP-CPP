#include<bits/stdc++.h>
using namespace std;



// You can buy an sell as many times as you want 

// if buy == 1 means you can buy the stock on that index 
// if buy == 0 means you have already bought the stock now you have 2 choices either sell it or don't sell it 
// and if you sell than in next index you can buy again


// Recursion Solution

int f(int ind, int buy, vector<int> &prices, int n){
    if(ind == n) return 0;

    int profit = 0;
    if(buy == 1){                   // this means you can buy the stock
        profit = max(-prices[ind] + f(ind + 1, 0, prices, n),      0 + f(ind + 1, 1, prices, n));
                            // you buy  the stock                   you did not buy the stock 
    }
    else {                      // this means you have alreay bought stock now you either sell it or keep the stock
        profit = max(prices[ind] + f(ind + 1, 1, prices, n),            0 + f(ind + 1, 0, prices, n));
    }           // you sell it and now you can buy in next round    you did not sell so you can't buy in next round
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
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    int profit = 0;
    if(buy == 1){                   // this means you can buy the stock
        profit = max(-prices[ind] + f1(ind + 1, 0, prices, n, dp),      0 + f1(ind + 1, 1, prices, n, dp));
                            // you buy  the stock                   you did not buy the stock 
    }
    else {
        profit = max(prices[ind] + f1(ind + 1, 1, prices, n, dp),       0 + f1(ind + 1, 0, prices, n, dp));
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






// Tabulation 

int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int ind = n -1; ind >= 0; ind--){
        for(int buy = 0; buy <=1; buy ++){
            int profit = 0;
                if(buy == 1){                  
                    profit = max(-prices[ind] +dp[ind + 1][0], 0 + dp[ind + 1][1]);
        
                }
                else {
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind + 1][0]);
                }           
                dp[ind][buy] = profit;
        }
    }

    return dp[0][1];
}

// TC - O(N * 2) 
// SC - O(N * 2)      dp




// Space optimization

int maxProfit3(vector<int>& prices) {
    int n = prices.size();
    vector<int> prev(2, 0), curr(2, 0);

    prev[0] = 0;
    prev[1] = 0;

    for(int ind = n -1; ind >= 0; ind--){
        for(int buy = 0; buy <=1; buy ++){
            int profit = 0;
                if(buy == 1){                  
                    profit = max(-prices[ind] + prev[0], 0 + prev[1]);
        
                }
                else {
                    profit = max(prices[ind] + prev[1], 0 + prev[0]);
                }           
                curr[buy] = profit;
        }
        prev = curr;
    }

    return prev[1];
}

// TC - O(N * 2) 
// SC - O (4)     prev and curr





int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    cout << maxProfit1(prices);

                          
    
}
