class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries){
        vector<int> powers;
        // int i = 0;
        // while(n > 0){
        //     if(n&1){ powers.push_back(1 << i);} 
        //     n = n >> 1;
        //     i++;
        // }
        
        const int MOD = 1000000007;
        for(;n>0; n&= (n-1)){
            powers.push_back(n & -n);
        }
        vector<int> answers;
        for(int i = 0; i<queries.size(); i++){
            
            if(queries[i][0] == queries[i][1]) answers.push_back(powers[queries[i][0]]);
            else{
                int mul = 1;
                for(int j = queries[i][0]; j <= queries[i][1];j++){
                    mul = int((1LL * mul * powers[j]) % MOD);
                }
                answers.push_back(mul);
            }
        }

        return answers;
    }
};