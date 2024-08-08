#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// MinHeap class definition (same as the one you provided)
class MinHeap {
 public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }

  vector<int> buildHeap(vector<int>& vector) {
    int firstParentIdx = std::floor((vector.size() - 2) / 2);
    for (int i = firstParentIdx; i >= 0; i--) {
      siftDown(i, vector.size() - 1, vector);
    }
    return vector;
  }

  void siftDown(int currentIdx, int endIdx, vector<int>& heap) {
    int childOne = (currentIdx * 2) + 1;
    while (childOne <= endIdx) {
      int childTwo = (currentIdx * 2) + 2;
      int idxSwap;
      if (childTwo <= endIdx && heap[childTwo] < heap[childOne]) {
        idxSwap = childTwo;
      } else {
        idxSwap = childOne;
      }
      if (heap[currentIdx] > heap[idxSwap]) {
        std::swap(heap[currentIdx], heap[idxSwap]);
        currentIdx = idxSwap;
        childOne = (currentIdx * 2) + 1;
      } else {
        break;
      }
    }
  }

  void siftUp(int currentIdx, vector<int>& heap) {
    int parentIdx = std::floor((currentIdx - 1) / 2);
    while (currentIdx > 0 && heap[currentIdx] < heap[parentIdx]) {
      std::swap(heap[currentIdx], heap[parentIdx]);
      currentIdx = parentIdx;
      parentIdx = std::floor((currentIdx - 1) / 2);
    }
  }

  int peek() {
    return heap[0];
  }

  int remove() {
    int poppedValue = heap[0];
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    siftDown(0, heap.size() - 1, heap);
    return poppedValue;
  }

  void insert(int value) {
    heap.push_back(value);
    siftUp(heap.size() - 1, heap);
  }
};

// Driver function
int main() {
  // Initial heap array
  vector<int> array = {48, 12, 24, 7, 8, 23, -5, 16};

  // Create a MinHeap from the array
  MinHeap minHeap(array);

  // Print the heap after building it
  cout << "Heap after building: ";
  for (int val : minHeap.heap) {
    cout << val << " ";
  }
  cout << endl;

  // Peek the minimum value
  cout << "Peek: " << minHeap.peek() << endl;

  // Remove the minimum value
  int removed = minHeap.remove();
  cout << "Removed: " << removed << endl;

  // Print the heap after removal
  cout << "Heap after removal: ";
  for (int val : minHeap.heap) {
    cout << val << " ";
  }
  cout << endl;

  // Insert a new value
  minHeap.insert(10);
  cout << "Heap after inserting 10: ";
  for (int val : minHeap.heap) {
    cout << val << " ";
  }
  cout << endl;

  return 0;
}