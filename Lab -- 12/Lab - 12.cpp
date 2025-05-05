#include<iostream>
using namespace std;

// ===== BST Implementation =====
class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
public:
    BSTNode* insert(BSTNode* root, int val) {
        if (!root) return new BSTNode(val);

        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }

    void inorder(BSTNode* root) {
        if (!root) return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

// ===== AVL Implementation =====
class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

int height(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

AVLNode* insertAVL(AVLNode* node, int val) {
    if (!node) return new AVLNode(val);

    if (val < node->data)
        node->left = insertAVL(node->left, val);
    else if (val > node->data)
        node->right = insertAVL(node->right, val);
    else
        return node; // duplicate

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && val < node->left->data) return rotateRight(node);
    if (balance < -1 && val > node->right->data) return rotateLeft(node);
    if (balance > 1 && val > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && val < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void inorderAVL(AVLNode* node) {
    if (!node) return;
    inorderAVL(node->left);
    cout << node->data << " ";
    inorderAVL(node->right);
}

// ===== Main Function =====
int main() {
    cout << "=== BST (Binary Search Tree) ===\n";
    BST bst;
    BSTNode* bstRoot = nullptr;
    bstRoot = bst.insert(bstRoot, 40);
    bstRoot = bst.insert(bstRoot, 20);
    bstRoot = bst.insert(bstRoot, 60);
    cout << "Inorder Traversal: ";
    bst.inorder(bstRoot);
    cout << "\n\n";

    cout << "=== AVL (Self-Balancing Tree) ===\n";
    AVLNode* avlRoot = nullptr;
    avlRoot = insertAVL(avlRoot, 30);
    avlRoot = insertAVL(avlRoot, 20);
    avlRoot = insertAVL(avlRoot, 10); // Triggers balancing
    cout << "Inorder Traversal: ";
    inorderAVL(avlRoot);
    cout << endl;

    return 0;
}
