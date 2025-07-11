class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> stableMnts;
        int s = height.size();
        for(int i = 1; i<s ; i++){
            if(height[i-1] > threshold){
                stableMnts.push_back(i);
            }
        }
        return stableMnts;
    }
};