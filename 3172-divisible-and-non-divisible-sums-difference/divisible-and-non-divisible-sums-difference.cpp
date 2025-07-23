class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total_sum = (n * (n+1)) / 2;
        int div_sum = 0;
        if(m == 1) return (-1)*total_sum;
        for(int i = 1 ; (i*m) <= n ;i++){
            div_sum += i*m;
        }
        return (total_sum - div_sum - div_sum);
    }
};