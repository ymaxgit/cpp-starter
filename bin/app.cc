#include <iostream>

#include "library.hh"

using namespace std;

void checkKey(Cache<std::string, int> &cache, string key) {
    auto v = cache.get(key);
    if (v != nullptr) {
      cout << "hit for : " << key << ", value: " << *v << endl;
    } else {
      cout << "miss for: " << key << endl;
    }
}

int main(void)
{
    Cache<std::string, int> cache(2);

    string key1 = "hello1";
    string key2 = "hello2";
    string key3 = "hello3";

    cout << "# Test Get/Set" << endl;
    cache.set(key1, 10);
    checkKey(cache, key1);

    cout << endl << "# Test Delete" << endl;
    bool b = cache.remove(key1);
    cout << "removed? " << b << endl;
    checkKey(cache, key1);

    cout << endl << "# Test LRU" << endl;
    cache.set(key1, 10);
    cache.set(key2, 10);
    checkKey(cache, key1);
    cache.set(key3, 10);

    checkKey(cache, key1);
    checkKey(cache, key2);
    checkKey(cache, key3);
}
