#include <iostream>
using namespace std;

/* 
   TOPIC 9: TREES
   --------------
   Binary Tree: Each node has at most two children.
   Height: Number of edges from root to deepest leaf.
   Depth: Number of edges from root to specific node.
*/

struct TreeNode {
    char data;
    TreeNode *left, *right;
    TreeNode(char val) {
        data = val;
        left = right = NULL;
    }
};

// --- TRAVERSALS ---

// PreOrder: Root -> Left -> Right
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// InOrder: Left -> Root -> Right
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// PostOrder: Left -> Right -> Root
void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// --- EXAM SNIPPET: EXPRESSION TREE (Feb 2025 Q4d) ---
/*
   Expression: J / (M + N) - K * L
   Rule: Operands are leaves, Operators are internal nodes.
   Follow Order of Operations (PEMDAS/BODMAS)
   
   Tree structure:
             -
           /   
          /     *
         /     / 
        /     K   L
       /
      /
     /
    +
   / 
  M   N
   Wait, let's re-verify: J / (M + N) is one term. K * L is another.
   Correct structure for J / (M + N) - K * L:
            -
          /   
         /     *
        /     / 
       /     K   L
      /
     /
    J
   / 
  +
 / 
M   N
   Actually:
            -
          /   
         /     *
        /     / 
       /     K   L
      /
     /
    J
     
      +
     / 
    M   N
   
   Final Algebraic Expression Tree Structure:
   Top Node: -
   Left of -: /
   Right of -: *
   Left of /: J
   Right of /: +
   Left of +: M
   Right of +: N
   Left of *: K
   Right of *: L
*/

int main() {
    // Example Tree for Figure 10 (Feb 2025)
    /*
          70
         /  
        45   90
       / \   / 
      38 62 85 95
    */
    TreeNode* root = new TreeNode('A'); // Placeholder
    // Root=70, Left=45, Right=90...
    
    cout << "Traversals are keys for exams. Remember: " << endl;
    cout << "Pre: Root first" << endl;
    cout << "Post: Root last" << endl;
    cout << "In: Root middle" << endl;

    return 0;
}
