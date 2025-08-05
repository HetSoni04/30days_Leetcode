class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> m_sc;
        unordered_map<char,string> m_cs;
        int n = pattern.size();
        int j = 0;
        
        for(int i = 0; i<n ; i++){
            string t = "";
            while(s[j] != ' ' && s[j] != '\0'){
               t += s[j];
               j++;
            }
            if(m_sc.find(t) != m_sc.end() || m_cs.find(pattern[i]) != m_cs.end()){
                if(m_sc[t] != pattern[i] && m_cs[pattern[i]] != t) return false;
            }else{
                m_sc[t] = pattern[i];
                m_cs[pattern[i]] = t;
            }
            j++;
            cout<<m_sc[t]<<" "<<m_cs[pattern[i]]<<endl;
        }

        if(--j>s.size()|| j<s.size()) return false;
        return true;
    }
};