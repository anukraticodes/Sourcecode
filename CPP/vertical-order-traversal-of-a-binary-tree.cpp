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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* temp=p.first;
            int x=p.second.first;
            int y=p.second.second;
            nodes[x][y].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{x-1, y+1}} );
            }
if(temp->right){
    q.push({temp->right, {x+1, y+1}});
}
        }

vector<vector<int>> v;
for(auto i:nodes){
    vector<int> col;
    for(auto j:i.second){
        col.insert(col.end(), j.second.begin(), j.second.end());
    }
    v.push_back(col);
}
        return v;
    }
};
