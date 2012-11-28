#ifndef TREENODE_HPP
#define TREENODE_HPP

class TreeNode {
public:
  TreeNode(): left(0), right(0), data(0) {} 
  TreeNode( int n ): left(0), right(0), data(n) {} 

  TreeNode *leftSubtree() { return left; }
  TreeNode *rightSubtree() { return right; }

  void leftSubtree( TreeNode *left ) { this->left = left; }
  void rightSubtree(TreeNode *right) { this->right = right; }

  int& value() { return data; } 

private:
  TreeNode *left, *right;
  int data;
};  

#endif
