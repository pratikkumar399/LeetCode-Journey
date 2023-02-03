//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here
        string ans ;
      int count = 0 ;
        for(auto c : s ){
          if(c == '(' and count == 0){
            count++ ;
          }
          else if(c == '(' and count > 0){
            ans += c ;
            count++ ;
          }
          else if(c == ')' and count > 1){
            ans += c ;
            count-- ;
          }
          else if(c == ')' and count == 1){
            count-- ;
          }
        }
      return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends