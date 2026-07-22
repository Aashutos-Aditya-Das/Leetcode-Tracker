class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = size(s);

        int ones = 0;
        for (char ch : s) {
            if (ch == '1') {
                ones++;
            }
        }

        vector<int> type;
        vector<int> start;
        vector<int> end;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && s[j] == s[i]) {
                j++;
            }

            type.push_back(s[i] - '0');
            start.push_back(i);
            end.push_back(j - 1);

            i = j;
        }

        int m = size(type);

        vector<int> pos(n);

        for (int i = 0; i < m; i++) {
            for (int j = start[i]; j <= end[i]; j++) {
                pos[j] = i;
            }
        }

        vector<int> gain(m, 0);

        for (int i = 1; i < m - 1; i++) {
            if (type[i] == 1) {
                gain[i] =
                    (end[i - 1] - start[i - 1] + 1) +
                    (end[i + 1] - start[i + 1] + 1);
            }
        }

        vector<int> lg(m + 1, 0);

        for (int i = 2; i <= m; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int k = lg[m] + 1;

        vector<vector<int>> st(k, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            st[0][i] = gain[i];
        }

        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= m; i++) {
                st[j][i] = max(
                    st[j - 1][i],
                    st[j - 1][i + (1 << (j - 1))]
                );
            }
        }

        auto query = [&](int l, int r) {
            if (l > r) {
                return 0;
            }

            int j = lg[r - l + 1];

            return max(
                st[j][l],
                st[j][r - (1 << j) + 1]
            );
        };

        auto calc = [&](int idx, int L, int R, int leftSeg, int rightSeg) {
            if (idx <= leftSeg || idx >= rightSeg) {
                return 0;
            }

            if (type[idx] == 0) {
                return 0;
            }

            int left = 0;

            if (idx - 1 == leftSeg) {
                left = max(0, end[idx - 1] - L + 1);
            } else {
                left = end[idx - 1] - start[idx - 1] + 1;
            }

            int right = 0;

            if (idx + 1 == rightSeg) {
                right = max(0, R - start[idx + 1] + 1);
            } else {
                right = end[idx + 1] - start[idx + 1] + 1;
            }

            return left + right;
        };

        vector<int> ans;

        for (auto &q : queries) {
            int L = q[0];
            int R = q[1];

            int leftSeg = pos[L];
            int rightSeg = pos[R];

            if (rightSeg - leftSeg < 2) {
                ans.push_back(ones);
                continue;
            }

            int mx = 0;

            mx = max(mx, calc(leftSeg + 1, L, R, leftSeg, rightSeg));
            mx = max(mx, calc(rightSeg - 1, L, R, leftSeg, rightSeg));

            if (leftSeg + 2 <= rightSeg - 2) {
                mx = max(mx, query(leftSeg + 2, rightSeg - 2));
            }

            ans.push_back(ones + mx);
        }

        return ans;
    }
};