class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(0);
        
        vector<pair<int,int>>p;
        for(int i=0;i<deadline.size();i++)
        {
            p.push_back(make_pair(deadline[i],profit[i]));
        }
        sort(p.begin(),p.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<p.size();i++)
        {
            if(p[i].first>pq.size())
            {
                pq.push(p[i].second);
            }
            else{
                if(!pq.empty() && p[i].second>pq.top())
                {
                    pq.pop();
                    pq.push(p[i].second);
                }
            }
        }
        while(!pq.empty())
        {
            ans[1]+=pq.top();
            pq.pop();
            ans[0]++;
        }
        return ans;
        
    }
};