#include<unordered_map>
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i : nums){
            m[i]++;
        }
        for(auto& f : m){
            if(f.second % 2 != 0) return false;
        }
        return true;
    }
};