#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<vector<int> > > dp(amount+1); 
        sort(coins.begin(), coins.end());
        // building DP 
        for (int i = 1; i <= amount; i++){
            if (i >= coins[0]) {
                for (auto& c : coins){
                    if (i-c>=0 && dp[i-c].size() > 0){
                        for (auto& v: dp[i-c]){
                            if (v.empty()){
                                dp[i].push_back({i}); 
                            }
                            else {
                                if (i >= v.back()){
                                    vector<int> tmp = v; 
                                    v.push_back(i); 
                                    dp[i].push_back(v); 
                                }
                            }
                        } 
                    }
                }
            }
        }
        return dp.back().size(); 
    }
};
int main()
{
    Solution s;
    vector<int> v; 
    v.push_back(1);
    v.push_back(2);
    v.push_back(5); 
    s.change(5, v); 

    return 0;
}
