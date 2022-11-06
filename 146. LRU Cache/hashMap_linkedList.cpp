#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode1 {
    int key;
    int val;
    ListNode1 *next;

    ListNode1(int k, int v) : key(k), val(v), next(NULL) {}
};

class LRUCache {
private:
    int size;
    ListNode1 *head, *bottom;
    unordered_map<int, ListNode1*> map;
    void refreshNode(int &key);
public:
    LRUCache(int capacity) : size(capacity) {
        head = new ListNode1(0, 0);
        bottom = head;
    }

    int get(int key) {
        auto iter = map.find(key);
        if (iter == map.end()) return -1;
        refreshNode(key);
        return iter->second->next->val;
    }

    void put(int key, int value) {
        auto iter = map.find(key);
        if (iter != map.end()) {
            iter->second->next->val = value;
            refreshNode(key);
        } else {
            map[key] = head;
            ListNode1 *temp = new ListNode1(key, value);
            temp->next = head->next;
            head->next = temp;
            if (temp->next) map[temp->next->key] = temp;
            else bottom = temp;
            if (size < map.size()) {
                int keyTemp = bottom->key;
                delete bottom;
                bottom = map[keyTemp];
                map.erase(keyTemp);
                bottom->next = nullptr;
            }
        }
    }
};

void LRUCache::refreshNode(int &key) {
    if (map[key] == head) return;

    ListNode1 *temp = map[key]->next;
    if (temp->next) map[temp->next->key] = map[key];
    else bottom = map[key];
    map[key]->next = temp->next;
    temp->next = head->next;
    map[head->next->key] = temp;
    head->next = temp;
    map[key] = head;
}

int main() {
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    cout << obj->get(1) << endl;
    obj->put(3, 3);
    cout << obj->get(2) << endl;
    obj->put(4, 4);
    cout << obj->get(1) << endl;
    cout << obj->get(3) << endl;
    cout << obj->get(4) << endl;
    return 0;
}
