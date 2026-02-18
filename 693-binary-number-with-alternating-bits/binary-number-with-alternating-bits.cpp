class Solution {
public:
    bool hasAlternatingBits(int n) {
        int currBit = n%2;
        n=n/2;
        
        while(n>0){
            if(currBit == n%2)
                return false;
            currBit = n%2;
            n/=2;    
        }
        return true;
    }
};