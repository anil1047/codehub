//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    void isexist(vector<vector<int>>&grid,vector<vector<bool>>&vis,int si,int sj){
        int n=grid.size();
        if(si<0 || si>=n || sj<0 || sj>=n || grid[si][sj]==0 || vis[si][sj]==true)
          return;
        vis[si][sj]=true;
        isexist(grid,vis,si+1,sj);
         isexist(grid,vis,si-1,sj);
          isexist(grid,vis,si,sj-1);
           isexist(grid,vis,si,sj+1);
        
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size(),m=grid[0].size(),si,sj,di,dj;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    si=i;
                    sj=j;
                }
                if(grid[i][j]==2){
                    di=i;
                    dj=j;
                }
            }
        }
        isexist(grid,vis,si,sj);
        return vis[di][dj];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends