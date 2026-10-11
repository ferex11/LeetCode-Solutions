class Solution {
private:
  bool dfs(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return dfs(p->left, q->left) && dfs(p->right, q->right);
  }
public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
      return false;
    }
    if (dfs(root, subRoot)) {
      return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};
