#include<bits/stdc++.h>
using namespace std;


// This is the prerequisite for this problem to solve as it is exaclty same 
// stack and queue L12 - Largest Rectangle in Histrogram 

// why this comes under DP as well
// because we are storing the values in height from last rows from matrix in maximalRectangle()


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> st;
    for(int i = 0; i<= n; i++){
        
        while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
            int height = heights[st.top()];
            st.pop();
            int width;
            if(st.empty()){
                width = i;
            }
            else {
                width = i - st.top() - 1;
                maxArea = max(maxArea, width * height);
            }
        }
        st.push(i);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int maxArea = 0;
    vector<int> height(m, 0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 1) height[j] ++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
}


// TC - exponential
// SC - O(N)  Auxillary stack space





int main(){

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };
    
    cout << maximalRectangle(mat);
}
