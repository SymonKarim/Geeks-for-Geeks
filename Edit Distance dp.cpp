//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(vector<vector<int>>&dp,string s, string t, int i ,int j){
        if(i==s.size()) return t.size()-j;
        if(j==t.size()) return s.size()-i;
        int &ret= dp[i][j];
        if(ret!=-1) return ret;
        int x = 0;
        if(s[i]==t[j]){
            x = solve(dp,s,t,i+1,j+1);
        }else{
            x = 1+min(solve(dp,s,t,i+1,j), 
            min(solve(dp,s,t,i,j+1),
            solve(dp,s,t,i+1,j+1)));
        }
        return ret = x;
    }
    int editDistance(string s, string t) {
        // Code here
        if(s==t) return 0;
        vector<vector<int>>dp(s.size()+1, vector<int>(t.size()+1, -1));
        return solve(dp,s, t, 0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
