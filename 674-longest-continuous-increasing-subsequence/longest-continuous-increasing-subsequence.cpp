class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int r = 1;
        int l = 0;
        int maxl = 1;
        int n = nums.size();
        while( r < n ){
            if(nums[r] <= nums[r-1]){
                l = r;
            }
            int len = r - l + 1;
            maxl = max(len,maxl);
            r++;
        }
        return maxl;
    }
};