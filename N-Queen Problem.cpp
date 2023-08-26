//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int N;
    bool isSafe(char **grid, int row,int col){
        for(int i=0;i<row;i++){
            if(grid[i][col]=='Q') return false;
        }
        for(int i=0;i<col;i++){
            if(grid[row][i]=='Q') return false;
        }
        for(int i=row, j=col;i>=0 and j>=0;i--,j--){
            if(grid[i][j]=='Q') return false;
        }
        for(int i=row, j=col;i>=0 and j<N;i--,j++){
            if(grid[i][j]=='Q') return false;
        }
    }
    void solve(char **grid,int index,vector<vector<int>> &ans){
        if(index == N){
            vector<int>temp;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
             if(grid[i][j]=='Q') 
               {temp.push_back(j+1);break;}
            }
        }
        ans.push_back(temp);
        return;
        }
        
        for(int i=0;i<N;i++){
            if(isSafe(grid, index,i)){
               grid[index][i] = 'Q';
               solve(grid, index+1,ans);
                 grid[index][i] = '.';
           }
        }
    }
    vector<vector<int>> nQueen(int n) {
        char **grid;
        grid = new char*[n];
        N = n;
        for(int i=0;i<n;i++){
            grid[i] = new char[n];
            for(int j=0;j<n;j++){
                grid[i][j] = '.';
            }
        }
        vector<vector<int>> ans;
        solve(grid,0, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
