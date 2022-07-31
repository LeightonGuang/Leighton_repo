function checkCashRegister(price, cash, cid) {
  let originalCid = cid.map(v => v.slice());
  let amount = [100, 20, 10, 5, 1, 0.25, 0.1, 0.05, 0.01];
  let total_cid = 0;
  let totalChange = cash - price;
  let changeArr = [];
  let change = {status: "OPEN", change: changeArr};
  let justEnough = false;
  
  //total amount left in cid
  for(let i = 0; i < cid.length; i++){
    if(cid[i][1] == 0){
      cid.splice(i, 1);
      amount.splice(amount.length - i - 1, 1);
      i = i-1;
    }else{
      total_cid += cid[i][1];
    }
  }

  if(total_cid == totalChange){
    justEnough = true;
  }

  //if there's not enough money in drawer
  if(total_cid - totalChange < 0){
    console.log({status: "INSUFFICIENT_FUNDS", change: []});
    return {status: "INSUFFICIENT_FUNDS", change: []};

  //if there's left over after change in drawer
  }else{
    for(let amountIndex = 0; amountIndex < amount.length; amountIndex++){
      if(amount[amountIndex] <= totalChange  && cid[amount.length - amountIndex - 1][1] != 0){
        //if there are alrady same currency in array then add to the value 
        if(changeArr.length > 0){
          //loop through the array
          for(let i = 0; i < changeArr.length; i++){
            if(changeArr[i][0] == cid[amount.length - amountIndex - 1][0]){
              changeArr[i][1] += amount[amountIndex];
            
            }else if(i == changeArr.length - 1){
              changeArr.push([cid[amount.length - amountIndex - 1][0], amount[amountIndex]]);
              break;
            }
          }

        //if theres not enought change even tho there are enough amount of money left
        }else if(amountIndex == (amount.length - 1) && total_cid > totalChange){
          console.log({status: "INSUFFICIENT_FUNDS", change: []});
          return {status: "INSUFFICIENT_FUNDS", change: []};

        }else{
          changeArr.push([cid[amount.length - amountIndex - 1][0], amount[amountIndex]]);
        }
        
        cid[amount.length - amountIndex - 1][1] -= amount[amountIndex];

        totalChange -= amount[amountIndex];
        totalChange = totalChange.toFixed(2);

        //console.log(cid[amount.length - amountIndex - 1][0] + " left: " +(cid[amount.length - amountIndex - 1][1]).toFixed(2));

        //if there's none of the specific currency left, remove from amount array
        if(cid[amount.length - amountIndex - 1][1] == 0){
          cid.splice(amount.length - amountIndex - 1, 1);
          amount.splice(amountIndex, 1);
        }
        amountIndex = -1;
      }
    }

    if(justEnough){
      console.log({status: "CLOSED", change: originalCid});
      return {status: "CLOSED", change: originalCid};

    }else{
      console.log(change);
    return change;
    }
  }
}

checkCashRegister(19.5, 20, [["PENNY", 0.5], ["NICKEL", 0], ["DIME", 0], ["QUARTER", 0], ["ONE", 0], ["FIVE", 0], ["TEN", 0], ["TWENTY", 0], ["ONE HUNDRED", 0]]);