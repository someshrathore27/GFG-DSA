
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &arr) {
        // code here
        int rs = 0;  
        int re = arr.size() - 1;  
        int cs = 0; 
        int ce = arr[0].size() - 1; 
        vector<int> ans;

        while (rs <= re && cs <= ce) {
            for (int i = cs; i <= ce; i++) {
                ans.push_back(arr[rs][i]);
            }
            rs++;

            for (int i = rs; i <= re; i++) {
                ans.push_back(arr[i][ce]);
            }
            ce--;

            if (rs <= re) {
                for (int i = ce; i >= cs; i--) {
                    ans.push_back(arr[re][i]);
                }
                re--;
            }

            if (cs <= ce) {
                for (int i = re; i >= rs; i--) {
                    ans.push_back(arr[i][cs]);
                }
                cs++;
            }
        }
        return ans;
    }
};

