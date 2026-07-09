class Solution {
public:
    bool checkValidString(string s) {
        int leftOpen = 0;
        int leftClose = 0;

        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                leftOpen++;
                leftClose++;
            }else if(s[i] == ')'){
                leftOpen--;
                leftClose--;
            }else if(s[i] == '*'){
                leftOpen--;
                leftClose++;
            }
            
            if(leftClose < 0) return false;
            if(leftOpen < 0) leftOpen = 0;
        }


        return (leftOpen == 0);
        
    }
};