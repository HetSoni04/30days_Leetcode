class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> m;
        int max = 0;
        for(auto i : barcodes){
            m[i]++;
        }
        
        priority_queue<pair<int,int>> pq;
        for(auto& [num,count] : m){
            pq.push({count,num});
        }
        vector<int> v;
        while(pq.size() >= 2){
            auto [count1,n1] = pq.top();pq.pop();
            auto [count2,n2] = pq.top();pq.pop();
            v.push_back(n1);
            v.push_back(n2);
            if(--count1 > 0) pq.push({count1,n1});
            if(--count2 > 0) pq.push({count2,n2});
        }
        if(!pq.empty()){
            v.push_back(pq.top().second);
        }
        return v;
    }
};