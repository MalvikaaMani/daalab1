class Solution {
public:
    int ans;
    
    int maxPathDown(TreeNode* node){
        if(!node) return 0;
        int left = max(maxPathDown(node->left), 0);
        
        int right = max(maxPathDown(node->right), 0);
        ans = max(ans, left+right+node->val);
     
        return node->val + max(left, right);
    };

    int maxPathSum(TreeNode* root) {
         ans = INT_MIN;
        
        maxPathDown(root);
        
        return ans;
    }
};
