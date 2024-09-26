/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximizeSum = function(nums, k) {
    var maxNum = Math.max(...nums);
    var sum = 0;
    for(i=1;i<=k;i++){
      sum += maxNum;
      maxNum += 1;
    };
    return sum;

};
