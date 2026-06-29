class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int MaxLen = 0;
        unordered_map<char, int> lastSeen;

        for(int right = 0; right < s.length(); right++){
            char c = s[right];
            if(lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= l){
                l = lastSeen[c] + 1;
            }
            MaxLen = max(MaxLen, right - l + 1);
            lastSeen[c] = right;
        }    

        return MaxLen;
    }
};