#include<set>
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        bool all_neg = true;
        int max = nums[0];
        set<int> s;
        int sum = 0;

        for(int i = 0; i<n ;i++){
            if(s.find(nums[i]) != s.end()){
                continue;
            }
            if(nums[i] > max) max = nums[i];
            s.insert(nums[i]);
            if(nums[i]>0){
                all_neg = false;
                sum += nums[i];
            }
        }
        if(all_neg) return max;
        return sum;
    }
};