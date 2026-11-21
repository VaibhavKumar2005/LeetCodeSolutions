class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<int> first_child(n, -1), next_sibling(n, -1); 
        for (int x = n - 1; x > 0; --x) {
            next_sibling[x] = first_child[parent[x]];
            first_child[parent[x]] = x;
        }
        vector<int> size(n, 1), above(n);
        array<int, 26> last;  
        last.fill(-1);
        vector<int> stack{0};  
        while (!stack.empty()) {
            int x = stack.back();
            stack.pop_back();
            if (x >= 0) {
                int c = s[x] - 'a';
                above[x] = last[c];  
                last[c] = x;
                stack.push_back(~x); 
                for (int child = first_child[x]; child != -1; child = next_sibling[child])
                    stack.push_back(child);
            } else {
                x = ~x;
                last[s[x] - 'a'] = above[x];
                if (x)  
                    size[above[x] >= 0 ? above[x] : parent[x]] += size[x];
            }
        }
        return size;
    }
};

inline auto init = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();
