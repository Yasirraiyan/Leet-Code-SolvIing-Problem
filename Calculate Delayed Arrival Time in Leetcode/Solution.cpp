class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int delayedarrivaltime= arrivalTime+delayedTime;
        if(delayedarrivaltime>=24)
        {
            return delayedarrivaltime%24;
        }
        return delayedarrivaltime;
    }
};
