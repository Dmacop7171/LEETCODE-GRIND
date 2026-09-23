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
    int check(TreeNode* root , int & Max){
        if(root == NULL) return 0;
        int lt = check(root -> left , Max);
        int rt = check(root -> right , Max);

        Max = max(Max,lt+rt);

        return 1 + max(rt,lt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int Max = 0;
        check(root , Max);
        return Max;
    }
};