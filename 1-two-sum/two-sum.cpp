class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = nums.size();
        vector<int> res;
        // for(int i=0;i<s;i++){
        //     for(int j=i+1;j<s;j++){
        //         if((nums[i]+nums[j]) == target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }

        //two pointer's approach --> O(nlogn) -- pair + sort + twopointers
        // vector<pair<int,int>> arr;
        // for(int i = 0; i<s ;i++){
        //     arr.push_back({nums[i],i});
        // }
        // sort(arr.begin(),arr.end());
        // int left = 0;
        // int right = s-1;    
        // while(left < right){
        //     int sum = arr[left].first + arr[right].first;
        //     if(sum == target){
        //         res.push_back(arr[left].second);
        //         res.push_back(arr[right].second);
        //         break;
        //     }
        //     else if(sum < target){
        //         left++;
        //     } 
        //     else{
        //         right--;
        //     }
        // }


        //Hashmap approach -- Best approach -- O(n)
        unordered_map<int,int> m;
        for(int i = 0; i<s; i++){
            int comp = target - nums[i];
            if(m.find(comp) != m.end()){
                res.push_back(m[comp]);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};