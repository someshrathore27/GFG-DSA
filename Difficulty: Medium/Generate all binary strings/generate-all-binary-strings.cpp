// User function Template for C++

class Solution {
  public:
    
    void generate(string &str, vector<string> &ans, string output, int idx) {
        // Base case
        if (idx >= str.length()) {
            ans.push_back(output);
            return;
        }
        
        str[idx] = '0';
        generate(str, ans, output + '0', idx + 1);
        
        if (output.empty() || output.back() != '1') {
            str[idx] = '1';
            generate(str, ans, output + '1', idx + 1);
            str[idx] = '0';
        }
    }

    vector<string> generateBinaryStrings(int num) {
        string str(num, '0'); // initialize with zeros
        vector<string> ans;
        generate(str, ans, "", 0);
        return ans;
    }
};
