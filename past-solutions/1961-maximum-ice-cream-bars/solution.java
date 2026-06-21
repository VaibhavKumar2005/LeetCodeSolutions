class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);

        int count = 0;
        int total = 0;

        for(int cost : costs){
            if(total + cost > coins) break;

        total += cost;

        count++;

        }
        return count;

    }
}
