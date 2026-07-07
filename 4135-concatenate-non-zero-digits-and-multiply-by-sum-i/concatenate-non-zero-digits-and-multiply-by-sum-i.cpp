class Solution {
public:
    long long sumAndMultiply(int n) {

        long long divider = 1;
        long long x=0;
        long long sum=0;
        while(n>0){
            int digit = n%10;
            if(digit>0){
                x += digit*divider;
                sum += digit;
                divider *= 10;
            }
            n /= 10;
        }
        return x*sum;
    }
};