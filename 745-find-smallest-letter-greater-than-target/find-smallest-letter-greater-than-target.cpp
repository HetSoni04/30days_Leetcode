class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[letters.size()-1] <= target) return letters[0];
        if(letters.size() == 1)
            return letters[0];
        if(letters.size() == 0) 
            return '\0';
        if(letters[0] > target) return letters[0];
        int l = 0;
        int h = letters.size()-1;
        int m;
        while(l<=h && l>=0 && h>=0){
            m = (l+h)/2;
            cout<<letters[m]<<endl;
            if(letters[m] > target){
                if(letters[m-1] <= target) break;
                h = m-1;
            }
            if(letters[m] <= target) l = m+1;
        }
        return letters[m];
    }
};