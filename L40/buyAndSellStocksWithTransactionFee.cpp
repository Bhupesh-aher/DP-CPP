#include<bits/stdc++.h>
using namespace std;


// Transaction fee means you after every transaction means (buy and sell) whatver profit you will make 
// you have to pay fee for that

// You can buy and sell as many times as you want just like we did in (DP - 36)

// [1, 3, 2, 8, 4, 9] and fee = 2
//  0  1  2  3  4  5
// if you Buy at index 0 and Sell at index 3, then profit is 8 - 1 = 7
// and if you buy again at 4 and sell at index 5 then profit = 9 - 4 = 5
// and as you did 2 transaction so fee will 2 * 2 = 4
// The ans will be 7 + 5 - 4 = 12 - 4 = 8
// 8 will be the answer for this case 

// Will use same code (DP - 36) and just small one fee variable which we need to add and everything else remains same
// that's how we can easily solve this problem 

// Now we have to do - fee, you have 2 option you can choose any one
// 1. when buying stock at that time do - fee
// 2. or when you sell the stock at that time yoy can do - fee
// you can choose any option and both will give correct answer
// what matters is as long as you are paying it once that on buy and sell it should be absolutly right 





// Recursion Solution

int f(int ind, int buy, vector<int> &prices, int n){
    if(ind == n) return 0;

    int profit = 0;
    if(buy == 1){                   // this means you can buy the stock
        profit = max(-prices[ind] + f(ind + 1, 0, prices, n, fee),      0 + f(ind + 1, 1, prices, n, fee));
                            // you buy  the stock                   you did not buy the stock 
    }
    else {                      // this means you have alreay bought stock now you either sell it or keep the stock
        profit = max(prices[ind] - fee + f(ind + 1, 1, prices, n, fee),            0 + f(ind + 1, 0, prices, n, fee));
    }           // you sell it and now you can buy in next round    you did not sell so you can't buy in next round
    return profit;
}
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    return f(0, 1, prices, n, fee);
}

// TC - O(2 ^ N) exponential
// SC - O(N)  Auxillary stack space



// DP Memization

int f1(int ind, int buy, vector<int> &prices, int n, int fee, vector<vector<int>> &dp){
    if(ind == n) return 0;
    int profit = 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    if(buy == 1){
        profit = max(-prices[ind] + f1(ind + 1, 0, prices, n, fee, dp),  0 + f1(ind + 1, 1, prices, n, fee, dp));
    }
    else {
        profit = max(prices[ind] - fee + f1(ind + 1, 1, prices, n, fee, dp), 0 + f1(ind + 1, 0, prices, n, fee, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit1(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, n, fee, dp);
}


// TC - O(N * 2) 
// SC - O(N) + O(N * 2)     Auxillary stack space  +  dp



// I have not write the base cases for Tabulation and space optimization
// beacuse we are already initializing the DP with 0 and our base case also return 0
// that's why even if we don't write base case the code will work absolutly right


// Tabulation 

int maxProfit2(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int ind = n - 1; ind>=0; ind--){
        for(int buy = 0; buy <= 1; buy ++){
            int profit = 0;
            if(buy == 1){
                profit = max(-prices[ind] + dp[ind+1][0],  0 + dp[ind+1][1]);
            }
            else {
                profit = max(prices[ind] - fee + dp[ind+1][1], 0 + dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// TC - O(N * 2) 
// SC - O(N * 2)      dp




// Space optimization

int maxProfit3(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> prev(2, 0);
    vector<int> curr(2, 0);

    for(int ind = n - 1; ind>=0; ind--){
        for(int buy = 0; buy <= 1; buy ++){
            int profit = 0;
            if(buy == 1){
                profit = max(-prices[ind] + prev[0],  0 + prev[1]);
            }
            else {
                profit = max(prices[ind] - fee + prev[1], 0 + prev[0]);
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
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    
    cout << maxProfit(prices, fee);

                          
    
}
