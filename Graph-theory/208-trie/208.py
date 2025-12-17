class Trie:

    def __init__(self):
        self._root: dict[str, dict] = {}
        self._end = "#"

    def insert(self, word: str) -> None:
        cur_node = self._root
        for ch in word:
            if ch not in cur_node:
                cur_node[ch] = {}
            cur_node = cur_node[ch]
        cur_node[self._end] = {}

    def search(self, word: str) -> bool:
        cur_node = self._root
        for ch in word:
            if ch not in cur_node:
                return False
            cur_node = cur_node[ch]
        return self._end in cur_node

    def startsWith(self, prefix: str) -> bool:
        cur_node = self._root
        for ch in prefix:
            if ch not in cur_node:
                return False
            cur_node = cur_node[ch]
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)