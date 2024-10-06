/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
       
      var len = this.length -1;
      
      if(this.length === 0){
        return -1;
      }else{
          return this[len];
      }

    
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
