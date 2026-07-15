class Node:
    def __init__(self, v):
        self.v = v
        self.l = None
        self.r = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.head = Node(None)
        self.tail = Node(None)
        self.head.r = self.tail
        self.tail.l = self.head
        self.d = {}
        self.n = {}

    def _append(self, v):
        v.r = self.tail
        v.l = self.tail.l
        self.tail.l.r = v
        self.tail.l = v
    
    def _unlink(self, v):
        v.r.l = v.l
        v.l.r = v.r

    def get(self, key: int) -> int:
        if key in self.n:
            cn = self.n[key]
            self._unlink(cn)
            self._append(cn)
        return self.d.get(key, -1)

    def put(self, key: int, value: int) -> None:
        if key not in self.d and len(self.d) + 1 > self.cap:
            # evict
            to_evict = self.head.r
            self._unlink(to_evict)
            del self.d[to_evict.v]
            del self.n[to_evict.v]

        self.d[key] = value
        
        if key in self.n:
            cn = self.n[key]
            self._unlink(cn)
        else:
            cn = Node(key)
        self._append(cn)
        self.n[key] = cn
        



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)