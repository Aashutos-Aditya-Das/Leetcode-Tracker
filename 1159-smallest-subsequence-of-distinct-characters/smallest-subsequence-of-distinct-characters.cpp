class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> charCnt(26, 0);
        unordered_map<char, int> inStack;

        int uniqueCharCnt = 0;

        for(auto ch: s) {

            if(charCnt[ch - 'a'] == 0) {
                uniqueCharCnt++;
            }

            charCnt[ch - 'a']++;
        }

        stack<char> st;

        for(auto ch: s) {

            charCnt[ch - 'a']--;
            if(inStack.find(ch) != inStack.end()) {
                continue;
            }

            while(!st.empty() && charCnt[st.top() - 'a'] != 0 && (ch < st.top())) {
                inStack.erase(st.top());
                st.pop();
            }

            st.push(ch);
            inStack[ch]++;
        }

        string str = "";
        while(!st.empty()) {
            str += st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
};