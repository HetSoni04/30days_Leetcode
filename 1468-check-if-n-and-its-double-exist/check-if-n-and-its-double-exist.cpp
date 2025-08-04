#include<unordered_map>
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,bool> m;
        for(auto n : arr){
            if(m[2*n])  return true;
            else if(n%2==0 && m[n/2])   return true;
            m[n] = true; 
        }
        return false;
    }
};