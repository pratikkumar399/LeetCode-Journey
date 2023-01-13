class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
              
      int n = arr.size() ;
      if(n == 1 ) return {-1} ;
      int maxi = -1 ;
      
      int prev ;
      for(int i = n-1 ; i >= 0 ; i--){
       //  fixing the n-i th element as the element
        // prev= 1 
        // arr[5] = 1 
        // prev = 6 
        // arr[4] = 6 
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
// from the question it is clear that we have to only take the rightmost element into consideration 
// now if we see from the back side then we can clearly see that the last element has -1 as its max in the right
// the seconde last element has the last element as the max
// so what we can do is that iterate from the back side and then take up tha max of all the elements already traversed from the back side and then replace that element witht the maximum one 