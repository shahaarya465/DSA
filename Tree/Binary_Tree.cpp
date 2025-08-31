// Binary Tree Operations - Implementation of binary tree with insertion, deletion, and traversal methods

#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    void insertLeft(int parentKey, int key) {
        if (root == nullptr) {
            root = new TreeNode(parentKey);
            root->left = new TreeNode(key);
            return;
        }

        TreeNode* parentNode = findNode(root, parentKey);
        if (parentNode) {
            if (parentNode->left == nullptr) {
                parentNode->left = new TreeNode(key);
            } else {
                cout << "Left child already exists." << endl;
            }
        } else {
            cout << "Parent node not found." << endl;
        }
    }

    void deleteRight(int parentKey) {
        TreeNode* parentNode = findNode(root, parentKey);
        if (parentNode && parentNode->right) {
            delete parentNode->right;
            parentNode->right = nullptr;
        } else {
            cout << "Parent node not found or right child does not exist." << endl;
        }
    }

    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->val << " ";
            inorder(node->right);
        }
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->val << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->val << " ";
        }
    }

    void levelOrder() {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            cout << current->val << " ";

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

private:
    TreeNode* findNode(TreeNode* node, int key) {
        if (node == nullptr) return nullptr;
        if (node->val == key) return node;

        TreeNode* leftResult = findNode(node->left, key);
        if (leftResult) return leftResult;

        return findNode(node->right, key);
    }
};

int main() {
    BinaryTree tree;

    tree.insertLeft(1, 2);
    tree.insertLeft(1, 3);
    tree.insertLeft(2, 4);
    tree.insertLeft(2, 5);

    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "Level Order Traversal: ";
    tree.levelOrder();
    cout << endl;

    tree.deleteRight(2);
    cout << "After deleting right child of 2, Level Order Traversal: ";
    tree.levelOrder();
    cout << endl;

    return 0;
}
