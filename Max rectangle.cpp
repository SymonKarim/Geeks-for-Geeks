//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
 private:
   vector<int> nextIndexes(int *arr, int &n){
       stack<int>stack;
       stack.push(-1);
       vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        while( stack.top() != -1 and arr[stack.top()]>=curr){
                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(i);
            
        }
    return ans;
   }
      vector<int> prevIndexes(int *arr, int &n){
        stack<int>stack;
       stack.push(-1);
       vector<int>ans(n);
     for(int i=0;i<n;i++){
        int curr = arr[i];
        while( stack.top() != -1 and arr[stack.top()]>=curr){
                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(i);
        }
    return ans;
}
   int solve(int *arr, int n){
       vector<int>next(n), prev(n);
       next = nextIndexes(arr,n);
       prev = prevIndexes(arr,n);
        int mx = INT_MIN;
       for(int i=0;i<n;i++){
          int left = arr[i];
           if(next[i]==-1) {
               next[i] = n;
           } 
           int right = next[i]-prev[i]-1;
           int ans = left*right;
           mx = max(mx, ans);
       }
       return mx;
   }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        int ans = solve(M[0], m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] >0){
                    M[i][j]=M[i][j]+M[i-1][j];
                }else{
                     M[i][j] = 0;
                }
            }
            ans = max(ans, solve(M[i],m));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
