class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string sum="";
        while(n)
        {
            sum=sum+to_string(n%2);
            n=n/2;
        }
        int s=0;
        int e=sum.size()-1;
        while(s<e)
        {
            swap(sum[s++],sum[e--]);
        }
        return sum;
        
    }
};