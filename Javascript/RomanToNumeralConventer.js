/**
 * @brief Convert the given number into a roman numeral.
 * @param num the Number to check
 * @return the converted input
 */
 const symbols = {
    1   : "I",
    5   : "V",
    10  : "X",
    50  : "L",
    100 : "C",
    500 : "D",
    1000: "M"
  }
  var ranges = [[1,10],[10,100],[100,1000]];
  function range(num) {
    if(num < 10){
      return [1,5,10];
    }else if(num < 100){
      return [10,50,100];
    }else if(num < 1000){
      return [100,500,1000];
    }else{
      return [1000];
    }
  }
  function destructure(num) {
    let newArr = [0,0,0,0];
    for(let i=0;i<4;i++){
      newArr[3 - i] = (num % 10) * Math.pow(10,i);
      num = parseInt(num /= 10);
    }
    return newArr;
  }
  function objFactory(num) {
    this.order = range(num);
    this.start = symbols[this.order[0]];
    this.end = symbols[this.order[2]];
    this.middle = symbols[this.order[1]];
  }
  function nthElement(obj,number){
    let str = "x";
    let arr = obj.order;
    console.log(arr);
    if((number == arr[0]) || (number == arr[1]) 
      || (number == arr[2])){
        str = symbols[number];
    }else if(number < arr[1]){
      if(number == (arr[1]-arr[0])){
        str = obj.start.concat(obj.middle);
      }else{
        str = obj.start.repeat(parseInt(number.toString()[0]));
      }
    }else if(number > arr[1]){
      if(number == (arr[1]+arr[0])){
        str = obj.middle.concat(obj.start);
      }else if(number == (arr[2]-arr[0])){
        str = obj.start.concat(obj.end);
      }else{
        str = obj.middle.concat(obj.start.repeat(
          parseInt((number-obj.order[1]).toString()[0])));
      }
    }else {
      str = obj.start.repeat(parseInt(number.toString()[0]));
       console.log("match");
    }
    // console.log(str);
    return str;
  }
  function convertToRoman(num) {
    let result = "";
    let numbers = destructure(num);
    console.log(numbers);
    for(let i=0;i<4;i++){
      let obj = new objFactory(numbers[i]);
      if(numbers[i] != 0){
        console.log(numbers[i]);
        result = result.concat(nthElement(obj,numbers[i]));
      }
    }
    return result;
  }
  
  console.log(convertToRoman(2014));