/**
 * @param {string[]} details
 * @return {number}
 */
var countSeniors = function(details) {
     var old=[];
     

   for(var i=0; i<details.length;i++){
       var age = details[i][11]+details[i][12];

       if(age > 60){
         old.push(age)
       }
   }
   ;

   return old.length;
};
