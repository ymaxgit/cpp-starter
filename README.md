# Project

This is a project.

## Cache

Caching library:

* `key-value` pairs.
* `set(key, value) bool`
* `get(key) *value`
* `delete(key) bool`
* `deleteAll() void`

* `all() []key-value` -- iterators

With configurable eviction policy. For example:

* Least-recently-used.
* FIFO (insertion order).

When to evict:

* When number of keys exceeds a configurable maximum.

### Use-Cases

Without caching:

```
func handleRequest(conn, req):
  resp := slow_build_response_path(req)
  write(conn, resp)
```

With caching:

```
var cache Cache

func handleRequest(conn, req):
  key := derive_key(req)
  resp := cache.get(key)
  if resp == nil {
    resp := slow_build_response_path(req)
    cache.set(key, resp)
  }
  write(conn, resp)
```

## Building

This project uses automake and autoconf for its build system. To build:

``` sh
./autogen.sh
./configure
make
```

To package up the binaries, use:

## Authors

This library is written and maintained by David Terei <dterei@cs.stanford.edu>.

## Licensing

This library is BSD-licensed.

