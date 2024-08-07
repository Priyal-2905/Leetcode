/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {

  let x=0;
  let y=1;

  while(true){
    yield x;
    let temp =y;
    y =x+y;
    x=temp;
  }
    
};


 const gen = fibGenerator();
 gen.next().value; // 0
 gen.next().value; // 1
 
