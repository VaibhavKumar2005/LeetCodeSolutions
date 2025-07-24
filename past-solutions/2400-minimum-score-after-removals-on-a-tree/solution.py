from typing import List
from collections import defaultdict

class Solution:
    def minimumScore(self, nums: List[int], edges: List[List[int]]) -> int:
        n = len(nums)
        tree = defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)

        parent = [-1] * n
        subtree_xor = [0] * n
        in_time = [0] * n
        out_time = [0] * n
        time = [0]

        def dfs(u, p):
            parent[u] = p
            in_time[u] = time[0]
            time[0] += 1
            xor_sum = nums[u]
            for v in tree[u]:
                if v != p:
                    xor_sum ^= dfs(v, u)
            subtree_xor[u] = xor_sum
            out_time[u] = time[0]
            time[0] += 1
            return xor_sum

        total_xor = dfs(0, -1)

        def is_ancestor(u, v):
            return in_time[u] < in_time[v] and out_time[u] > out_time[v]

        # Find all directed edges from parent -> child
        directed_edges = []
        for u in range(n):
            for v in tree[u]:
                if parent[v] == u:
                    directed_edges.append((u, v))

        min_score = float('inf')

        # Try all pairs of edges
        for i in range(len(directed_edges)):
            for j in range(i + 1, len(directed_edges)):
                _, a = directed_edges[i]
                _, b = directed_edges[j]

                if is_ancestor(a, b):
                    # a is ancestor of b
                    xor1 = subtree_xor[b]
                    xor2 = subtree_xor[a] ^ subtree_xor[b]
                    xor3 = total_xor ^ subtree_xor[a]
                elif is_ancestor(b, a):
                    # b is ancestor of a
                    xor1 = subtree_xor[a]
                    xor2 = subtree_xor[b] ^ subtree_xor[a]
                    xor3 = total_xor ^ subtree_xor[b]
                else:
                    xor1 = subtree_xor[a]
                    xor2 = subtree_xor[b]
                    xor3 = total_xor ^ subtree_xor[a] ^ subtree_xor[b]

                min_score = min(min_score, max(xor1, xor2, xor3) - min(xor1, xor2, xor3))

        return min_score

       
