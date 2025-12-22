class Solution {
  public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& vis, vector<int>& path,
    string& ans){
        vis[u]=true;
        path[u]=true;
        
        for(int v=0;v<26;v++){
            if(graph[u][v]){
                if(!vis[v]){
                    if(!dfs(v, graph, vis, path, ans)) return false;
                }
                else if(path[v]) return false;
            }
            
        }
        
        ans+=(u+'a');
        path[u]=false;
        return true;
    }
    string findOrder(vector<string> &words) {
        int n=words.size();
        vector<vector<int>> graph(26, vector<int>(26, 0));
        vector<int> exist(26, 0);
        vector<int> vis(26, 0);
        vector<int> path(26, 0);
        string ans="";
        
        for(auto word: words){
            for(auto ch: word){
                exist[ch-'a']=1;
            }
        }
        
        for(int i=0;i+1<n;i++){
            string a=words[i], b=words[i+1];
            int m=a.size(), n=b.size(), ind=0;
            
            while(ind<m && ind<n && a[ind]==b[ind]){
                ind++;
            }
            
            if(ind<m && ind==n){
                return "";
            }
            
            if(ind<m && ind<n){
                graph[a[ind]-'a'][b[ind]-'a']=1;
            }
        }
        
        for(int i=0;i<26;i++){
            if(exist[i] && !vis[i]){
                if(!dfs(i, graph, vis, path, ans)){
                    return "";
                }
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
