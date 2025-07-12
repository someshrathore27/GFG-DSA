class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n=deadline.size();
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(0);
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            p.push_back(make_pair(deadline[i],profit[i]));
        }
        sort(p.begin(),p.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto job:p)
        {
            if(job.first>pq.size())
            {
                pq.push(job.second);
            }
            else if(!pq.empty() && pq.top()<job.second)
            {
                pq.pop();
                pq.push(job.second);
            }
        }
        while(!pq.empty())
        {
            ans[1]+=pq.top();
            pq.pop();
            ans[0]++;
        }
        return ans;
        
        // int n = deadline.size();
        // vector<int> ans = {0, 0};
        // vector<pair<int, int>> jobs;
        // for (int i = 0; i < n; i++) 
        // {
        //     jobs.push_back({deadline[i], profit[i]});
        // }
        // sort(jobs.begin(), jobs.end());
        // priority_queue<int, vector<int>, greater<int>> pq;
    
        // for (const auto &job : jobs) 
        // {
        //     if (job.first > pq.size())
        //         pq.push(job.second);

        //     else if (!pq.empty() && pq.top() < job.second) {
        //         pq.pop();
        //         pq.push(job.second);
        //     }
        // }
    
        // while (!pq.empty()) 
        // {
        //     ans[1] += pq.top();
        //     pq.pop();
        //     ans[0]++;
        // }
    
        // return ans;
    }
};

