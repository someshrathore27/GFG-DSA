
// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        // Your code goes here
        vector<int>lps(s.length(),0);
        int len=0;
        lps[0]=0;
        int i=1;
        while(i<s.length())
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)
                {
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps[lps.size()-1];
    }
};