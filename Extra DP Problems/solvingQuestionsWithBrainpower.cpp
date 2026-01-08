#include<bits/stdc++.h>
using namespace std;



// Recursion Solution


int f(int ind, vector<vector<int>>& questions, int n){
    if(ind == n - 1) return questions[ind][0];
    if(ind >= n) return 0;

    int take = questions[ind][0] + f(ind + questions[ind][1] + 1, questions, n);
    int notTake = 0 +f(ind + 1, questions, n);
    return max(take, notTake);
}
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();
    return f(0, questions, n);
}

// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space




// DP Memization


 long long f1(int ind, vector<vector<int>>& questions, vector<long long> &dp, int n){
    if(ind == n - 1) return questions[ind][0];
    if(ind >= n) return 0;

    if(dp[ind] != -1) return dp[ind];

    long long take = questions[ind][0] + f1(ind + questions[ind][1] + 1, questions, dp, n);
    long long notTake = 0 + f1(ind + 1, questions, dp, n);
    return dp[ind] = max(take, notTake);
}
long long mostPoints1(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n, - 1);
    return f1(0, questions, dp, n);
}


// TC - O(N) 
// SC - O(N) + O(N)     Auxillary stack space  +  dp




// Tabulation 

long long mostPoints2(vector<vector<int>>& questions) {
    int n = questions.size();
    vector<long long> dp(n, 0);
    dp[n-1] = questions[n-1][0];

    for(int ind = n - 2; ind >= 0; ind--){
        long long take = questions[ind][0];
        if(ind + questions[ind][1] + 1 < n) take += dp[ind + questions[ind][1] + 1];
        long long notTake = 0 + dp[ind + 1];
        dp[ind] = max(take, notTake);
    }
    return dp[0];
}

// TC - O(N) 
// SC - O(N)     dp



int main(){
    
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    cout << mostPoints(questions);

                          
 
}
