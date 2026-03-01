// 1.03.2026 
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    int m;
    std::cin >> m;
    
    std::vector<int> heap;
    heap.reserve(m);
    
    for (int i = 0; i < m; ++i) {
        int num;
        std::cin >> num;
        heap.push_back(num);
    }
    
    // Построить max-heap
    std::make_heap(heap.begin(), heap.end());
    
    int q;
    std::cin >> q;
    
    std::vector<int> popped_values;
    
    for (int i = 0; i < q; ++i) {
        std::string cmd;
        std::cin >> cmd;
        
        if (cmd == "push") {
            int x;
            std::cin >> x;
            heap.push_back(x);
            std::push_heap(heap.begin(), heap.end());
        } else if (cmd == "pop") {
            std::pop_heap(heap.begin(), heap.end());
            int max_val = heap.back();
            heap.pop_back();
            popped_values.push_back(max_val);
        }
    }
    
    // Вывод извлеченных элементов
    for (size_t i = 0; i < popped_values.size(); ++i) {
        std::cout << popped_values[i] << " ";
       
    }
    std::cout << std::endl;
    
    // Сортировка оставшихся элементов по возрастанию
    std::sort_heap(heap.begin(), heap.end());
    
    // Вывод оставшихся элементов
    for (size_t i = 0; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
       
    }
  
    std::cout << std::endl;
    
    return 0;
}