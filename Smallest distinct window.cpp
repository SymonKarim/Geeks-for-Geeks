//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        unordered_map<char,int>mp,temp;
        for(auto i:str) mp[i]++;
        int mx = str.size();
        int sz = mx;
        int start = 0;
        for(int i=0;i<sz;i++){
           temp[str[i]]++;
           if(temp.size()<mp.size()) continue;
           
           while(temp[str[start]]>1) {
              temp[str[start]]--;
              start++;
           }
           mx = min(mx, i-start+1);
        }
        return mx;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
