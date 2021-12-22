/**
 * @brief Palindrome checker 
 * A palindrome is a word or sentence that's spelled the same 
 * way both forward and backward, ignoring punctuation, case, and spacing.
 * @param string str Input to check
 * @returns return true if the Input is a Palidrome and false otherwise 
 */
 function palindrome(str) {
    let newStr = "";
    // strip out any whitespace, non aphabetic character and underscores
    str = str.replace(/\s|\W|[_]/g,"");
    str = str.toLowerCase();
    for(let i = 0 ; i<str.length; i++){
      newStr += str[(str.length-1) - i];
    }
    return newStr == str;
  }
  
  
  
  //console.log(palindrome("0_0 (: /-\ :) 0-0"));
