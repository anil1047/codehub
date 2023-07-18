//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
            
            for(auto d:dir){
                int nr=r+d[0];
                int nc=c+d[1];
                
                if(nr<0||nr>=grid.size()||nc<0||nc>=grid[0].size()||vis[nr][nc]) 
                continue;
               if(grid[r][c]=='1')
                bfs(nr,nc,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends