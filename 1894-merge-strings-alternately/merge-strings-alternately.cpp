class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i  = 0;
        int j = 0;
        int n = word1.size();
        int m = word2.size();
        if(n>m){
            while(j<m){
                result += word1[i++];
                result += word2[j++];
            }
            while(i<n){
                result += word1[i++];
            }
        }
        else if(n == m){
            while(i < n){
                result += word1[i++];
                result += word2[j++];
            }
        }
        else{
            while(i < n){
                result += word1[i++];
                result += word2[j++];
            }
            while(j<m){
                result += word2[j++];
            }
        } 
        return result;
    }
};