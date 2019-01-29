template <class K, class V>
class HashMap {
private:

  class HashNode {
  public:
    K key;
    V value;
    HashNode *next;

    HashNode(K k, V v) : key(k), value(v), next(nullptr) {}
  };

  vector<HashNode *> map;
  int capacity;

  int getHash(K key) {
    return key % capacity;
  }

public:
  HashMap() : capacity(256) {
    map = vector<HashNode *>(capacity);
  }

  V get(K key) {
    int hashCode = getHash(key);
    const auto *node = map[hashCode];

    while (node) {
      if (node->key == key)
        return node->value;
    }
    return nullptr;
  }

  bool put(K key, V value) {
    int hashCode = getHash(key);
    const auto *node = map[hashCode];

    while (node && node->next) {
      if (node->key == key)
        return false;
      node = node->next;
    }

    if (!node) {
      map[hashCode] = new HashNode(key, value);
      return true;
    }

    if (node->key == key)
      return false;

    node->next = new HashNode(key, value);
    return true;
  }
};
