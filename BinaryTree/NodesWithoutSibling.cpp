#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};



BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void printNodesWithoutSibling(BinaryTreeNode<int>* root){
    if(root==NULL){
        return ;
    }
    if(root->left !=NULL && root->right==NULL){
        cout<<root->left->data<<" ";
    }
    if(root->left ==NULL && root->right!=NULL){
        cout<<root->right->data<<" ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    printNodesWithoutSibling(root);
}
// 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1