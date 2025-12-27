#include<bits/stdc++.h>
using namespace std;


// We are going to use the approach which we disucss in the DP - 42 
// that same code we will use here and will do small change and we can easily get the longest chain


bool checkPossible(string &s1, string &s2){    // s1 here is greater string and s2 is smaller string
    if(s1.size() != s2.size() + 1) return false;
    int first = 0;
    int second = 0;
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else {
            first ++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

static bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStrChain(vector<string>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    sort(nums.begin(), nums.end(), comp); 

    int maxi = 0;
    for(int ind = 0; ind < n; ind ++){
        for(int prev = 0; prev < ind; prev ++){
            if(checkPossible(nums[ind], nums[prev]) && 1 + dp[prev] > dp[ind]){
                dp[ind] = 1 + dp[prev];
            }
        }
        if(dp[ind] > maxi){
            maxi = dp[ind];
        }
    }
    return maxi;
}


// TC - O(N * N) + O(max length of the string)    + O(N log N)        
// SC - O (N)    dp



int main(){
    vector<string> nums = {"a","b","ba","bca","bda","bdca"};
    
    cout << longestStrChain(nums);


                          
    
}
