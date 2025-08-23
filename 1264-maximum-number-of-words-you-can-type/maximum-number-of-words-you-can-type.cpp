class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool> bl;
        for(auto i : brokenLetters){
            bl[i] = true;
        }
        int count = 0;
        bool f = false;
        for(auto c : text){
            if(c == ' '  && !f){
                count++;
            } 
            else if(c == ' ') f = false;
            else if(bl.find(c) != bl.end()) f = true; 
        }
        if(!f) count++;
        return count;
    }
};