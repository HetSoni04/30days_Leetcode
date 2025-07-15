class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        int nums_size = nums.size();
        //vector<int> v(nums_size);
        int i = 0;
        int j = nums_size-1;
        while(i<j){
            if(nums[i]%2 != 0 && nums[j]%2 == 0){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
            if(nums[i]%2 == 0 && nums[j]%2 == 0){
                j++;
            }
            if(nums[i]%2 != 0 && nums[j]%2 != 0){
                i--;
            }
            i++;
            j--;
        }
        return nums;
    }
};