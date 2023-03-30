//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		  deque<char>dq;
		  int ar[26] = {0};
		  string ans;
		  for(auto i:A){
		      ar[i-'a']++;
		     dq.push_back(i);
		     
		     while(!dq.empty()){
		         if(ar[dq.front()-'a']>1){
		             dq.pop_front();
		         }else{
		             ans.push_back(dq.front());
		             break;
		         }
		     }
		     if(dq.empty()) ans.push_back('#');
		  }
		  return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
