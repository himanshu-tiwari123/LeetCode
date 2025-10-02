class Solution {
public:
    int maxBottlesDrunk(int fullBottles, int numExchange) {
        int drunkBottles = 0;
        int emptyBottles = 0;

        while(fullBottles + emptyBottles >= numExchange){
            drunkBottles += fullBottles;
            emptyBottles += fullBottles;
            fullBottles = 0;

            if(emptyBottles -numExchange >= 0){
                emptyBottles -= numExchange;
                numExchange++;
                fullBottles++;
            }
        }

        return drunkBottles + fullBottles;
    }
};