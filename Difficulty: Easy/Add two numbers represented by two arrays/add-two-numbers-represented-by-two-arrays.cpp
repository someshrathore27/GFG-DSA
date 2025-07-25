

class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        // Complete the function
        int i=arr1.size()-1;
        int j=arr2.size()-1;
        int carry=0;
        string ans="";
        while(i>=0 || j>=0 || carry)
        {
            int digit1=(i>=0)?arr1[i]:0;
            int digit2=(j>=0)?arr2[j]:0;
            int sum=digit1+digit2+carry;
            carry=sum/10;
            int digit=sum%10;
            ans=to_string(digit)+ans;
            i--;
            j--;
        }
        return ans;
    }
};