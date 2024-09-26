/**
 * @param {number} arrivalTime
 * @param {number} delayedTime
 * @return {number}
 */
var findDelayedArrivalTime = function(arrivalTime, delayedTime) {
    if((delayedTime + arrivalTime) >= 24){
        return((delayedTime + arrivalTime)- 24)  ; 
         }
       
      else{
        return delayedTime + arrivalTime;
      }
     
};
