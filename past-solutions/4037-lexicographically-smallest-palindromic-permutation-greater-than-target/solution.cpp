class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Frequency of characters
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Find the middle character
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                if (middle != '\0') {
                    return "";
                }

                middle = char('a' + i);
            }
        }

        // Characters available for the left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        int halfLen = n / 2;

        string prefix;
        string answer;

        // Can the current prefix be completed
        // into a palindrome greater than target?
        function<bool()> feasible = [&]() {

            string left = prefix;

            // Make the largest possible remaining left half
            for (int c = 25; c >= 0; c--) {
                for (int k = 0; k < halfCnt[c]; k++) {
                    left.push_back(char('a' + c));
                }
            }

            // Build palindrome
            string palindrome = left;

            if (middle != '\0') {
                palindrome.push_back(middle);
            }

            for (int i = (int)left.size() - 1; i >= 0; i--) {
                palindrome.push_back(left[i]);
            }

            return palindrome > target;
        };

        // Build the left half
        for (int pos = 0; pos < halfLen; pos++) {

            bool chosen = false;

            // Try smallest character first
            for (int c = 0; c < 26; c++) {

                if (halfCnt[c] == 0) {
                    continue;
                }

                // Choose c temporarily
                halfCnt[c]--;
                prefix.push_back(char('a' + c));

                // Is there some valid completion?
                if (feasible()) {
                    chosen = true;
                    break;
                }

                // Undo
                prefix.pop_back();
                halfCnt[c]++;
            }

            // No character can work
            if (!chosen) {
                return "";
            }
        }

        // Construct final palindrome
        answer = prefix;

        if (middle != '\0') {
            answer.push_back(middle);
        }

        for (int i = halfLen - 1; i >= 0; i--) {
            answer.push_back(prefix[i]);
        }

        if (answer > target) {
            return answer;
        }

        return "";
    }
};
