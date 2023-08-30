//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:


     bool check(int i,int j,string &S){
         while(i<j){
             if(S[i]!=S[j]) return false;
             
             i++;
             j--;
         }
         return true;
     }
    string longestPalindrome(string S){
        // code here 
        int n=S.size();
        
        // bool dp[n][n];
        // memset(dp,0,sizeof(dp));
        
        int maxlen=0;
        int sidx=0;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(i,j,S)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        sidx=i;
                    }
                }
            }
        }
        return S.substr(sidx,maxlen);
        
        // for(int i=0;i<n;i++){
        //     dp[i][i]=true;
        // }
        
        // int start=0;
        // for(int i=0;i<n-1;i++){
        //     if(S[i]==S[i+1])
        //     {
        //         dp[i][i+1]=true;
        //         start=i;
        //         mxlen=2;
        //     }
        // }
        
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends