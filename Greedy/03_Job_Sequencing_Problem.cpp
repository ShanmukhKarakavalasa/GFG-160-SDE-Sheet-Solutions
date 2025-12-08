#include<bits/stdc++.h>
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        vector<pair<int, int>> jobs;
        
        for(int i=0;i<n;i++){
            jobs.push_back({deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto job: jobs){
            if(pq.size()<job.first){
                pq.push(job.second);
            }
            else if(!pq.empty() && pq.top()<job.second){
                pq.pop();
                pq.push(job.second);
            }
        }
        
        int total=0, profits=0;
        while(!pq.empty()){
            profits+=pq.top();
            pq.pop();
            total++;
        }
        
        return {total, profits};
    }
};
