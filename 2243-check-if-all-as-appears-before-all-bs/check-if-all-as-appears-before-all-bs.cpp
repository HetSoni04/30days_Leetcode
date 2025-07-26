class Solution {
public:
    bool checkString(string s) {
        bool result = true;
        for(int i = 0; (i+1)<s.size() ; i++){
            if(s[i] == 'b' && s[i+1]=='a'){
                result = false;
            }
        }
        return result;
    }
};