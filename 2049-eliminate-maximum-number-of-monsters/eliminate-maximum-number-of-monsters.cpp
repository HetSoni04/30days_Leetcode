class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        if(n == 1) return n;
        vector<int> time;
        for(int k = 0; k<n ; k++){

            if(dist[k]%speed[k] == 0) time.push_back(dist[k]/speed[k]);
            else{
                time.push_back((dist[k]/speed[k]) + 1);
            }
        }
        sort(time.begin(),time.end());
        // for(auto a : time){
        //     cout<<a<<" ";
        // }cout<<endl;
        //now every minute a monster will be killed
        int i;
        for(i = 1; i<n ; i++){
            if(i >= time[i]) break;
        }
        return i;
    }
};