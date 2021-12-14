/**
 * @brief check if a number is a valid US-Number
 * @param num the telephone number to check 
 * @return true the telephone number is a valid US-telephone number 
 */ 
function isInRange(num) {
    return (num == 10) || (num == 11) ? true : false;
  }
  function telephoneCheck(str) {
    let result = true;
    let numberOfNum = str.split("").filter((item) => /\d/.test(item)).length;
    console.log(numberOfNum);
    console.log(!isInRange(numberOfNum));
    if(!isInRange(numberOfNum) || /[?#*]/.test(str)){
      result = false;
    }else if(isInRange(numberOfNum) && !/^1|^5|^[(]5{3}[)]/.test(str)){
      console.log("match");
      result = false;
    }else if((str.indexOf("(") != -1) || (str.indexOf(")") != -1)){
      if((str.indexOf("(") == -1) || (str.indexOf(")") == -1)){
        result = false;
      }
    }
    return result;
  }
  
  console.log(telephoneCheck("(555)555-5555"));