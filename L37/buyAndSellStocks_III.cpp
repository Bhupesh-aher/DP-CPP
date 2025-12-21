#include<bits/stdc++.h>
using namespace std;


// at max 2 transactions can be done 
// one transaction means when you buy the stock and sell the stock that is called as one transaction


// Recursion Solution

int f(int ind, int buy, int cap, vector<int> &prices, int n){
    if(cap == 0) return 0;
    if(ind == n) return 0;

    int profit = 0;
    if(buy == 1){                   // this means you can buy the stock
        profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, n),      0 + f(ind + 1, 1, cap, prices,  n));
                            // you buy  the stock                   you did not buy the stock 
    }
    else {                      // this means you have alreay bought stock now you either sell it or keep the stock
        profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, n),            0 + f(ind + 1, 0, cap, prices, n));
    }           // you sell it and now you can buy in next round                 you did not sell so you can't buy in next round

    return profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    return f(0, 1, 2, prices, n);
}

// TC - O(2 ^ N) exponential
// SC - O(N)  Auxillary stack space



// DP Memization

int f1(int ind, int buy, int cap, vector<int> &prices, int n,  vector<vector<vector<int>>> &dp){
    if(cap == 0) return 0;
    if(ind == n) return 0;
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

    int profit = 0;
    if(buy == 1){                   
        profit = max(-prices[ind] + f1(ind + 1, 0, cap, prices, n),  0 + f1(ind + 1, 1, cap, prices,  n));
                                       
    }
    else {                    
        profit = max(prices[ind] + f1(ind + 1, 1, cap - 1, prices, n),  0 + f1(ind + 1, 0, cap, prices, n));
    }           
    return dp[ind][buy][cap] = profit;
}
int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f1(0, 1, 2, prices, n, dp);
}


// TC - O(N * 2 * 3) 
// SC - O(N) + O(N * 2 * 3)     Auxillary stack space  +  dp






// Tabulation 

int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // 1st base case
    for(int ind = 0; ind < n; ind ++){
        for(int buy = 0; buy <= 1; buy ++){
            dp[ind][buy][0] = 0;
        }
    }

    // 2nd base case
    for(int buy = 0; buy <=1; buy++){
        for(int cap = 0; cap <= 2; cap ++){
            dp[n][buy][cap] = 0;
        }
    }

    for(int ind = n - 1; ind >= 0; ind --){
        for(int buy = 0; buy <= 1; buy ++){
            for(int cap = 1; cap <= 2; cap ++){
                int profit = 0;
                if(buy == 1){                   
                    profit = max(-prices[ind] + dp[ind+1][0][cap], 0 + dp[ind + 1][1][cap]);
                                                
                }
                else {                    
                    profit = max(prices[ind] + dp[ind + 1][1][cap - 1],  0 + dp[ind + 1][0][cap]);
                }           
                dp[ind][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}

// TC - O(N * 2 * 3) 
// SC - O(N * 2 * 3)      dp

// even if you don't write base cases for Tabulation still it will give correct ans
// because we are already initilazing the dp with 0
// if base case was returning 1 or something else in that case we would have written base just like how i have wrote it
// still i will keep the base cases as it is for reference and understanding

// that's why in Space optimization i have not written the bases cases 




// Space optimization

int maxProfit3(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> prev(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));


    for(int ind = n - 1; ind >= 0; ind --){
        for(int buy = 0; buy <= 1; buy ++){
            for(int cap = 1; cap <= 2; cap ++){
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
    return prev[1][2];
}

// TC - O(N * 2 * 3) 
// SC - O (6)     prev and curr



// Now there also exist another solution for this question 
// and it has TC - O(N * 4) 

// instead o using buy and cap differently we use just maintain both things using one variable
// Buy sell buy sell - 2 transactions at max we can do as per question 
// 0    1    2   3

// Now we can keep transaction variable and it will have initial value as 0
// and even index means we can buy and odd index means we can sell the stock 
// so that's how TC becomes O(N * 4)
// so i have wrote the Recursion and  DP Memization Solution
// you can convert that into Tabulation and Space optimization as well

// Important - the solution which we discuss till now is best solution and you can give it in interview if this quesgtion is asked
// the second solution which i have discussed is also good you can present that too
// you can choose anything both will be accepetd in interviews
// becasue both solutions are really good



// Recursion Solution - 2nd Approach which we discuss above 

int f2(int ind, int transaction, vector<int> &prices, int n){
    if(transaction == 4) return 0;      // this means we have done 2 transaction completely and reach to 4
    if(ind == n) return 0;

    int profit = 0;
    if(transaction % 2 == 0){          // we can buy as it is even index 
        profit = max(-prices[ind] + f2(ind + 1, transaction + 1, prices, n),   0 + f2(ind + 1, transaction, prices, n));
    }       
    else {                              // we can sell as it is odd index 
        profit = max(prices[ind] + f2(ind + 1, transaction + 1, prices, n),  0 + f2(ind + 1, transaction, prices, n));
    }   
    return profit;
}

int maxProfit4(vector<int>& prices) {
    int n = prices.size();
    return f2(0, 0, prices, n);
}

// TC - O(2 ^ N) exponential
// SC - O(N)  Auxillary stack space




// DP Memization - 2nd Approach which we discuss above 

int f(int ind, int transaction, vector<int> &prices, int n, vector<vector<int>> &dp){
    if(transaction == 4) return 0;      // this means we have done 2 transaction completely and reach to 4
    if(ind == n) return 0;

    if(dp[ind][transaction] != -1) return dp[ind][transaction] ;

    int profit = 0;
    if(transaction % 2 == 0){          // we can buy as it is even index 
        profit = max(-prices[ind] + f(ind + 1, transaction + 1, prices, n, dp),   0 + f(ind + 1, transaction, prices, n, dp));
    }       
    else {                              // we can sell as it is odd index 
        profit = max(prices[ind] + f(ind + 1, transaction + 1, prices, n, dp),  0 + f(ind + 1, transaction, prices, n, dp));
    }   
    return dp[ind][transaction] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(0, 0, prices, n, dp);
}


// TC - O(N * 4) 
// SC - O(N) + O(N * 4)     Auxillary stack space  +  dp





int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    
    cout << maxProfit1(prices);

                          
    
}
