class Solution:
    def cover(self, t_cnt: dict, window: dict) -> bool:
        for k, v in t_cnt.items():
            if window.get(k, 0) < v:
                return False
        return True

    def minWindow(self, s: str, t: str) -> str:
        t_cnt = {c: t.count(c) for c in t}
        window = dict()
        min_len = 100001
        start = -1
        l, r = 0, 0
        for r in range(len(s)):
            if s[r] in t_cnt.keys():
                window[s[r]] = window.get(s[r], 0) + 1
            while self.cover(t_cnt, window) and l <= r:
                cur_len = r - l + 1
                if cur_len < min_len:
                    min_len = cur_len
                    start = l
                window[s[l]] = window.get(s[l], 0) - 1
                l += 1
        return "" if start == -1 else s[start : start + min_len]


if __name__ == "__main__":
    s = "ADOBECODEBANC"
    t = "ABC"
    obj = Solution()
    print(obj.minWindow(s, t))
