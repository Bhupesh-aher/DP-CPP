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
    return f(0, 0, rides);
}


// TC - O(2 ^ N) 
// SC - O(N)  Auxillary stack space






int main(){
    
    int n = 20;
    vector<vector<int>> rides = {{1,6,1},{3,10,2},{10,12,3},{11,12,2},{12,15,2},{13,18,1}};
    cout << maxTaxiEarnings(n, rides);

                          
 
}
