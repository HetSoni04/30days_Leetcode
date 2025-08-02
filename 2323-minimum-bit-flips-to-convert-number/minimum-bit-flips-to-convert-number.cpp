class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        start = start ^ goal;
        while(start){
            start &= (start-1);
            count++;
        }
        return count;
    }
};