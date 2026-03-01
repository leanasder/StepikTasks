//1.03.2026

#include <iostream>
#include <vector>
#include <algorithm>

// mergin two max-heap in one
std::vector<int> mergeHeaps(const std::vector<int>& heap1, 
                            const std::vector<int>& heap2) {
    std::vector<int> result = heap1;               
    result.insert(result.end(), heap2.begin(), heap2.end()); 
    std::make_heap(result.begin(), result.end()); 
    return result;
}

// removing k times max element from heap and print the result
void printKMax(std::vector<int>& heap, int k) {
    
    for (int i = 0; i < k && !heap.empty(); ++i) {
        std::pop_heap(heap.begin(), heap.end()); // max in temp.back()
        std::cout << heap.back() << " ";
        heap.pop_back();
    }
}

int main() {
    // getting first heap == heap1
    int n;
    std::cin >> n;

    std::vector<int> heap1;
    heap1.reserve(n);

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        heap1.push_back(num);
    }

    // getting second heap == heap2;
    int m;
    std::cin >> m;

    std::vector<int> heap2;
    heap2.reserve(m);

    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;
        heap2.push_back(num);
    }

    //merging heap1 and heap2
    auto mergedHeap = mergeHeaps(heap1, heap2);

    // adding number x
    int x;
    std::cin >> x;
    mergedHeap.push_back(x);

    // Find the k maximum elements and print them.
    int k;
    std::cin >> k;
    printKMax(mergedHeap, k);

    // Sort heap
    sort(mergedHeap.begin(), mergedHeap.end());

    // Print the result
    for (auto& x: mergedHeap) {
        std:: cout << x << ' ';
    }

}