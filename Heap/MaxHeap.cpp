/**
 * Basic Implementation of heap
 * Heap -> Heap is a complete binary tree and follows heap order property
 * Complete Binry tree -> every level is completly filled expect last level. Its is filled from left to right
 * Heap Property -> 1.Max Heap(max element on top) 2.Min Heap(min element on top)
*/

#include <iostream>
#include <vector>

// Implemenation of max Heap
// this implementation is 0 indexed based array
class MaxHeap {
private:
    std::vector<int> heap;

public:
    MaxHeap();
    void push(int);
    void print();
    void pop();
    int top();
    void heapify(std::vector<int>&, int);
    void heapify(std::vector<int>&, int, int);
    void heapSort();
};

MaxHeap::MaxHeap() {} // no use

void MaxHeap::push(int x)
{

    // push to last element
    this->heap.push_back(x);

    int size = this->heap.size();

    // apply heapify to maintain heap property
    // i = size/2 will give last leaf node of tree
    for (int i = size / 2; i >= 0; i--)
        this->heapify(this->heap, i);

    return;
}

void MaxHeap::print()
{
    for (auto elem : this->heap)
        std::cout << elem << " ";
    std::cout << "\n";
    return;
}

int MaxHeap::top()
{
    if (this->heap.size() == 0)
        return -1;
    return this->heap[0];
}

void MaxHeap::pop()
{

    // step 0 if size is zero
    if (this->heap.size() == 0)
        return;

    //Step 1 swap last node with root
    std::swap(this->heap[0], this->heap[this->heap.size()]);

    //step 2 Remove last node
    this->heap.pop_back();

    //step 3
    this->heapify(this->heap, 0);

    return;
}

void MaxHeap::heapify(std::vector<int>& heap, int element)
{

    int curr = element;
    int left = 2 * curr + 1; // if 0 based index used this else if 1 based index use (2 * curr)
    int right = 2 * curr + 2; // if 0 based index used this else if 1 based index use (2 * curr + 1)
    int heapSize = heap.size(); // size of curr heap

    // check if left is largest if yes change curr to left
    if (left <= heapSize && heap[left] > heap[curr])
        curr = left;

    //check if right is largest if yes change curr to right
    if (right <= heapSize && heap[right] > heap[curr])
        curr = right;

    // if element and curr are not change just return
    if (curr != element) {
        std::swap(heap[curr], heap[element]);
        heapify(heap, curr);
    }
    return;
}

void MaxHeap::heapify(std::vector<int>& heap, int element, int heapSize)
{

    int curr = element;
    int left = 2 * curr + 1; // if 0 based index used this else if 1 based index use (2 * curr)
    int right = 2 * curr + 2; // if 0 based index used this else if 1 based index use (2 * curr + 1)

    // check if left is largest if yes change curr to left
    if (left <= heapSize && heap[left] > heap[curr])
        curr = left;

    //check if right is largest if yes change curr to right
    if (right <= heapSize && heap[right] > heap[curr])
        curr = right;

    // if element and curr are not change just return
    if (curr != element) {
        std::swap(heap[curr], heap[element]);
        heapSize--;
        this->heapify(heap, curr, heapSize);
    }
    return;
}

void MaxHeap::heapSort()
{

    int size = this->heap.size() - 1;

    while (size >= 0) {

        // step 1 swap first element to last element
        std::swap(this->heap[0], this->heap[size]);
        size--;

        // step 2 apply heapyfy
        this->heapify(heap, 0, size);
    }

    return;
}

int main()
{
    MaxHeap heap;
    heap.push(5);
    heap.push(6);
    heap.push(10);
    std::cout << heap.top() << "\n";
    heap.pop();
    std::cout << heap.top() << "\n";
    heap.push(17);
    heap.push(99);
    heap.push(56);
    heap.push(80);
    heap.print();
    heap.heapSort();
    heap.print();
    std::cout << "\n";
}