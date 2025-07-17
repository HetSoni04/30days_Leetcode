class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> result;
        char start = s[0];
        char end = s[3];
        char i = s[1];
        char j = s[4];
        for(char c = start; c<=end ; c++){
            for(char k = i; k<=j ; k++){
                string temp;
                temp += c;
                temp += k;
                result.push_back(temp);
            }
        }
        return result;
    }
};