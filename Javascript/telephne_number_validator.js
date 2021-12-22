/**
 * @brief check if a number is a valid US-Number
 * @param num the telephone number to check 
 * @return true if the telephone number looks like a valid US-telephone number 
 */ 
isInRange = (num) => (num == 10) || (num == 11) ? true : false;
function telephoneCheck(str) {
    let result = true;
    let numberOfNum = str.split("").filter((item) => /\d/.test(item)).length;
   
    if(!isInRange(numberOfNum) || /[?#*]/.test(str)){
      result = false;
    } else if(isInRange(numberOfNum) && !/^1|^5|^[(]5{3}[)]/.test(str)){
      result = false;
    } else if((str.indexOf("(") != -1) || (str.indexOf(")") != -1)){
      if((str.indexOf("(") == -1) || (str.indexOf(")") == -1)){
        result = false;
      }
    }
    return result;
  }
  
  //console.log(telephoneCheck("(555)555-5555"));