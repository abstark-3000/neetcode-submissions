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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        map<int,vector<int>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size()>0)
        {
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int ver=it.second.second,hor=it.second.first;
            m[hor].push_back(node->val);
            if(node->left)
            {
                q.push({node->left,{hor+1,ver-1}});
            }
            if(node->right)
            {
                q.push({node->right,{hor+1,ver+1}});
            }
        }
        vector<int>ans;
        for(auto it:m)
        {
            ans.push_back(it.second.back());
        }
        return ans;
    }
};
