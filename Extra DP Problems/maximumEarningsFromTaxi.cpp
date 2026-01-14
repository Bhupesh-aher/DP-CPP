#include<bits/stdc++.h>
using namespace std;



// Recursion Solution


int f(int ind, int lastTime, vector<vector<int>> &rides){
    if(ind == rides.size()) return 0;
    
    int performJob = 0;
    int startTime = rides[ind][0];
    if(startTime >= lastTime){
        performJob = rides[ind][1] - rides[ind][0] + rides[ind][2] + f(ind + 1, rides[ind][1], rides);
    }
    int notPerformJob = 0 + f(ind + 1, lastTime, rides);
    return max(performJob, notPerformJob);

}
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    return f(0, 0, rides);
}


// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space




// DP Memization


int f1(int ind, int lastTime, vector<vector<int>> &rides, vector<int> &dp){
    if(ind == rides.size()) return 0;
    if(dp[lastTime] != -1) return dp[lastTime];
    
    int performJob = 0;
    int startTime = rides[ind][0];
    if(startTime >= lastTime){
        performJob = rides[ind][1] - rides[ind][0] + rides[ind][2] + f1(ind + 1, rides[ind][1], rides, dp);
    }
    int notPerformJob = 0 + f1(ind + 1, lastTime, rides, dp);
    return dp[lastTime] = max(performJob, notPerformJob);

}
long long maxTaxiEarnings1(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    vector<int> dp(n + 1, -1);
    return f(0, 0, rides, dp);
}


// TC - O(N) 
// SC - O(N) + O(N)     Auxillary stack space  +  dp




// DP Memization + Binary Search 

long long f(int ind, int lastTime, vector<vector<int>> &rides, vector<long long> &dp){
    if(ind == rides.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
        
    long long notPerformJob = 0 + f(ind + 1, lastTime, rides, dp);
    long long performJob = 0;
    int startTime = rides[ind][0];
    int ans = rides.size();
    int low = ind + 1;
    int high = rides.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(rides[mid][0] >= rides[ind][1]){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    
    performJob = rides[ind][1] - rides[ind][0] + rides[ind][2] + f(ans, rides[ind][1], rides, dp);


    return dp[ind] = max(performJob, notPerformJob);

}
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    vector<long long> dp(rides.size(), -1);
    return f(0, 0, rides, dp);
}



// This solution below is same as above 
// as we are not using lastTime in above code we are just passing it
// in below code i removed that paramater 
// that's the only change

long long f(int ind, vector<vector<int>> &rides, vector<long long> &dp){
    if(ind == rides.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
        
    long long notPerformJob = 0 + f(ind + 1, rides, dp);
    long long performJob = 0;
    int startTime = rides[ind][0];
    int ans = rides.size();
    int low = ind + 1;
    int high = rides.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(rides[mid][0] >= rides[ind][1]){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    
    performJob = rides[ind][1] - rides[ind][0] + rides[ind][2] + f(ans, rides, dp);


    return dp[ind] = max(performJob, notPerformJob);

}
public:
long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    sort(rides.begin(), rides.end());
    vector<long long> dp(rides.size(), -1);
    return f(0, rides, dp);
}



int main(){
    
    int n = 20;
    vector<vector<int>> rides = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}};
    cout << maxTaxiEarnings(n, rides);

                          
 
}
