class Solution {
public:
    int myAtoi(string s) {
        if(s.empty()) return 0;

        int n = s.length();
        int i = 0;

        while(i<n && s[i] == ' '){
            i++;
        }

        if(i==n)return 0;

        int sign = 1;
        if(s[i] == '+'){
            i++;
        }else if(s[i] == '-'){
            sign = -1;
            i++;
        }

        long long res=0;
        while(i<n && isdigit(s[i])){
            res = res*10 + (s[i] - '0');
           
           if (res > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return (int)res * sign;
    }
};