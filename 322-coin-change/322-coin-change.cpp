class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, amount + 1);
        memo[0] = 0;
        
        for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            for (auto& coin : coins) {
                if (currentAmount - coin >= 0) {
                    memo[currentAmount] = min(memo[currentAmount], 1 + memo[currentAmount - coin]);
                }
            }
        }
        
        if (memo[amount] == amount + 1) return -1;
        else return memo[amount];
    }
};