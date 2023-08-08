
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class SegmentTree
{
  int *tree = NULL; // The array representing the segment tree
  int size = 0;     // Total size of the segment tree array
  int height = 0;   // Height of the segment tree

public:
  SegmentTree(int);
  int construct(int *, int);
  int getSum(int, int, int);
  void update(int, int, int *, int);
  void printTree();
};

// Constructor to initialize the SegmentTree class
SegmentTree::SegmentTree(int n)
{
  // Calculate the height of the segment tree (log2(N+1) base 2)
  this->height = (int)(ceil(log2(n)));

  // Calculate the total size of the segment tree array
  this->size = 2 * (int)pow(2, this->height) - 1;

  // Create an array to represent the segment tree and initialize all elements to -1 (undefined or null)
  int *arr = new int[this->size];
  for (int i = 0; i < this->size; i++)
    arr[i] = -1;

  this->tree = arr;
}

// Function to construct the segment tree recursively
int constructTree(int curr, int min, int max, int *arr, int *tree)
{
  // Base case: if it's a leaf node
  if (max == min)
  {
    tree[curr] = arr[min];
    return arr[min];
  }

  // Calculate the middle index of the current range
  int mid = min + (max - min) / 2;

  // Recursively construct the left and right subtrees
  tree[curr] = constructTree((curr * 2) + 1, min, mid, arr, tree) + constructTree((curr * 2) + 2, mid + 1, max, arr, tree);

  // Return the value for the current node
  return tree[curr];
}

// Function to construct the segment tree
int SegmentTree::construct(int *arr, int n)
{
  // Call the recursive function to construct the segment tree starting from the root node (index 0)
  constructTree(0, 0, n - 1, arr, this->tree);
  return 0;
}

// Function to get the sum of elements in a given range [endMin, endMax]
int getSumRange(int endMin, int endMax, int min, int max, int curr, int *tree)
{
  // Case 1: Completely in range, return the value at the current node
  if (endMin <= min && endMax >= max)
    return tree[curr];

  // Case 2: Completely out of range, return 0
  if (endMin > max || endMax < min)
    return 0;

  // Case 3: Partial overlap, so recursively find the sum in left and right subtrees
  int mid = min + (max - min) / 2;
  return getSumRange(endMin, endMax, min, mid, (2 * curr) + 1, tree) + getSumRange(endMin, endMax, mid + 1, max, (2 * curr) + 2, tree);
}

// Function to get the sum of elements in the range [endMin, endMax]
int SegmentTree::getSum(int endMin, int endMax, int siz)
{
  // Base case: If the given range is invalid, return -1 (error)
  if (endMin > endMax)
    return -1;

  // Call the helper function to find the sum in the specified range
  return getSumRange(endMin, endMax, 0, siz - 1, 0, this->tree);
}

// Function to update an element in the array and the corresponding segment tree
void updateRange(int *tree, int index, int diff, int min, int max)
{
  // Base case: If the index is out of range, return
  if (index < min || index > max)
    return;

  // Update the current node with the difference (new_val - old_val)
  tree[index] += diff;

  // If the current node is not a leaf node, update its children recursively
  if (min != max)
  {
    int mid = min + (max - min) / 2;

    // Update left subtree
    updateRange(tree, 2 * index + 1, diff, min, mid);

    // Update right subtree
    updateRange(tree, 2 * index + 2, diff, mid + 1, max);
  }
}

// Function to update an element in the array and the corresponding segment tree
void SegmentTree::update(int index, int new_val, int *arr, int n)
{
  // Check if the given index is within the valid range of the segment tree
  if (index < 0 || index > this->size - 1)
    return;

  // Calculate the difference between the new value and the old value
  int diff = new_val - arr[index];

  // Update the array with the new value
  arr[index] = new_val;

  // Update the segment tree with the difference
  updateRange(this->tree, index, diff, 0, n - 1);
}

// Function to print the elements of the segment tree
void SegmentTree::printTree()
{
  for (int i = 0; i < this->size - 1; i++)
  {
    cout << this->tree[i] << " ";
  }
  cout << "\n";
  return;
}

int main()
{
  int siz = 5;
  int *arr = new int[siz];
  for (int i = 0; i < siz; i++)
    arr[i] = i + 1;

  SegmentTree *ST = new SegmentTree(siz);
  ST->construct(arr, siz);

  cout << ST->getSum(0, 2, siz) << "\n"; // Output: 6 (sum of elements in the range [0, 2])
  
  ST->update(0, 10, arr, siz); // Update the value at index 0 to 10

  cout << ST->getSum(0, 2, siz) << "\n"; // Output: 16 (sum of elements in the range [0, 2] after the update)
  
  delete[] arr; // Clean up the memory
  delete ST;
  return 0;
}

/*

Explanation:
The code implements a basic Segment Tree data structure for efficient range query operations (in this case, sum of elements in a given range) and element updates.
The SegmentTree class encapsulates the functionality of the data structure.
The constructTree function recursively constructs the segment tree by splitting the array into smaller segments until leaf nodes are reached.
The getSumRange function efficiently calculates the sum of elements in the given range by traversing the segment tree based on three cases: completely in range, completely out of range, or partially overlapping.
The updateRange function updates the segment tree nodes accordingly when an element in the array is modified.
The printTree function is used to display the elements of the segment tree (excluding the last element, which is initialized to -1).
Note: The code also includes a main function to demonstrate the usage of the Segment Tree for range sum queries and updates. It creates a simple array and initializes a Segment Tree using it. Then, it performs a range sum query and an element update, displaying the results accordingly.

*/