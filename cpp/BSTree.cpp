#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

BSTNode* Search(BSTNode* root, int data)
{
    if (root == NULL) {
        return root;
    } else if (root->data == data) {
        return root;
    } else if (root->data < data) {
        return Search(root->right, data);
    } else {
        return Search(root->left, data);
    }
}

BSTNode* SearchMax(BSTNode* root)
{
    if (root == NULL) {
        return root;
    } else if (root->right == NULL) {
        return root;
    } else {
        return SearchMax(root->right);
    }
}

BSTNode* SearchMin(BSTNode* root)
{
    if (root == NULL) {
        return root;
    } else if (root->left == NULL) {
        return root;
    } else {
        return SearchMin(root->left);
    }
}

BSTNode* Insert(BSTNode* root, int data)
{
    if (root == NULL) {
        root = new BSTNode();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    } else if (root->data == data) {
        cout << "data exist" << endl;
    } else if (root->data < data) {
        root->right = Insert(root->right, data);
    } else {
        root->left = Insert(root->left, data);
    }

    return root;
}

BSTNode* Delete(BSTNode* root, int data)
{
    if (root == NULL) {
        cout << "data dos not exist" << endl;
    } else if (root->data < data) {
        root->right = Delete(root->right, data);
    } else if (root->data > data) {
        root->left = Delete(root->left, data);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root;
            root = root->left;
            delete temp;
        } else {
            BSTNode* temp = SearchMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
    }

    return root;
}

void PreOrder(const BSTNode* root)
{
    if (root != NULL) {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(const BSTNode* root)
{
    if (root != NULL) {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(const BSTNode* root)
{
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}


int main()
{
    BSTNode* root = NULL;
    int data[] = {15, 30, 7, 3, 10, 5, 20, 35, 40, 7, 38};
    for (int i = 0; i < sizeof(data)/sizeof(int); ++i) {
        root = Insert(root, data[i]);
    }

    InOrder(root);
    cout << endl;
    root = Delete(root, 33);
    InOrder(root);
    cout << endl;
    root = Delete(root, 7);
    InOrder(root);
    cout << endl;
    root = Delete(root, 40);
    root = Delete(root, 38);
    InOrder(root);
    cout << endl;
    return 0;
}
