#include<unordered_map>
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // unordered_map<int,int> m;
        // for(auto i : nums){
        //     m[i]++;
        // }
        // for(auto& f : m){
        //     if(f.second % 2 != 0) return false;
        // }
        // return true;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        bool result = true;
        for(int i = 0; i<n ;i+=2){
            if(i+1>=n || nums[i+1] != nums[i] ){
                result = !result;
                break;
            } 
        }
        return result;
    }
};