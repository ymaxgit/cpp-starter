#ifndef LIBRARY_HH
#define LIBRARY_HH

#include <iostream>
#include <list>
#include <map>

int example(int x);

template <class K, class V>
class Cache {
public:
  struct KV {
    K key;
    V value;
  };

  Cache(int size);

  bool set(K key, V value);
  V* get(K key);
  bool remove(K key);
  void clear();

  using map_value = typename std::list<KV>::iterator;

private:
  int limit;
  std::map<K,map_value> map;
  std::list<KV> evict;
};

template <class K, class V>
Cache<K,V>::Cache(int size)
  : limit{size}
  , map{}
  , evict{}
{
}

template <class K, class V>
bool Cache<K,V>::set(K key, V value)
{
  // find existing in map
  auto mIX = map.find(key);

  // if exists, delete from LRU
  if (mIX != map.end()) {
    evict.erase(mIX->second);
  }

  // store at end of LRU
  evict.push_back({key, value});
  map_value lIX = --evict.end();

  // store in map
  map[key] = lIX;

  // check limit and evict
  if (map.size() > limit) {
    lIX = evict.begin();
    map.erase(lIX->key);
  }
}

template <class K, class V>
V* Cache<K,V>::get(K key)
{
  auto mIX = map.find(key);
  if (mIX == map.end()) {
    return nullptr;
  }

  auto lIX = mIX->second;
  KV kv = *lIX;
  evict.erase(lIX);
  evict.push_back(kv);
  lIX = --evict.end();

  return &lIX->value;
}

template <class K, class V>
bool Cache<K,V>::remove(K key)
{
  auto mIX = map.find(key);
  if (mIX == map.end()) {
    return false;
  }

  evict.erase(mIX->second);
  map.erase(mIX);
  return true;
}

template <class K, class V>
void Cache<K,V>::clear()
{
  map.clear();
  evict.clear();
}

#endif /* LIBRARY_HH */
