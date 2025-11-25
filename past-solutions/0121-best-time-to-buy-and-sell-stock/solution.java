class Solution {
    public int maxProfit(int[] prices) {
        int maxpr = 0;
        int currpr = 0;
        int buy = prices[0];
        for(int i = 0; i < prices.length; i++){
            buy = Math.min (buy, prices[i]);
            currpr = prices[i] - buy;
            maxpr = Math.max (currpr, maxpr);

        }
        return maxpr;
    }
}
