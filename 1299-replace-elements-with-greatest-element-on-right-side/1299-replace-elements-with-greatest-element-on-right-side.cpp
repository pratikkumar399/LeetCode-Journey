class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
              
      int n = arr.size() ;
      if(n == 1 ) return {-1} ;
      int maxi = -1 ;
      int prev ;
      for(int i = n-1 ; i >= 0 ; i--){
        prev=  arr[i] ;
        arr[i] = maxi ;
        maxi= max(prev , maxi) ;
      }
      
      // arr.push_back(-1) ;
      
      return arr ;
    }
};

// so what we are required to do in this question is that we need to take an element and replace it with the greatest element that
// is in the right of that element

// lets talk about the brute force approach 
//  lets not take the first element because we have to replace it with greater element on its right 
// then the nested loop can run from the second elements and take the greatest out of all of them and then replace it with
//  the required element 

// let us optimize our 2d loop approach to do our work in a better time complexity because the brute force approach gives us tle /
// 