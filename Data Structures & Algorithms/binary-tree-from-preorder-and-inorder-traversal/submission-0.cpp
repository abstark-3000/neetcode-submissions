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
    TreeNode* f(vector<int>&preorder,vector<int>&node)
    {
        if(node.size()==0 || preorder.size()==0)return NULL;
         
        int rootval=preorder[0];
        TreeNode* root=new TreeNode(rootval);
        int i=0;
        while(i<node.size() && node[i]!=preorder[0])i++;
        vector<int>lnode(node.begin(),node.begin()+i);
        vector<int>rnode(node.begin()+i+1,node.end());
        int x=lnode.size();
        vector<int>lpre(preorder.begin()+1,preorder.begin()+1+x);
        vector<int>rpre(preorder.begin()+1+x,preorder.end());
        TreeNode* temp=new TreeNode(-1);
        
        root->left=f(lpre,lnode);
        root->right=f(rpre,rnode);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return f(preorder,inorder);
        
        
    }
};