#include "lru_cache.h"
#include <iostream>

int main() {
  LRU::lru<int, int> cache(4); // Cache capacity of 2
    cache.put(1,-6);
    cache.put(2, -4);
    cache.put(3, 8);
    cache.put(7,2);
    std::cout<< "value: "<<(cache.get(2) ? *cache.get(2) : -1)<< std::endl;
    cache.print();
    
    cache.put(3, 3); // evicts 2
    std::cout << "value: "<< (cache.get(2) ? *cache.get(2) : -1) << std::endl;
    cache.print();
    
    cache.put(4, 4); // evicts 1
    std::cout << "value: "<<(cache.get(1) ? *cache.get(1) : -1) << std::endl;
    cache.print();
    std::cout << "value: "<<(cache.get(3) ? *cache.get(3) : -1) << std::endl;
    cache.print();
    std::cout << "value: "<< (cache.get(7) ? *cache.get(4) : -1) << std::endl;
    cache.print();
  return 0;
}