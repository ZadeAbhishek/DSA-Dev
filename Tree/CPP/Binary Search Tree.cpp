// C++ implemenatation for BST
#include <iostream>
using namespace std;

struct Node
{
      int key;
      Node * left;
      Node * right;
      Node() {}
      Node(int x): key(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right): key(x), left(left), right(right) {}
};

void traversal(Node *root)
{
      if (root == NULL) return;
      traversal(root->left);
      cout << root->key << " ";
      traversal(root->right);
      return;
}

void insert(Node *root, int key)
{
     	// check if the root is NULL
      if (root == NULL) return;

     	// not null check the right and left with key value
      Node *curr = root;
      while (true)
      {
           	// if right and left is NUll leag node is found
            if (curr->right == NULL && curr->left == NULL) break;

           	// go to right
            if (key >= curr->key)
            {
                  if (curr->right == NULL) break;
                  curr = curr->right;
            }

           	// go to left
            else
            {
                  if (curr->left == NULL) break;
                  curr = curr->left;
            }
      }

     	// add new node to right or left according to value
      if (key > curr->key) curr->right = new Node(key);
      else curr->left = new Node(key);

      return;
}

Node* search(Node *root, int key)
{
     	// ptr
      Node *curr = root;
      while (curr)
      {
            if (key == curr->key) return curr;
            else if (key > curr->key) curr = curr->right;
            else curr = curr->left;
      }

      return NULL;
}

Node* deleteNode(Node *root, int key)
{
     	// delete using rescurrsion
      if (root == NULL) return NULL;

     	// go to left
      if (key < root->key)
      {
            root->left = deleteNode(root->left, key);
            return root;
      }

     	// go to right
      if (key > root->key)
      {
            root->right = deleteNode(root->right, key);
            return root;
      }

     	// if key is not greter nor smaller then we found element

     	// case 1 check if only one child is present
      if (root->left == NULL)
      {
            Node *temp = root->right;
            delete root;
            return temp;
      }
      else if (root->right == NULL)
      {
            Node *temp = root->left;
            delete root;
            return temp;
      }

     	// case 2 if both children exists
      else
      {
            Node *parent = root;

           	// get successor of root which is always right's left
            Node *child = root->right;
            while (child->left != NULL)
            {
                  parent = child;
                  child = child->left;
            }

           	// gfg explaination
           	// Delete successor.  Since successor
           	// is always left child of its parent
           	// we can safely make successor's right
           	// right child as left of its parent.
           	// If there is no succ, then assign
           	// succ->right to succParent->right

            if (parent != root)
                  parent->left = child->right;
            else
                  parent->right = child->right;

            root->key = child->key;

            delete child;
            return root;
      }
}

int main()
{
      Node *root = new Node(10);
      insert(root, 1);
      insert(root, 15);
      insert(root, 6);
      insert(root, 3);
      insert(root, 7);
      traversal(root);
      cout << "\n";
      deleteNode(root, 15);
      traversal(root);
      cout << "\n";
      deleteNode(root, 3);
      traversal(root);
      cout << "\n";
}