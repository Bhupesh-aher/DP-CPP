#include<bits/stdc++.h>
using namespace std;

// Recursion Solution

int f(int i, int j, string s, string t){
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(s[i] == t[j]){
        return f(i-1, j-1, s, t) + f(i-1, j, s, t);
    }
    return f(i-1, j, s, t);
}
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    return f(n-1, m-1, s, t);
}

// TC - O(2 ^ N * 2 ^ M)        exponential
// SC - O(N + M)  Auxillary stack space



// DP Memization

int f1(int i, int j, string s, string t, vector<vector<int>> &dp){
    if(j < 0) return 1;
    if(i < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]){
        return dp[i][j] = f1(i-1, j-1, s, t, dp) + f1(i-1, j, s, t, dp);
    }
    return dp[i][j] = f1(i-1, j, s, t, dp);
}

int numDistinct1(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n-1, m-1, s, t, dp);
}


// TC - O(N * M) 
// SC - O(N + M) + O(N * M)     Auxillary stack space  +  dp






// Now if we try to write base case for tabulation we can't write like this dp[-1][somehting]
// because we can't acceess the negative index
// so to do change we will do shifting on index
// that means will shift index by one on the right side
// f(1) means f(0), f(n) means f(n-1) and f(-1) means f(0)
// so that's how we can easily write the base case
// base case will be 
// if(i == 0) return 0;
// if(j == 0) return 0;

// i have write the Memization code again just to understand the shifting index logic and code
// only change is in the base case and first if condition when both string chars are mathced or not
// other than that everything remains exactly same
// remember there is no need of shifting index in recursion and Memization, but we need to do in tabulation
// but just to show how we can do it i have done in the Memization as well in below code  (LCS2 f2)


// DP Memization - After index shifting by one on right side


int f2(int i, int j, string s, string t, vector<vector<int>> &dp){
    if(j == 0) return 1;
    if(i == 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i-1] == t[j-1]){
        return dp[i][j] = f2(i-1, j-1, s, t, dp) + f2(i-1, j, s, t, dp);
    }
    return dp[i][j] = f2(i-1, j, s, t, dp);
}
int numDistinct2(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, s, t, dp);
}


// Tabulation 

int numDistinct3(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));

    for(int i = 0; i <=n; i++) dp[i][0] = 1;
    for(int j = 1; j <=m; j++) dp[0][j] = 0;                // You remove this line if you want beacuse we are already initialize the dp with 0

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return (int)dp[n][m];
}

// TC - O(N * M) 
// SC - O(N * M)      dp



// Space optimization

int numDistinct4(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double> prev(m + 1, 0), curr(m + 1, 0);

    prev[0] = 1;
    curr[0] = 1;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            if(s[i-1] == t[j-1]){
                curr[j] = prev[j-1] + prev[j];
            }
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return (int)prev[m];
}


// TC - O(N * M) 
// SC - O 2(N)     prev and curr



// Space optimization - Single Array Space Optimised 

int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double> prev(m + 1, 0);

    prev[0] = 1;

    for(int i = 1; i <=n; i++){
        for(int j = m; j >=1; j--){
            if(s[i-1] == t[j-1]){
                prev[j] = prev[j-1] + prev[j];
            }
        }
    }
    return (int)prev[m];
}


// TC - O(N * W) 
// SC - O(W)     prev 


int main(){
    string s = "babgbag";
    string t = "bag";
    
    cout << numDistinct1(s, t);

                          
    
}
