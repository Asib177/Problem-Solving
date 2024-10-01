class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger*(maxChoosableInteger+1) / 2;
        if(desiredTotal < 2) return true;
        else if(sum < desiredTotal) return false;
        else if(sum == desiredTotal) return maxChoosableInteger%2;
        else return dfs(maxChoosableInteger, desiredTotal, 0);
    }

    bool dfs(int maxChoosableInteger, int desiredTotal, int k) {
        if(mem[k] != 0) return mem[k] > 0;
        if(desiredTotal <= 0) return false;
        for(int i=0; i<maxChoosableInteger; i++) {
            if(!(k&(1<<i)) && !dfs(maxChoosableInteger, desiredTotal-i-1, k|(1<<i))) {
                mem[k] = 1;
                return true;
            }
        }
        mem[k] = -1;
        return false;
    }
    int mem[1<<20] = {};
};