class Solution {
public:
    vector<int> gRows(int row){
        vector<int> Row(row);
        Row[0] = 1;
        int ans = 1;
        for(int col = 1 ; col < row ; col++){
            ans = ans*(row - col);
            ans = ans/(col);
            Row[col] = ans;
        }
        return Row;
    }
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1) return {{1}};
        vector<int> rows;
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int row = 2 ; row<= numRows  ; row++){
            ans.push_back(gRows(row));
        }
        return ans;
    }
};