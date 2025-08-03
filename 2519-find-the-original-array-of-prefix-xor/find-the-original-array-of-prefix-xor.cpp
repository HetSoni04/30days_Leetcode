class Solution {
public:
    vector<int> findArray(vector<int>& pref){
        int prev = pref[0];
        for(int i = 1 ; i<pref.size() ; i++){
            int n = pref[i];
            pref[i] = n ^ prev;
            prev = n;
        }
        return pref;
    }
};