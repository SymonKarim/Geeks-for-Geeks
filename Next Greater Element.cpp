//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>stack;
        stack.push(-1);
        vector<long long>ans(n);

    for(long long i=n-1;i>=0;i--){
        long long curr = arr[i];
        while(stack.top() != -1 and arr[stack.top()]<=curr){
                stack.pop();
            }
            ans[i] = stack.top();
            stack.push(i);
        }
       for(auto &i:ans){
           if(i!=-1){
               i = arr[i];
           }
       }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
