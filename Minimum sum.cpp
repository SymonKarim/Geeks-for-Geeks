//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string solve(int arr[], int n) {
        sort(arr, arr+n);
        string s="", t="";
        long long sum = 0,carry = 0;
        string ans;
        for(int i=0;i<n;i++){
            if(i&1){
                s+=(arr[i]+'0');
            }else{
                t+=(arr[i]+'0');
            }
        }
        if(n&1) s = '0'+s;
        for(int i=s.size()-1;i>=0;i--){
            sum = (s[i]-'0') + (t[i]-'0')+carry;
            carry = 0;
            if(sum>=10){
                int x = sum%10;
                ans.push_back(x+'0');
                carry = sum/10;
            }else{
                ans.push_back(sum+'0');
            }
        }
        if(carry) ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        int x = 0,sz = ans.size();
        while(ans[x]=='0') x++;
        return ( (x== sz) ? "0" : ans.substr(x));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
