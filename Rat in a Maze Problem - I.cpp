//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(int i, int j,vector<vector<int>> &m,int &n,vector<vector<bool>> &visited){
        if((i>=0 and i<n) and (j>=0 and j<n) and m[i][j] == 1 and visited[i][j] == false) return true;
        else return false;
    }
    void solve(vector<vector<int>> &m, int &n, vector<string>&ans, string temp, int i, int j,vector<vector<bool>> &visited){
      
        if(i == n-1 and j == n-1) {
            ans.push_back(temp);
            temp.clear();
            return;
        }   
        visited[i][j] = true;
        int x=0, y=0;
         x = i+1, y = j;
        if(isSafe(x,y, m,n ,visited)){
            temp.push_back('D');
            solve(m, n ,ans, temp, x,y, visited);
            temp.pop_back();
        }
        x = i, y = j-1;
        if(isSafe(x,y, m,n, visited)){
             temp.push_back('L');
            solve(m, n ,ans, temp, x,y, visited);
            temp.pop_back();
        }
       x = i, y = j+1;
        if(isSafe(x,y, m,n, visited)){
             temp.push_back('R');
            solve(m, n ,ans, temp, x,y, visited);
            temp.pop_back();
        }
       
         x = i-1, y = j;
        if(isSafe(x,y, m,n, visited)){
             temp.push_back('U');
            solve(m, n ,ans, temp, x,y, visited);
            temp.pop_back();
        }
      visited[i][j] = false;
    
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
      vector<string>ans;
      vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
      if(m[0][0] == 0 ) return ans;
      solve(m, n , ans, "",0,0, visited);
     // sort(ans.begin(), ans.end());
      return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
