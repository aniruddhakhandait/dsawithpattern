// given array of value. the combination of valur = target
// figure all | return all the combination

// containg 2 things : 1. dfs 2.Backtracking

# include <bits/stdc++.h>
using namespace std;

class Solution {
    public :
    vector <vector <int> > result;


    // we initializing the dfs method here..
    // step 1 : we used dfs method find each possibility

    void dfs( vector<int>& candidates, int target,int index, vector<int>&current ){

        // found the valid combination
        if (target == 0){
             result.push_back(current);
             return;

        }

        // exceeded target
        if (target < 0)
            return;

      // we use loop here. we check the every single combination with
      // every single value. value - index | current combination | present target

      // Step 2 : build all the combination here
      for (int i = index ; i< candidates.size(); i++){
             current.push_back(candidates[i]);
             dfs(candidates, target - candidates[i],i, current);
             current.pop_back(); // Backtracking


         }


    }
        // Step 3 : start the programe
     vector <vector<int>> combinationsum (vector<int>&candidates, int target){
             vector <int> current;
             dfs(candidates, target, 0 , current );
             return result;


     }

};
   // Step 4 : passing the actual values to it..

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = sol.combinationsum(candidates, target);

    cout << "Combinations:\n";
    for (auto& v : ans) {
        cout << "[ ";
        for (int x : v)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
