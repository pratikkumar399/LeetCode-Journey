class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      // the givern matrix is a sqaure matrix 
        int n = matrix.size();
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
		for(int i  = 0  ; i < n ; ++i ){
            reverse(matrix[i].begin() , matrix[i].end() ) ;
        }
    }
};

// in this question we are required to rotate a 2d image by 90 degrees 
// and also take care that the rotation of the matrix is done in constatnt space 
// when we analyze the question we get to see that the col of the first matrix becomes the reversed row of the second matrix 
// so what we need to do is that we swap the elements of the matrx in the col to the elements in the row of the matrix 
// lets take an example to see how we can do the swapping  matrix[1][2]  = 5 ,  now swap it  matrix[2][1] = 5 
// so we can do the swapping by making i = j and j = i and also inside the second loop we need to make j == i , in order to do swapping for each of the row 
// now after the swapping we need to reverse the rows in the matrix 
// and this will give us the required answer 