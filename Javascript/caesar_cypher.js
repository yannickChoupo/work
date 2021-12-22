/**
 * @brief Decode a with ROT13 cipher encoded string 
 * @param str encoded string to decode 
 * @return The decoded string
 */
function rot13(str) {
  let newStr = "";
  newStr = str.split("");
  for (let i=0; i<newStr.length; i++){
    let index = letters.indexOf(newStr[i]);
    if(!/\s|\W/.test(newStr[i])){
      if(index >= 13){
        newStr[i] = letters[index-13];
       } else {
          newStr[i] = letters[index+13];
        }
     }
   }
  return newStr.join("");
}
/*
const letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
console.log(rot13("SERR PBQR PNZC"));
*/
