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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        return build(v, 0, v.size()-1);
    }

    void inorder(TreeNode* node, vector<int> & v){
        if(!node) return;

        inorder(node->left ,v);
        v.push_back(node->val);
        inorder(node->right, v);
        }

    TreeNode* build(vector<int> & v, int start, int end){
        if(start>end) return NULL;

        int mid=(start+end)/2;
        TreeNode* node= new TreeNode(v[mid]);
        node->left= build(v, start, mid-1);
        node->right= build(v, mid+1, end);
        return node;    }
};
