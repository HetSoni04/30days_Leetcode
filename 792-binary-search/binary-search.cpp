class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1){
            return -1;
        }
        int l,h;
        l = 0;
        h = nums.size()-1;
        int m;
        while(l!=h && h>=0 && l>=0){
            m = (l+h)/2;
            if(nums[m] == target){
                return m;
            }
            if(nums[m] > target){
                //go  to left
                h = m-1;
            }
            else{
                //go to right
                l = m+1;
            }
        }
        
        if(nums[l] == target){
            return l;
        }
        return -1;
    }
};