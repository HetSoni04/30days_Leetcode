class Solution {
public:
    bool isSubsequence(string s, string t) {
        int it = 0;
        int js = 0;
        if(s == t){
            return true;
        }
        if(s == ""){
            return true;
        }
        int s_len = s.size();
        while(t[it] != '\0' && s[js] != '\0'){
            if(t[it] == s[js]){
                string temp = t.substr(0,s_len);
                if(temp == s){
                    return true;
                }
                js++;
            }
            else{
                t.erase(it,1);
                it--;
            }
            it++;
        }
        if(t == s){
            return true;
        }
        return false;
    }
};