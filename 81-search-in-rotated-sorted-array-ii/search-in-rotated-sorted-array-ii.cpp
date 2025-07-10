class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return false; 
        if(len == 1){
            if(nums[0] == target) return true;
            return false;
        }
        for(int i = 0;i<len;i++){
            if(nums[i] == target) {            
                return true;
            }
            if((i+1) <len){
                if(nums[i] > nums[i+1]){
                    //found pivot point
                    if(target > nums[i]){
                        return false;
                    }
                }
            }
            
        }   
        return false;
    }
};