class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int sum = 0, d = 0;
        for(int i=0; i<weights.size(); i++) { 
            if( weights[i] > capacity) {
                return false;  // Every individual container's weight should be <= the minimum capacity that can be shipped in a day
            }
            sum += weights[i];
            if(sum >= capacity) {
                if(sum > capacity) {
                    i--;   // Go back only if the weight summed till now exceeds capacity, else include this package as well
                }
                sum = 0;
                d++;
            }
        }
        
        if(sum> 0 && sum < capacity) {
            d++;   // To check if there are any packages left after the above block ends
        }
        return (d <= days);   
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap = 0;
        for(int i=0; i<weights.size(); i++) {
            maxCap+= weights[i];
        }
        int minCap = 1;
        while(minCap <= maxCap) {
            int mid = minCap + (maxCap - minCap)/2;
            if(canShip(weights, days, mid)) {   // If container can be shipped with an average loading capacity of 'mid', 
												//it probably can also be shipped with a lower average loading capacity, hence decrease maxCap
                maxCap = mid - 1;
            } else {
                minCap = mid + 1;
            }
        }
        return minCap;
    }
};