using namespace std;

bool hasSingleCycle(vector<int> array) {
  // Write your code here.
  int totalElements = array.size();
  int currIndex = 0; // we are starting from zero
  int visitedElements = 0;
  while(true){
    visitedElements++;
    currIndex = (currIndex + array[currIndex]) % totalElements;
    currIndex = (currIndex + totalElements) % totalElements;
    // check the currentIndex
    if(currIndex == 0){
      return (visitedElements == totalElements);
    }

    if(visitedElements == totalElements){ return false;}
  }
}
