#include<bits/stdc++.h>
using namespace std;



// Recrusion Solution
// ind = day
int f(int day, int last, vector<vector<int>> &matrix){
    if(day == 0){
        int maxi = 0;
        for(int i = 0; i <=2; i++){
            if(i != last){
                maxi = max(maxi, matrix[0][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for(int i = 0; i <= 2; i++){
        if(i != last){
            int points = matrix[day][i] + f(day - 1, i, matrix);
            maxi = max(maxi, points);
        }
    }
    return maxi;
}


int ninjaTraining(vector<vector<int>>& matrix) {
    int n = matrix.size();
    return f(n - 1, 3, matrix);
}

// TC - O(N ^ 2) 
// SC - O(N) + O(N)



// DP Memization

int f1(int day, int last, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task <=2; task++){
            if(task != last){
                maxi = max(maxi, matrix[day][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];

    int maxi = 0;
    for(int task = 0; task <= 2; task++){
        if(task != last){
            int points = matrix[day][task] + f1(day - 1, task, matrix, dp);
            maxi = max(maxi, points);
        }
    }
    return dp[day][last] = maxi;
}


int ninjaTraining1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f1(n - 1, 3, matrix, dp);
}

// TC - O(N * 4) * 3
// SC - O(N * 4) + O(N)         Auxillary stack space + DP heightsay 



// Tabulation 


int ninjaTraining2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
   
    dp[0][0] = max(matrix[0][1], matrix[0][2]);
    dp[0][1] = max(matrix[0][0], matrix[0][2]);
    dp[0][2] = max(matrix[0][0], matrix[0][1]);
    dp[0][3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

    for(int day = 1; day < n; day ++){
        for(int last = 0; last <=3; last ++){
            dp[day][last] = 0;
            int maxi = 0;
            for(int task = 0; task <=2; task ++){
                if(task != last){
                    int points = matrix[day][task] + dp[day - 1][task];
                    maxi = max(maxi, points);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n-1][3];
}

// TC - O(N * 4) * 3
// SC - O(N * 4)




// Space Optimization 


int ninjaTraining3(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev(4, 0);
   
    prev[0] = max(matrix[0][1], matrix[0][2]);
    prev[1] = max(matrix[0][0], matrix[0][2]);
    prev[2] = max(matrix[0][0], matrix[0][1]);
    prev[3] = max(matrix[0][0], max(matrix[0][1], matrix[0][2]));

    for(int day = 1; day < n; day ++){
        vector<int> temp(4, 0);
        for(int last = 0; last <=3; last ++){
            temp[last] = 0;

            for(int task = 0; task <=2; task++){
                if(task != last){
                    temp[last] = max(temp[last], matrix[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

// TC - O(N * 4) * 3
// SC - O(4)



int main(){
    vector<vector<int>> matrix = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    
    cout << ninjaTraining3(matrix);                           
 
}
