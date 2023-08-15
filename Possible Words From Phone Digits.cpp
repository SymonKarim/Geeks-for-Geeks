//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int &n, int index, vector<string>&ans, string temp,vector<string>&store){
        if(index==n){
            ans.push_back(temp);
            return;
        }
        string s = store[a[index]];
       // cout<<s<<endl;
        for(auto i:s){
           // cout<<i<<endl;
            temp.push_back(i);
            solve(a, n, index+1,ans, temp, store);
            temp.pop_back();
        }
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>ans;
        vector<string>store = {
            {},{},
            {"abc"},
            {"def"},
            {"ghi"},
            {"jkl"},
            {"mno"},
            {"pqrs"},
            {"tuv"},
            {"wxyz"}
        };
        string temp;
        solve(a, N, 0,ans,temp,store);
        //sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends
