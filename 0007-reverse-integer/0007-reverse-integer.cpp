class Solution {
public:
    int reverse(int x) {
        int ld = 0; 
        long long rev = 0;
        while(x != 0){
        ld = x%10;
         x = x/10;
         rev = rev*10 + ld;
           if (rev < INT_MIN || rev > INT_MAX)
                return 0;
        }
        
        return rev;
    }
};