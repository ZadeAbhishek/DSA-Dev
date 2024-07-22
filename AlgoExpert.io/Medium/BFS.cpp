#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string>* array) {
    // Write your code here.
    queue<Node*> que;
    que.push(this);
    while(!que.empty()){
      Node* currNode = que.front();
      que.pop();
      array->push_back(currNode->name);
      for(auto nextNode : currNode->children){
        que.push(nextNode);
      }
    }
    
    return *array; // we are getting pointer so we are sending back pointer only
  }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};
