#include<iostream>
#include<unordered_map>
using namespace std;

struct DlinkNode {
	int key;
	int value;
	DlinkNode* prev;
	DlinkNode* next;
	DlinkNode() :key(0), value(0), prev(nullptr), next(nullptr) {}
	DlinkNode(int _key, int _value) :key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
	unordered_map<int, DlinkNode*>	cache;
	DlinkNode* head;
	DlinkNode* tail;
	int capacity;
	int size;

public:
	LRUCache(int _capacity);
	int get(int _key);
	void put(int _key, int _value);
	void addToHead(DlinkNode* node);
	void removeNode(DlinkNode* node);
};

LRUCache::LRUCache(int _capacity):capacity(_capacity),size(0) {
	head = new DlinkNode();
	tail = new DlinkNode();
	head->next = tail;
	tail->prev = head;
}

int LRUCache::get(int _key) {
	if (cache.count(_key)) {
		DlinkNode* node = cache[_key];
		removeNode(node);
		addToHead(node);
		return node->value;
	}

	else return - 1;
}

void LRUCache::put(int _key, int _value) {
	if (cache.count(_key)) {
		cache[_key]->value = _value;
		DlinkNode* node = cache[_key];
		removeNode(node);
		addToHead(node);
	}
	else
	{
		if (size < capacity) {
			DlinkNode* node = new DlinkNode(_key, _value);
			cache[_key] = node;
			addToHead(node);
			size++;
		}
		else {
			DlinkNode* node = new DlinkNode(_key, _value);
			cache.erase(tail->prev->key);
			removeNode(tail->prev);
			addToHead(node);
			cache[_key] = node;
		}
	}
}

void LRUCache::removeNode(DlinkNode* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void LRUCache::addToHead(DlinkNode* node) {
	node->prev = head;
	node->next = head->next;
	head->next->prev = node;
	head->next = node;
}