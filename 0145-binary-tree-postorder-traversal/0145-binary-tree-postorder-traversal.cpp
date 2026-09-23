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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> post;
        TreeNode* cur = root;

        while(cur != NULL || !st.empty()){
            if(cur != NULL){
                st.push(cur);
                cur = cur -> left;
            }
            else{
                TreeNode* temp = st.top();
                if(temp -> right == NULL){
                    post.push_back(temp -> val);
                    st.pop();
                    while(!st.empty() && st.top() -> right == temp){
                        temp = st.top();
                        st.pop();
                        post.push_back(temp -> val);
                    }
                }
                else{
                    cur = temp -> right;
                }
            }
        }

        return post;
    }
};