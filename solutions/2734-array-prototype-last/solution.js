/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
       
      var len = this.length -1;
      
      if(len == -1){
        return len;
      }
      return this[len];

    
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */
