#include<string>
class Solution {
public:
    int minFlips(int a, int b, int c) {
        string s_a = bitify(a);
        string s_b= bitify(b);
        string s_c = bitify(c);
        int size = max({s_a.size(),s_b.size(),s_c.size()});
        if(s_a.size() < size){
            int t = size - s_a.size();
            string t_s = "";
            for(int i =0 ; i<t ; i++){
                t_s += "0";
            }
            s_a = t_s + s_a;
        }
        if(s_b.size() < size){
            int t = size - s_b.size();
            string t_s = "";
            for(int i =0 ; i<t ; i++){
                t_s += "0";
            }
            s_b = t_s + s_b;
        }
        if(s_c.size() < size){
            int t = size - s_c.size();
            string t_s = "";
            for(int i =0 ; i<t ; i++){
                t_s += "0";
            }
            s_c = t_s + s_c;
        }
        int count = 0;
        for(int i = size-1; i>=0 ;i--){
            if(s_a[i] == s_b[i] && s_a[i] == s_c[i]) continue;
            else if(s_a[i] == '1' && s_b[i] == '1' && s_c[i] == '0') count +=2;
            else if((s_a[i] == '1' || s_b[i] == '1') && s_c[i] == '1') continue;
            else if((s_a[i] == '0' || s_b[i] == '0') && s_c[i] == '1') count++;
            else if((s_a[i] == '1' || s_b[i] == '1') && s_c[i] == '0') count++;
        }
        return count;
    }
    string bitify(int n){
        string s = "";
        int started = 0;
        for (int i = 31; i >= 0; i--) {
            if ((n >> i) & 1) {
                started = 1;
                s += "1";
            } else if (started) {
                s += "0";
            }
        }
        if (!started) s+= "0";
        return s;
    }
};