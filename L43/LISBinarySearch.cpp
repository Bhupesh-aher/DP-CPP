#include<bits/stdc++.h>
using namespace std;


// We have already done LIS in DP - 41, 42 
// Here we are finding the LIS  using binary serach
// now using binary search you can only get the length only.
// we cannot genrat the LIS we can just get the length of LIS


// Tabulation 


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    int len = 1;
    temp.push_back(nums[0]);

    for(int i = 1; i < n; i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
            len ++;
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len; 
}

// The temp array at the does not contain the LIS it just gives the length of the LIS 

// TC - O(N log N) 
// SC - O(N)      




int main(){
    vector<int> nums = {1, 7, 8, 4, 5, 6, -1, 9};
    
    cout << lengthOfLIS(nums);


                          
    
}
