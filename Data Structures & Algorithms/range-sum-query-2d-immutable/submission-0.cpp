class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        prefixMatrix.resize(row,std::vector<int>(col,0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                prefixMatrix[i][j] = matrix[i][j];
                if(i - 1 >= 0){
                    prefixMatrix[i][j] += prefixMatrix[i-1][j];
                }

                if(j - 1 >= 0){
                    prefixMatrix[i][j] += prefixMatrix[i][j-1];
                }

                if(i-1 >= 0 && j -1 >= 0){
                    prefixMatrix[i][j] -= prefixMatrix[i-1][j-1];
                }
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        int sum = prefixMatrix[row2][col2];
        if(row1 -1 >= 0){
            sum -= prefixMatrix[row1 - 1][col2];
        }

        if(col1 - 1 >= 0){
            sum -= prefixMatrix[row2][col1 - 1];
        }

        if(row1 - 1 >= 0 && col1 - 1 >= 0){
            sum += prefixMatrix[row1 - 1][col1 - 1];
        }

        return sum;
    }

    std::vector<std::vector<int>> prefixMatrix;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */