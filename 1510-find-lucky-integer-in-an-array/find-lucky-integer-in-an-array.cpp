#include<map>
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> m;
        int s = arr.size();
        if(s < 1){
            return -1;
        }
        if(s == 1){
            if(arr[0] == 1) return 1;
            return -1;
        }
        for(int i = 0; i<s ;i++){
            if(m.contains(arr[i])){
                m[arr[i]] = m[arr[i]] + 1; 
            }else{
                m.insert({arr[i],1});
            }
        }
        int max = -1;
        for(auto it = m.begin() ; it != m.end() ; ++it){
            if(it->first == it->second) {
                if(max < it->first) max = it->second;
            }
        }
        return max;
    }
};