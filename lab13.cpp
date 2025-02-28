#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;

    }


    std::cout << root->data << " ";

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    std::cout << "Pre-order traversal of the tree: ";
    preOrderTraversal(root);
    std::cout << std::endl;


    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}



//Q2
#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return; 
    }


    postOrderTraversal(root->left);


    postOrderTraversal(root->right);


    std::cout << root->data << " ";
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);


    std::cout << "Post-order traversal of the tree: ";
    postOrderTraversal(root);
    std::cout << std::endl;


    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}




//Q3

#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val); 
    }

    if (val < root->data) {
        root->left = insert(root->left, val); 
    } else {
        root->right = insert(root->right, val); 
    }

    return root;
}


bool searchNonRecursive(TreeNode* root, int key) {
    while (root != nullptr) {
        if (key == root->data) {
            return true; 
        } else if (key < root->data) {
            root = root->left; 
        } else {
            root = root->right; 
        }
    }
    return false; 
}


bool searchRecursive(TreeNode* root, int key) {
    if (root == nullptr) {
        return false;
    }

    if (key == root->data) {
        return true; 
    } else if (key < root->data) {
        return searchRecursive(root->left, key); 
    } else {
        return searchRecursive(root->right, key); 
    }
}


void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;


    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);


    std::cout << "In-order traversal of the BST: ";
    inOrderTraversal(root);
    std::cout << std::endl;


    int key = 40;
    if (searchNonRecursive(root, key)) {
        std::cout << key << " found in the BST (non-recursive search)." << std::endl;
    } else {
        std::cout << key << " not found in the BST (non-recursive search)." << std::endl;
    }


    key = 90;
    if (searchRecursive(root, key)) {
        std::cout << key << " found in the BST (recursive search)." << std::endl;
    } else {
        std::cout << key << " not found in the BST (recursive search)." << std::endl;
    }

    return 0;
}