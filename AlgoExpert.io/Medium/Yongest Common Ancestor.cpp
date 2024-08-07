#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree* ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree*> descendants) {
    for (AncestralTree* descendant : descendants) {
      descendant->ancestor = this;
    }
  }
};

int getDepth(AncestralTree* descendant) {
  int depth = 0;
  while (descendant != nullptr) {
    descendant = descendant->ancestor;
    depth++;
  }
  return depth;
}

AncestralTree* getYoungestCommonAncestorBruteForiuce(
  AncestralTree* topAncestor,
  AncestralTree* descendantOne,
  AncestralTree* descendantTwo
) {
  // Write your code here.
  // basically topAncestor = root
  // DesendentOne = x
  // Desendenttwo = y
  unordered_map<char,char> hash;
  // traverse first desendent
  while(descendantOne != topAncestor){
    hash.insert({descendantOne->name,descendantOne->name});
    descendantOne = descendantOne->ancestor;
  }
 hash.insert({topAncestor->name,topAncestor->name});

  while(descendantTwo != nullptr){
    if(hash.count(descendantTwo->name)) return descendantTwo;
    descendantTwo = descendantTwo->ancestor;
  }
  return nullptr;
}

AncestralTree* getYoungestCommonAncestor(
  AncestralTree* topAncestor,
  AncestralTree* descendantOne,
  AncestralTree* descendantTwo
) {
  int descentOneDepth = getDepth(descendantOne);
  int descentTwoDepth = getDepth(descendantTwo);

  // Align the depths
  while (descentOneDepth > descentTwoDepth) {
    descendantOne = descendantOne->ancestor;
    descentOneDepth--;
  }

  while (descentTwoDepth > descentOneDepth) {
    descendantTwo = descendantTwo->ancestor;
    descentTwoDepth--;
  }

  // Move up the tree simultaneously
  while (descendantOne != descendantTwo) {
    descendantOne = descendantOne->ancestor;
    descendantTwo = descendantTwo->ancestor;
  }

  return descendantOne;
}

int main() {
  // Creating the ancestral tree nodes
  AncestralTree* A = new AncestralTree('A');
  AncestralTree* B = new AncestralTree('B');
  AncestralTree* C = new AncestralTree('C');
  AncestralTree* D = new AncestralTree('D');
  AncestralTree* E = new AncestralTree('E');
  AncestralTree* F = new AncestralTree('F');
  AncestralTree* G = new AncestralTree('G');
  AncestralTree* H = new AncestralTree('H');
  AncestralTree* I = new AncestralTree('I');

  // Building the tree
  A->addAsAncestor({B, C});
  B->addAsAncestor({D, E});
  C->addAsAncestor({F, G});
  D->addAsAncestor({H, I});

  // Test cases
  AncestralTree* youngestCommonAncestor;

  youngestCommonAncestor = getYoungestCommonAncestor(A, E, I);
  cout << "Youngest Common Ancestor of E and I: " << youngestCommonAncestor->name << endl;

  youngestCommonAncestor = getYoungestCommonAncestorBruteForiuce(A, F, G);
  cout << "Youngest Common Ancestor of F and G: " << youngestCommonAncestor->name << endl;

  youngestCommonAncestor = getYoungestCommonAncestor(A, H, C);
  cout << "Youngest Common Ancestor of H and C: " << youngestCommonAncestor->name << endl;

  youngestCommonAncestor = getYoungestCommonAncestorBruteForiuce(A, D, G);
  cout << "Youngest Common Ancestor of D and G: " << youngestCommonAncestor->name << endl;

  // Clean up memory
  delete A;
  delete B;
  delete C;
  delete D;
  delete E;
  delete F;
  delete G;
  delete H;
  delete I;

  return 0;
}