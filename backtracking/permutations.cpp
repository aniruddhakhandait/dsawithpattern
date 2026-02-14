// return all the permutation and combination of given array
// [1,2,3 ] return all the combination
// all include 4 steps : 1. specify the method  2. start the loop  3.express it  4. pass the example to it
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public : vector<vector<int>> result;

    // numbers | used formation | path
    // step 1 : specify method
    void backtrack (vector<int>&nums, vector<bool> &used, vector<int>&path){

    // Base case | condition
    if (path.size() == nums.size()){
          result.push_back(path);
          return;
    }

     // loop formation
    // step 2 : build a loop and find out combination
    for (int i = 0 ; i < nums.size() ; i++){
        if (used[i]) continue;

        used[i] = true;

        // It simply means take a 1 value : build all the composition
        // drop that value and take a 2 nd value

        path.push_back(nums[i]);

        backtrack(nums,used,path);

        path.pop_back();

        used[i]= false;

    }

    }
    // step 3 :
    vector<vector<int>>permute(vector<int>& nums){
        // step by step
          vector<bool> used(nums.size(), false);
          vector<int> path;
          backtrack(nums,used,path);
          return result;
    }


};
// step 4 : passing an example
int main() {
    Solution sol;
    vector<int> nums = { 1, 2, 3};

    vector<vector<int>> ans = sol.permute(nums);

    for (auto& perm : ans) {
        cout << "[ ";
        for (int x : perm)
            cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
