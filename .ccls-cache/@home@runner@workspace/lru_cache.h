#pragma once
#include <iostream>
#include <optional>
#include <unordered_map>

namespace LRU {

template <typename K, typename V> class lru {
private:
  struct Node {
    K key;
    V value;
    Node *prev;
    Node *next;

    Node(K k, V v) {
      key = k;
      value = v;
      prev = nullptr;
      next = nullptr;
    }
  };

  int capacity;
  std::unordered_map<K, Node *> mp;
  Node *head;
  Node *tail;

  void inserthead(Node *node) {
    // Insert the node after the dummy head
    Node *temp = head->next;
    head->next = node;
    node->prev = head;
    node->next = temp;
    temp->prev = node;
  }

  void removenode(Node *node) {
    // Remove the node from the list
    Node *prevNode = node->prev;
    Node *nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
  }

public:
  lru(int capacity) {
    this->capacity = capacity;
    head = new Node(K(), V());
    tail = new Node(K(), V());
    head->next = tail;
    tail->prev = head;
  }

  ~lru() {
    // clean up the nodes except the dummy head and tail
    Node *current = head->next;
    while (current != tail) {
      Node *next = current->next;
      delete current;
      current = next;
    }
    delete head;
    delete tail;
  }

  std::optional<V> get(K key) {
    // check if key exists and then return the value. else return -1.
    if (mp.find(key) != mp.end()) {
      Node *node = mp[key];
      removenode(node);
      inserthead(node);
      return node->value;
    }
    return std::nullopt;
  }

  void put(K key, V value) {
    if (capacity <= 0)
      return;
    // check if key exists, yes, then update, no then check the capacity and add
    // the new node.
    if (mp.find(key) != mp.end()) {
      Node *node = mp[key];
      node->value = value;
      removenode(node);
      inserthead(node);
    } else {
      if (mp.size() == capacity) {
        Node *lastnode = tail->prev;
        removenode(lastnode);
        mp.erase(lastnode->key);
        delete lastnode;
      }

      Node *newnode = new Node(key, value);
      inserthead(newnode);
      mp[key] = newnode;
    }
  }

  size_t size() { return mp.size(); }

  bool empty() { return mp.empty(); }

  void print() {
    Node *curr = head->next;
    std::cout << "LRU Cache Contents:" << std::endl;
    while (curr != tail) {
      std::cout << "key: " << curr->key << " "
                << "value: " << curr->value << std::endl;
      curr = curr->next;
    }
    std::cout << std::endl;
  }
};

} // namespace LRU
