/**
 * @brief check if there is enou
 * @params price: the purchase
 *         cash: the resieved cash
 *         cid: object containing informations about the amount
 *              each currency available.
 * @return an object with a status key an a change key : 
 *         - {status: "INSUFFICIENT_FUNDS", change: []} -> if the cash in drawer is less than
 *                                                       the chnage due
 *                                                    -> or if it is not possible to return 
 *                                                       exact change
 *         - {status: "CLOSED", change: [...]}  -> cash-in-drawer as the value for the key 
 *                                                 change if it is equal to the change due.
 *         - {status: "OPEN", change: [...]} -> with the change due in coins and bills, 
 *                                              sorted in highest to lowest order, as 
 *                                              the value of the change key.
 */
/**
 * 
 *  cid :   [
                ["PENNY", 1.01],
                ["NICKEL", 2.05],
                ["DIME", 3.1],
                ["QUARTER", 4.25],
                ["ONE", 90],
                ["FIVE", 55],
                ["TEN", 20],
                ["TWENTY", 60],
                ["ONE HUNDRED", 100]
            ]
 */
  function checkCashRegister(price, cash, cid) {
    let change = { status: "", change:[]};

    // Calculate the total available cash
    let totalCash = getTotalCash(cid);

    // Calculate the total due
    let totalDue = cash - price;

    let due = destructureFrom(totalDue,100);
    // console.log(due);
    
    if (totalCash == totalDue){
       change.status = "CLOSED";
       let cashInCid = cid.slice();
       let available = cashInCid.filter((item) => item[2] != 0);
       let result = [];
       available = available.map((item) => {
         if(item[1] != 0){
           result.push([item[0],(totalDue/item[1])*item[1]]);
         }
       });
       change.change = cashInCid;
      } else {
        let wholeDue = parseInt(totalDue);

        let deciDue = (totalDue - wholeDue).toFixed(2);
        
        let cashInCid = sortCid(cid);
        cashInCid = (insertQuantity(cashInCid)).filter((item) => item[2] != 0);
        // console.log(cashInCid);
  
        let wholeCash = cashInCid.filter((item) => !/[.]/.test(item[1]));
        let deciCash = cashInCid.filter((item) => /[.]/.test(item[1]));
        
        if((totalDue < 1) && (deciDue < 1) && (getTotalCashFromUnit(deciCash) < totalDue)){
          change.status = "INSUFFICIENT_FUNDS";
          console.log(getTotalCashFromUnit(deciCash));
        } else{
          change.status = "OPEN";
          if(totalDue >= 1){
            change.change = structure(cashInCid,totalDue).filter((item) => item[1] !=0);
          } else {
            for(let i=0;i<deciCash.length;i++){
              console.log(deciCash[i][1]*deciCash[i][2]);
              if(deciCash[i][1]*deciCash[i][2] > totalDue){
                change.change.push([deciCash[i][0],totalDue])
                console.log("match");
                break;
              }
            }
          }
        }
      }
      return change;
    }
    
    //checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);
    
 /**
   * @brief calculate the summe of all the available cash
   * @param arr an array containing  
   * @returns the total available cash
   */
  function getTotalCash (arr){
    let totalCash = 0;
    let newArr = arr.slice();
    newArr.forEach((item) => totalCash += item[1]);
  
    return totalCash;
  }


const currencyUnit = {
    "ONE HUNDRED" : 100,
     "TWENTY" : 20,
     "TEN" : 10,
     "FIVE" : 5,
     "ONE" : 1,
     "QUARTER" : 0.25,
     "DIME" : 0.1,
     "NICKEL" : 0.05,
     "PENNY" : 0.01
  }

  const wholeUnit = [20,20,5,1];
  const deciUnit = [0.25,0.1,0.05,0.01];
  const unit = [100,20,10,5,1,0.25,0.1,0.05,0.01];

  /**
   * @brief map a number to a currency Unit
   * @param num a Number to map to a currency Unit  
   * @returns the Currency Unit corresponding to the given number
   */
  function getProp(num){
    let str = "";
    for(let prop in currencyUnit){
      if(currencyUnit[prop] == num){
        str = prop;
      }
    }
    return str;
  }

  /**
   * @brief Decompose a number in a summe of multiple of the different avaible 
   *        currency 
   * @param num the nomber to decompose
   * @param x the currency to start from
   * @returns an array containing the currency in character in number and the amount of 
   *          it necessary to build the due.
   */
  function destructureFrom(num,x) {
      let newArr = [];
      let newNumber = num;

      unit.slice(unit.indexOf(x),).forEach((item) => {
        if(parseInt(newNumber / item) != 0){
          let combi = [getProp(item),item,parseInt((newNumber / item) + 0.001)];
          newArr.push(combi);
          newNumber = newNumber - combi[1]*combi[2];
        }
      });
      return newArr;
  }

/**
 * add an extra element to the array corresponding to the amount of the currancy available
 * @param arr 
 * @returns new array with a 3th element at position 2 corresponding 
 *          to the amount of th currency
 */
  function insertQuantity(arr) {
    let newArr =  [];
    newArr = arr.slice();
    newArr = newArr.map((item) => {
      // item[1] -> the amount of the currency available
      // item[0] -> the name of the currency 
      // Math.round(item[1] / currencyUnit[item[0]]) -> gives back the amount of 
      //                                                the currency 
      // so ADDING a an extra element to the array at position "2"                                             
      if(item[1] != 0){
        item.push(Math.round(item[1] / currencyUnit[item[0]]));
        item[1] = currencyUnit[item[0]];
      } else {
        item.push(0);
      }
      return item;
    });
    return newArr;
  }


  /**
   * 
   * @param {*} arr 
   * @returns 
   */
  function getTotalCashFromUnit (arr){
    let sumOfContain = 0;
    let newArr = arr.slice();
    newArr.forEach((item) => sumOfContain += item[1]*item[2]);
    return sumOfContain;
  }

  /**
   * 
   * @param {*} arr 
   * @param {*} str 
   * @returns 
   */
  function isAvailable(arr,str) {
    if(arr.some((item) => item[0] == str)){
      return true;
    }else{
      return false;
    }
  }
  /**
   * inverse the oder of the values in the array
   * @param arr the array to inverse
   * @returns the inversed array
   */
  function sortCid(arr){
    let newArr = [];
    for(let i=0; i < arr.length; i++){
      newArr[arr.length-i] = arr[i];
    }
    return newArr;
  }
  

  /**
   * 
   * @param {*} arr 
   * @param {*} num 
   * @returns 
   */
  function  structure(arr,num){
    let newArr = arr.slice().filter((item) => item[0] != "ONE HUNDRED");
    let result = [];
    let restDue = num;
    console.log(newArr);
    newArr.forEach((item) => {
      let amount = (item[1]*item[2]).toFixed(2);
      if(amount < restDue){
         item[1] = item[1]*item[2];
         result.push(item.slice(0,2));
         restDue -= item[1];
         console.log(restDue);
      }else{
        let temp = destructureFrom(restDue,item[1])[0];
        restDue -= temp[1]*temp[2];
        result.push([temp[0],temp[1]*temp[2]]);
      }
    });
    return result;
  }
  