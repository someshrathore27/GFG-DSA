class Solution {
  public:
    int precedence(char ch)
    {
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/')return 2;
        else if(ch=='+' || ch=='-')return 1;
        else{
            return -1;
        }
    }
    string infixToPostfix(string& s) {
        // code here
        string ans="";
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))
            {
                ans+=s[i];
            }
            else if(s[i]=='(') st.push(s[i]);
            
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            
             else {
                while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
