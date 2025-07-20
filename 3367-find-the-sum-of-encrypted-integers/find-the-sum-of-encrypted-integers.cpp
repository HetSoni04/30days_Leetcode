class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int nums_size = nums.size();
        int sum = 0;
        for(int i = 0; i<nums_size; i++){
            if(nums[i] == 0) continue;
            sum +=encrypt(nums[i]);
        }
        return sum;
    }
    int encrypt(int n){
        int max = 0;
        int  i = 1;
        int result = 1;;
        while(n>0){
            int t = n%10;
            if(max < t) max = t;
            n /= 10;
            result += pow(10,i);
            i++;
        }
        result -= pow(10,--i);
        cout<<result<<endl;
        return result*max;
    }
};