/**
 * @brief check 
 * @params price: the purchase
 *         cash: the resieved cash
 *         cid: object containing the amount the current available currency
 * @return an object with a status key an a change key 
 */
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
  function getProp(num){
    let str = "";
    for(let prop in currencyUnit){
      if(currencyUnit[prop] == num){
        str = prop;
      }
    }
    return str;
  }
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
  // console.log(destructureFrom(96,100));
  function insertQuantity(arr) {
    let newArr =  [];
    newArr = arr.slice();
    newArr = newArr.map((item) => {
      if(item[1] != 0){
        item.push(Math.round(item[1] / currencyUnit[item[0]]));
        item[1] = currencyUnit[item[0]];
      }else{
        item.push(0);
      }
      return item;
    });
    return newArr;
  }
  function getTotalCash (arr){
    let sumOfContain = 0;
    let newArr = arr.slice();
    newArr.forEach((item) => sumOfContain += item[1]);
    return sumOfContain;
  }
  function getTotalCashFromUnit (arr){
    let sumOfContain = 0;
    let newArr = arr.slice();
    newArr.forEach((item) => sumOfContain += item[1]*item[2]);
    return sumOfContain;
  }
  function isAvailable(arr,str) {
    if(arr.some((item) => item[0] == str)){
      return true;
    }else{
      return false;
    }
  }
  function sortCid(arr){
    let newArr = [];
    for(let i=0;i<arr.length;i++){
      newArr[arr.length-i] = arr[i];
    }
    return newArr;
  }
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
  
  function checkCashRegister(price, cash, cid) {
    let change = { status:"",change:[]};
    let totalCash = getTotalCash(cid);
    let totalDue = cash-price;
    let due = destructureFrom(totalDue,100);
    // console.log(due);
    
    if(totalCash == totalDue){
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
      }else{
        let wholeDue = parseInt(totalDue);
        console.log(wholeDue);
        let deciDue = (totalDue - wholeDue).toFixed(2);
        console.log(wholeDue + " / " + deciDue);
  
        let cashInCid = sortCid(cid);
        cashInCid = (insertQuantity(cashInCid)).filter((item) => item[2] != 0);
        // console.log(cashInCid);
  
        let wholeCash = cashInCid.filter((item) => !/[.]/.test(item[1]));
        let deciCash = cashInCid.filter((item) => /[.]/.test(item[1]));
  
      if((totalDue < 1) && (deciDue < 1) && (getTotalCashFromUnit(deciCash) < totalDue)){
          change.status = "INSUFFICIENT_FUNDS";
          console.log(getTotalCashFromUnit(deciCash));
        }
        else{
          change.status = "OPEN";
          // console.log(structure(deciCash,deciDue));
          if(totalDue >= 1){
           change.change = structure(cashInCid,totalDue).filter((item) => item[1] !=0);
          }else{
            for(let i=0;i<deciCash.length;i++){
              console.log(deciCash[i][1]*deciCash[i][2]);
              if(deciCash[i][1]*deciCash[i][2] > totalDue){
                change.change.push([deciCash[i][0],totalDue])
                console.log("match");
                break;
              }
            }
            // change.change = structure(cashInCid,totalDue);
            console.log(deciCash);
          }
        }
        
      }
    console.log(change);
    return change;
  }
  
  checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);