#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
#include <algorithm>
void convertToArray(BinaryTreeNode<int> *root, vector<int> &output)
{
    if (root == NULL)
    {
        return;
    }
    output.push_back(root->data);
    convertToArray(root->left, output);
    convertToArray(root->right, output);
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> output;
    convertToArray(root, output);
    sort(output.begin(), output.end());
    int i = 0, j = output.size() - 1;
    while (i < j)
    {
        if (output[i] + output[j] == sum)
        {
            cout << output[i] << " " << output[j]<<endl;
            i++;j--;
        }
        else if (output[i] + output[j] > sum)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
// 5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
// 15