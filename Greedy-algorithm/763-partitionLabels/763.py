from typing import List


class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        results: list[int] = [1]
        partitions: list[set[str]] = [set(s[0])]
        for x in range(1, len(s)):
            ch = s[x]
            if ch in partitions[-1]:
                results[-1] += 1
                continue
            is_new_ch = True
            for i in range(len(partitions)-2, -1, -1):
                if ch in partitions[i]:
                    new_partition = set()
                    new_len = 1
                    for j in range(i, len(partitions)):
                        new_partition |= partitions[j]
                        new_len += results[j]
                    partitions[i] = new_partition
                    partitions = partitions[: i + 1]
                    results[i] = new_len
                    results = results[: i + 1]
                    is_new_ch = False
                    break
            if is_new_ch:
                partitions.append(set(ch))
                results.append(1)
        return results


class Solution2:
    def partitionLabels(self, s: str) -> List[int]:
        results = []
        last_pos = {ch: i for i, ch in enumerate(s)}
        start = end = 0
        for i, ch in enumerate(s):
            end = max(end, last_pos[ch])
            if i == end:
                results.append(end - start + 1)
                start = i + 1
        return results



if __name__ == "__main__":
    s = Solution()
    s.partitionLabels("ababcbacadefegdehijhklij")
