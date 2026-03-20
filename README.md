#Overview.
* Implemented an LRU (Least Recently Used) cache in C++ using raw pointers and manual memory management.
* Combines a doubly linked list + unordered_map for O(1) get and put operations.
* Focused on pointers, dynamic memory allocation, and memory safety.

#Features.
* get(key) → retrieves value if present, moves node to front (recently used).
* put(key, value) → inserts or updates value, evicts least recently used when capacity is full.
* print() → shows current cache state for debugging.
* Handles any data type with templates (<K,V>).
* Safe memory cleanup in destructor.

#Key Learnings.
* Mastered raw pointer usage and linked list manipulation.
* Practiced memory allocation and deallocation.
* Learned how to integrate hash maps with linked lists for optimal performance.
