#include<bits/stdc++.h>
using namespace std;

// Recursion Solution

int f(int i, int j, string s, string t){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(s[i] == t[j]) {
        return 0 + f(i - 1, j - 1, s, t);
    }             // delete                   // insert               replace
    return 1 + min(f(i - 1, j, s, t), min(f(i, j - 1, s, t), f(i - 1, j - 1, s, t)));
}
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    return f(n - 1, m - 1, word1, word2);
}

// TC - exponential
// SC - O(N + M)  Auxillary stack space



// DP Memization

int f1(int i, int j, string s, string t, vector<vector<int>> &dp){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) {
        return dp[i][j] = 0 + f1(i - 1, j - 1, s, t, dp);
    }             // delete                   // insert               replace
    return dp[i][j] = 1 + min(f1(i - 1, j, s, t, dp), min(f1(i, j - 1, s, t, dp), f1(i - 1, j - 1, s, t, dp)));
}
int minDistance1(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n - 1, m - 1, word1, word2, dp);
}


// if you wamt to you can write line 37 in more readble way, like this - 

// int insertion = 1 + f(i, j - 1, s, t, dp);
// int deletion = 1 + f(i - 1, j, s, t, dp);
// int replace  = 1 + f(i - 1, j - 1, s, t, dp);
// return dp[i][j] = min(insertion, min(deletion, replace));



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
    if(i == 0) return j;
    if(j == 0) return i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i - 1] == t[j - 1]) {
        return dp[i][j] = 0 + f2(i - 1, j - 1, s, t, dp);
    }                           // delete                   // insert               replace
    return dp[i][j] = 1 + min(f2(i - 1, j, s, t, dp), min(f2(i, j - 1, s, t, dp), f2(i - 1, j - 1, s, t, dp)));
}
int minDistance2(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, word1, word2, dp);
}


// Tabulation 

int minDistance3(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int j = 0; j <= m; j++) dp[0][j] = j;
    for(int i = 0; i <=n; i++) dp[i][0] = i;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <=m; j++){
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = 0 + dp[i-1][j-1];
            }                           // delete                   // insert               replace
            else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}

// TC - O(N * M) 
// SC - O(N * M)      dp



// Space optimization

int minDistance4(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for(int j = 0; j <= m; j++) prev[j] = j;
    

    for(int i = 1; i <=n; i++){
        curr[0] = i;
        for(int j = 1; j <=m; j++){
            if(s[i - 1] == t[j - 1]) {
                curr[j] = prev[j-1];
            }                           // delete                   // insert               replace
            else curr[j] = 1 + min(prev[j], min(curr[j-1], prev[j-1]));
        }
        prev = curr;
    }
    return prev[m];
}


// TC - O(N * M) 
// SC - O 2(N)     prev and curr




int main(){
    string word1 = "horse";
    string word2 = "ros";
    
    cout << minDistance(word1, word2);

                          
    
}
