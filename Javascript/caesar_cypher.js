/**
 * @brief Decode a ROT!§ cipher encoder string 
 * @param str the string to decode 
 * @return The decoded string
 */
const letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
console.log(letters.length);

function rot13(str) {
  let newStr = "";
  newStr = str.split("");
  for(let i=0;i<newStr.length;i++){
    let index = letters.indexOf(newStr[i]);
    if(!/\s|\W/.test(newStr[i])){
      if(index >= 13){
        console.log(newStr[i]);
        console.log("->",letters[index-13])
        newStr[i] = letters[index-13];
       }else{
          newStr[i] = letters[index+13];
        }
    }
   }
  console.log(newStr.join(""));
  return newStr.join("");
}

console.log(rot13("SERR PBQR PNZC"));