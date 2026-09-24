class Solution {
public:
  
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;

        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
           int ssize = q.size();
           vector<int> ds(ssize);
           for(int i=0 ; i <ssize ; i++ ){
               int index = leftToRight ? i : ssize - i - 1;
               TreeNode* node = q.front();
               q.pop();
               ds[index] = node -> val;
               if(node -> left) q.push(node -> left);
               if(node -> right) q.push(node -> right);

           }

            ans.push_back(ds);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
