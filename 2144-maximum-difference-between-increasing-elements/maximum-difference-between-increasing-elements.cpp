class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max = -1;
        int min = nums[0];
        int s = nums.size();
        for(int i = 1; i<s ;i++){
            if(min > nums[i]){
                min = nums[i];
            }else{
                if(min!=nums[i] && max < (nums[i]-min)){
                    max = nums[i] - min;
                }
            }
        }
        return max;
    }
};