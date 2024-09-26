/**
 * @param {number} n
 * @return {number}
 */
var sumOfMultiples = function(n) {
   
    var sum = 0;

    for(i=0;i<=n;i++){
       if(i%5 == 0 || i%3 == 0 || i%7 == 0){
        sum = sum + i ;     
        }
    };
   

    return sum;

};
