/*A binary tree node
struct Node
{
    int data;
    Node* left, *right;
};
 */

vector<int> diagonal(Node *root)
{
	// your code here
	// Your Code Here	//Your code here
	// base case

	vector<int> ans;

	if (root == NULL) return ans;

	queue<Node*> que;

	que.push(root);	// start with 0

	while (!que.empty())
	{
		auto currNode = que.front();
		que.pop();
		// check if alrewady any element is add for horizontal distance
		//ans.push_back(currNode->data);

		while (currNode != NULL)
		{
			if (currNode->left != NULL)
				que.push(currNode->left);

			ans.push_back(currNode->data);
			currNode = currNode->right;
		}
	}

	// we don't need to sort since we are using map
	// for(auto &x : hash) ans.push_back(x.second);

	return ans;
}