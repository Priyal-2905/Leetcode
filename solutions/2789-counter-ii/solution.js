/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
let x= init;
   return{

       reset : function (){
      x=init;
     return x;
    },

    increment :  function (){
        
        x=x+1;
        return x;
    },
    decrement : function (){
        x=x-1;
     return x;
    },
 
   }
   
   
    
};


 const counter = createCounter(5)
 counter.increment(); // 6
 counter.reset(); // 5
 counter.decrement(); // 4
 
