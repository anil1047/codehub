//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        vector<int>path(31,-1);
        for(int i=0;i<N*2;i+=2){
            path[arr[i]]=arr[i+1];
        }
        
        queue<int>q;
        q.push(1);
        int cnt=0;
        vector<bool>vis(31,0);
        vis[1]=0;
        
        while(!q.empty()){
            
            int t=q.size();
            while(t--){
                int u=q.front();
                q.pop();
                if(u==30) return cnt;
                
            for(int i=u+1;i<u+7;i++){
                if(i>30) break;
                if(vis[i]) continue;
                
                if(path[i]==-1) q.push(i);
                 else q.push(path[i]);
            }
            }
            cnt++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends