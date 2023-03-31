//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string &s)
    {
        stack<char>st;
        
        for(int it=0;it<s.size();it++){
            char i = s[it];
            if(st.empty()) st.push(i);
            else if ((i==')' and st.top() == '(') || (i=='}' and st.top() == '{') or (i==']' and st.top() == '[')) st.pop();
            else st.push(i);
        }
        if(st.empty()) return true;
        return false;
    
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
