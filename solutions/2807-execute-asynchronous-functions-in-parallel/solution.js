/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    
      return new Promise((resolve, reject) => {
        let arr = new Array(functions.length);
        let count = 0;

        functions.forEach((fn,i)=>{
            fn()
            .then((val)=>{
                arr[i]=val;
                count++;
                if(count === functions.length){
                    resolve(arr);
                }
            })
            .catch((error)=>{reject(error)});
        })
      
    });
    
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */
