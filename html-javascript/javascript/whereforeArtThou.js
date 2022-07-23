function whatIsInAName(collection, source) {
  const arr = [];
  // Only change code below this line
  const sourceNum = Object.keys(source).length;
  const collectionNum = collection.length;

  //iterate each object in collection list
  for (let collectionObj = 0; collectionObj < collectionNum; collectionObj++){
    //iterate each properties in each object
    let counter = 0;
    const propNum = (Object.values(collection[collectionObj])).length;
    console.log("propNum " + propNum);
    for (let collectionProp = 0; collectionProp < propNum; collectionProp++){
      const objectNum = Object.keys(collection[collectionObj]).length;
      console.log("object length " + objectNum);
      //iterate each object property in source
      for (let sourceProp = 0; sourceProp < objectNum; sourceProp++){
        console.log(`${Object.keys(collection[collectionObj])[collectionProp]} and ${Object.keys(source)[sourceProp]}`);

        if(Object.keys(collection[collectionObj])[collectionProp] == Object.keys(source)[sourceProp]){
          console.log(`${Object.values(collection[collectionObj])[collectionProp]} and ${Object.values(source)[sourceProp]}`);

          if(Object.values(collection[collectionObj])[collectionProp] == Object.values(source)[sourceProp]){
          counter++;
          }
        }
      } 
    }
    if (counter == sourceNum){
      arr.push(collection[collectionObj]);
    }
  }

  // Only change code above this line
  return arr;
}

whatIsInAName([{ "apple": 1, "bat": 2 }, { "bat": 2 }, { "apple": 1, "bat": 2, "cookie": 2 }], { "apple": 1, "bat": 2 });