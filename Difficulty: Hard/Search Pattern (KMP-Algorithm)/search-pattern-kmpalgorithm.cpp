class Solution {
  public:
    void calclps(string &pat, vector<int>&lps)
    {
        int i=1;
        int len=0;
        lps[0]=0;
        int m=pat.size();
        while(i<m)
        {
            if(pat[i]==pat[len])
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
    }
    vector<int> search(string& pat, string& txt) {
        // code here
        vector<int>ans;
        int n=txt.size();
        int m=pat.size();
        if(m>n) return ans;
        vector<int>lps(m,0);
        calclps(pat,lps);
        int i=0;
        int j=0;
        while(i<n)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
                if(j==m)
                {
                    ans.push_back(i-j);
                    j=lps[j-1];
                }
            }
            else{
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};