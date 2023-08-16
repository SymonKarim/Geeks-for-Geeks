//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//#include<unordered_map>
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    if(is_sorted(nums.begin(), nums.end())) return 0;
	    int cnt = 0, n = nums.size();
	   unordered_map<int,int>mp;
	   vector<int>ans(n);
	   for(int i=0;i<n;i++){
	       ans[i] = nums[i];
	   }
	   sort(ans.begin(), ans.end());
	   for(int i=0;i<n;i++){
	       mp[ans[i]] = i;
	   }
	   for(int i = 0; i<n;i++){
	       int index = mp[nums[i]];
	       if(i!=index){
	           swap(nums[i] , nums[index]);
	           cnt++;
	           i-=1;
	       }
	   }
	   return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
