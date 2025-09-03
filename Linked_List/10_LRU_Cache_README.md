Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

1. PUT x y: sets the value of the key x with value y
2. GET x: gets the value of key x if present else returns -1.
The LRUCache class has two methods get() and put() which are defined as follows.

1. get(key): returns the value of the key if it already exists in the cache otherwise returns -1.
2. put(key, value): if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should remove the least recently used item before inserting the new item.
3. In the constructor of the class the capacity of the cache should be initialized.
