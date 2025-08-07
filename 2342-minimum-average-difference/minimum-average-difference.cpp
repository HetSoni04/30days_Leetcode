class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        if(nums.size() == 1) 0;
        int s = nums.size();
        vector<long int> n;
        n.push_back(nums[0]);
        for(int i = 1; i<s; i++){
            n.push_back(n[i-1] + nums[i]);
        }
        // for(auto a : n){
        //     cout<<a<<" ";
        // }cout<<endl;
        int min = INT_MAX;
        int in = -1;
        for(int i = 0; i<(s-1) ; i++){
            int t1 = n[i]/(i+1);
            int t2 = (n[s-1]-n[i])/(s-i-1);
            int  t = abs((t1-t2));
            if(t < min){
                min = t;
                in = i;
            }
            if(t == 0) return i;
            //cout<<t1<<" "<<t2<<" "<<t<<endl;
        }
        if(min > (n[s-1]/s)) return s-1;
        return in;
    }
};