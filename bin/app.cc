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

    string key = "hello";
    string key2 = "hello2";
    string key3 = "hello3";

    bool b = cache.set(key, 10);
    int *v = cache.get(key);

    if (v != nullptr) {
      cout << *v << endl;
    } else {
      cout << "miss!" << endl;
    }

    b = cache.remove(key);
    cout << "removed? " << b << endl;

    v = cache.get(key);

    if (v != nullptr) {
      cout << *v << endl;
    } else {
      cout << "miss!" << endl;
    }

    b = cache.set(key2, 10);
    checkKey(cache, key);
    b = cache.set(key3, 10);

    checkKey(cache, key);
    checkKey(cache, key2);
    checkKey(cache, key3);
}
