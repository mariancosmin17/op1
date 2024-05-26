#include <cstdio>
#include <tuple>

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        int index;
        Node(K k, V v, Node* n, int i) : key(k), value(v), next(n), index(i) {}
    };

    Node* head;
    int size;

    Node* find(const K& key) const {
        Node* current = head;
        while (current) {
            if (current->key == key)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    Node* find_prev(const K& key) const {
        Node* current = head;
        Node* prev = nullptr;
        while (current) {
            if (current->key == key)
                return prev;
            prev = current;
            current = current->next;
        }
        return nullptr;
    }

public:
    Map() : head(nullptr), size(0) {}

    ~Map() { Clear(); }

    V& operator[](const K& key) {
        Node* node = find(key);
        if (node) {
            return node->value;
        }
        else {
            Node* newNode = new Node(key, V(), head, size);
            head = newNode;
            size++;
            return head->value;
        }
    }

    bool Get(const K& key, V& value) const {
        Node* node = find(key);
        if (node) {
            value = node->value;
            return true;
        }
        return false;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        Node* current = head;
        while (current) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
        head = nullptr;
        size = 0;
    }

    bool Delete(const K& key) {
        Node* prev = find_prev(key);
        if (!prev) {
            if (head && head->key == key) {
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
                size--;
                return true;
            }
            return false;
        }
        Node* toDelete = prev->next;
        if (toDelete) {
            prev->next = toDelete->next;
            delete toDelete;
            size--;
            return true;
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) const {
        Node* current = map.head;
        while (current) {
            Node* node = find(current->key);
            if (!node || node->value != current->value)
                return false;
            current = current->next;
        }
        return true;
    }

    struct Iterator {
        Node* node;
        Iterator(Node* n) : node(n) {}
        bool operator!=(const Iterator& other) const { return node != other.node; }
        void operator++() { if (node) node = node->next; }
        auto operator*() const { return std::tie(node->key, node->value, node->index); }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

int main() {
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
