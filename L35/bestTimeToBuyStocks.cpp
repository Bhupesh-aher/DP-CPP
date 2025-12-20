#include<bits/stdc++.h>
using namespace std;




int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int mini = prices[0];

    for(int i = 1; i<prices.size(); i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

// TC - O(N) 
// SC - O(1)



int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    cout << maxProfit(prices);

                          
    
}
