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
  /**
   * @brief map a number to a range to match th symbols array
   * @param num to map 
   * @returns an array telling in wish range the Number is
   */
  function range(num) {
    if(num < 10){
      return [1,5,10];
    } else if(num < 100){
      return [10,50,100];
    } else if(num < 1000){
      return [100,500,1000];
    } else{
      return [1000];
    }
  }
  /**
   * @brief Decompose a number in a sum of multiple of 10 plus rest 
   * @param num number to decompose 
   * @returns an 4 Value array [a, b, c, d] where num = a*1000 + b*100 + c*10 * d
   */
  function decompose(num) {
    let newArr = [0,0,0,0];
    for(let i=0; i<4; i++){
      newArr[3 - i] = (num % 10) * Math.pow(10,i);
      num = parseInt(num /= 10);
    }
    return newArr;
  }

  /**
   * constructor for each number composing the final number
   * 
   * @param num 
   */
  function nthNumber (num) {
    // range gives back and array with the range of the number 
    // store the array in an attribute of the object
    this.rangeArr = range(num);

    // store the corresponding symbols in the attribute of the object
    this.rangeStart = symbols[this.order[0]];
    this.rangeEnd = symbols[this.order[2]];
    this.rangeMiddle = symbols[this.order[1]];
  }

  /**
   * 
   * @param {*} obj 
   * @param {*} number 
   * @returns 
   */
  function nthElement(obj, number){
    let str = "x";
    let arr = obj.rangeArr;

    
    if((number == arr[0]) || (number == arr[1]) || (number == arr[2])){
        str = symbols[number];
    } else if(number < arr[1]){
      if(number == (arr[1]-arr[0])){
        str = obj.start.concat(obj.middle);
      } else {
        str = obj.start.repeat(parseInt(number.toString()[0]));
      }
    }else if(number > arr[1]){
      if(number == (arr[1]+arr[0])){
        str = obj.middle.concat(obj.start);
      } else if(number == (arr[2]-arr[0])){
        str = obj.start.concat(obj.end);
      } else{
        str = obj.middle.concat(obj.start.repeat(
          parseInt((number-obj.order[1]).toString()[0])));
      }
    } else {
      str = obj.start.repeat(parseInt(number.toString()[0]));
       console.log("match");
    }
    return str;
  }

  /**
   * @brief Convert a Number in a Roman Number 
   * @param num 
   * @returns converted Number as string
   */
  function convertToRoman(num) {
    let result = "";

    // Get the different part of the number
    let allNumbers = decompose(num);
  

    for(let i=0; i<4; i++) { 
      // for each part of the number create an object containing the same information
      // translated in roman number mulktiple of 10 plus the rest 
      let obj = new nthNumber(allNumbers[i]);

      if(allNumbers[i] != 0){
        // find the Roman number corresponding to each number coming 
        // from decomposing the input and concatinate it them one after the oder 
        result = result.concat(nthElement(obj, allNumbers[i]));
      }
    }
    return result;
  }
  
  //console.log(convertToRoman(2014));