class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m;

        while(l<=h){
            m = (l+h)/2;
            if(nums[m] == target){
                return m;
            }
            if(nums[m] > target){
                //go to left
                h = m-1;
            }
            else{
                //go to rigth
                l = m+1;
            }
        }
        //cout<<l<<h<<m;
        if(nums[m] > target) return m;
        return m+1;
    }
};