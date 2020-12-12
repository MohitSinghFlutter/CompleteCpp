#include<bits/stdc++.h>
#include"1_trees_helper.h"
using namespace std;

void deleteTree(TreeNode<int> *root);
// void postorder(TreeNode<int>*);
void preorder(TreeNode<int>*);
int leafNodesInTheTree(TreeNode<int>*);
void printAtLevelK(TreeNode<int>*, int);
// int heigthOfTree(TreeNode<int> *root);
int lengthOfTree(TreeNode<int>*);
TreeNode<int>* takeInputLevelWise();
TreeNode<int>* takeInput();
void printTree(TreeNode<int>*);

int main() {

    // TreeNode<int> *root = takeInput();
    TreeNode<int> *root = takeInputLevelWise();

    printTree(root);

    cout << "The Length of the entered tree is : " << lengthOfTree(root) << endl;

    printAtLevelK(root, 2);

    cout << "Total number of leaf nodes are : " << leafNodesInTheTree(root) << endl;

    preorder(root);
    cout << endl;

    deleteTree(root);
    
    return 0;
}

TreeNode<int>* takeInput() {
    int value;
    cout << "Enter data : ";
    cin >> value;

    TreeNode<int> *root = new TreeNode<int>(value);

    int n;
    cout << "Enter no. of children for " << value << " : ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;

}

void printTree(TreeNode<int> *root) {

    if(root == NULL) {
        return;
    }

    cout << root->data << " : ";
    for(int i = 0; i < root->children.size(); i++) {
        if(i == root->children.size()-1) {
            cout << root->children[i]->data;
        } else {
            cout << root->children[i]->data << ", ";
        }
    }
    cout << endl;
    for(int i=0;i<root->children.size();i++) {
        printTree(root->children[i]);
    }
}

TreeNode<int>* takeInputLevelWise() {
    int value;
    cout << "Enter Root Data : ";
    cin >> value;
    TreeNode<int> *root = new TreeNode<int>(value);

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode<int> *front = q.front();
        q.pop();

        int numChild;
        cout << "Enter no. of childs of " << front->data << " : ";
        cin >> numChild;

        for(int i = 0; i < numChild; i++) {
            int childData;
            cout << "Enter " << i+1 << "th value of " << front->data << " : ";
            cin >> childData;
            TreeNode<int> *childTreeNode = new TreeNode<int>(childData);
            front->children.push_back(childTreeNode);
            q.push(childTreeNode);
        }
    }
    return root;
}

int lengthOfTree(TreeNode<int> *root) {
    int answer = 1;
    for(int i = 0; i < root->children.size(); i++) {
        answer += lengthOfTree(root->children[i]);
    }
    return answer;
}

// int heigthOfTree(TreeNode<int> *root) {}

void printAtLevelK(TreeNode<int> *root, int k) {
    if(root == NULL) {
        return;
    }
    if (k == 0) {
        cout << root->data << endl;
        return;
    }
    for(int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k-1);
    }
}

int leafNodesInTheTree(TreeNode<int> *root) {
    if(root->children.size() == 0) {
        return 1;
    }
    int answer = 0;
    for(int i = 0; i < root->children.size(); i++) {
        answer += leafNodesInTheTree(root->children[i]);
    }
    return answer;
}

void preorder(TreeNode<int> *root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    for(int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i]);
    }
}

// void postorder(TreeNode<int> *root) {}

void deleteTree(TreeNode<int> *root) {
    for(int i = 0; i < root->children.size(); i++) {
        deleteTree(root->children[i]);
    }
    delete root;
}