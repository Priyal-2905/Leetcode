/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let arr1 = [];

    for(i=0;i<arr.length;i+=size){
        arr1.push(arr.slice(i,i+size));
    }
    return arr1;
};

