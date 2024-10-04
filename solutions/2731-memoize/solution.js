/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const results = {};
    return function(...args) {
        const key = JSON.stringify(args);
        if(key in results){
            return results[key];
        }else{
        results[key] = fn(...args);
         return results[key];
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
