#include<bits/stdc++.h>
using namespace std;



int LCS4(int n, int m, string s1, string s2) {
    vector<int> prev(m + 1, 0);

    for(int j = 0; j <= m; j++) prev[j] = 0;

    for(int i = 1; i <= n; i++){
        vector<int> curr(m + 1, 0);
        for(int j = 1; j <= m; j++){
            if(s1[i - 1] == s2[j - 1]){
                curr[j] = 1 + prev[j - 1];
            }

            else curr[j] = 0 + max(curr[j - 1], prev[j]);
        }
        prev = curr;
    }
    return prev[m];
}

int longestPalindromicSubsequence(int n, string s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    int m = s2.size();
    return LCS4(n, m, s1, s2);
}
int minInsertions(string s) {
    int n = s.size();
    int longestStr = longestPalindromicSubsequence(n, s);
    return n - longestStr;
}

int main(){
    
    string s = "mbadm";
    cout << minInsertions(s);

                          
 
}
