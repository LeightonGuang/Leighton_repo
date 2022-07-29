function sumFibs(num) {
  let previous = 1;
  let last = 1;
  let sum = 1;
  
  while (last <= num){
    //if the last number is an odd number
    if(last % 2 != 0){
      sum += last;
      last = last + previous;
      previous = last - previous;
    
    //even number
    }else{
      last = last + previous;
      previous = last - previous;
    }
  }
  console.log(sum);
  return sum;
}

sumFibs(75024);