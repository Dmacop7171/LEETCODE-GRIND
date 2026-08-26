class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int rows = matrix.size();       // Get the number of rows
        int cols = matrix[0].size();    // Get the number of columns
        for(int i=0;i<rows;i++){
            for(int j=i+1;j<cols;j++){
                  swap(matrix[i][j] , matrix[j][i]);
            }
         }
           for(int i=0;i<rows;i++){
            for(int j=0;j<cols/2;j++){
                  swap(matrix[i][j] , matrix[i][rows-j-1]);
            }
         }

    }
};