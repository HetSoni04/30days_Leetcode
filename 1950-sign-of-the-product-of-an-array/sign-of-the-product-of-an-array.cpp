class Solution {
public:
    int arraySign(vector<int>& nums) {
        int s = nums.size();
        int p = 1;
        for(int i = 0; i<s ; i++){
            if(nums[i] < 0){
                p *= (-1);
            }
            if(nums[i] == 0) return 0;
        }
        return p;
    }
};