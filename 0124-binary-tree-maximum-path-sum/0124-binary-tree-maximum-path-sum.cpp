/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(TreeNode* root,int& maxsum){
        if(root == NULL) return 0;
        int lt = max(0,check(root -> left,maxsum));
        int rt = max(0,check(root -> right,maxsum));

        maxsum = max(maxsum,lt+rt+root->val);

        return  root -> val + max(lt,rt);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;
        check(root,maxsum);
        return maxsum;
    }
};