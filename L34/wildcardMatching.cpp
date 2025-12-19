#include<bits/stdc++.h>
using namespace std;

// Recursion Solution

bool f(int i, int j, string &pattern, string &text){
    if(i < 0 && j < 0) return true;
    if(i < 0 && j >= 0) return false;
    if(j < 0 && i >= 0) {
        for(int ind = 0; ind <= i; ind++){
            if(pattern[ind] != '*') return false;
        }
        return true;
    }

    if(pattern[i] == text[j] || pattern[i] == '?'){
        return f(i - 1, j - 1, pattern, text);
    }
    if(pattern[i] == '*'){
        return f(i - 1, j, pattern, text) | f(i, j - 1, pattern, text);
    }
    return false;
}

bool isMatch(string pattern, string text) {
    int n = pattern.size();
    int m = text.size();
    return f(n - 1, m - 1, pattern, text);
}

// TC - exponential
// SC - O(N + M)  Auxillary stack space



// DP Memization

 bool f1(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
    if(i < 0 && j < 0) return true;
    if(i < 0 && j >= 0) return false;
    if(j < 0 && i >= 0) {
        for(int ind = 0; ind <= i; ind++){
            if(pattern[ind] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(pattern[i] == text[j] || pattern[i] == '?'){
        return dp[i][j] = f1(i - 1, j - 1, pattern, text, dp);
    }
    if(pattern[i] == '*'){
        return dp[i][j] = f1(i - 1, j, pattern, text, dp) | f1(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}

bool isMatch1(string pattern, string text) {
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f1(n - 1, m - 1, pattern, text, dp);
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

bool f2(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
    if(i == 0 && j == 0) return true;
    if(i == 0 && j > 0) return false;
    if(j == 0 && i > 0) {
        for(int ind = 1; ind <= i; ind++){
            if(pattern[ind - 1] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?'){
        return dp[i][j] = f2(i - 1, j - 1, pattern, text, dp);
    }
    if(pattern[i - 1] == '*'){
        return dp[i][j] = f2(i - 1, j, pattern, text, dp) | f2(i, j - 1, pattern, text, dp);
    }
    return dp[i][j] = false;
}

bool isMatch2(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f2(n, m, pattern, text, dp);
}




int main(){
    string pattern = "ab*cd";
    string text = "abdefcd";
    
    cout << isMatch1(pattern, text);

                          
    
}
