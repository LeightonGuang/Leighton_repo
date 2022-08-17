let hangmanDiagram = [
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" +
  "                       \n" + 
  " ____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        O             \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        O             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        O             \n" +
  "|       /|             \n" +
  "|      / |             \n" +
  "|        |             \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        O             \n" +
  "|       /|\\            \n" +
  "|      / | \\           \n" +
  "|        |             \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        O             \n" +
  "|       /|\\            \n" +
  "|      / | \\           \n" +
  "|        |             \n" +
  "|       /              \n" +
  "|      /               \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
  ,
  "__________             \n" +
  "|        |             \n" +
  "|        |             \n" +
  "|        O             \n" +
  "|       /|\\            \n" +
  "|      / | \\           \n" +
  "|        |             \n" +
  "|       / \\            \n" +
  "|      /   \\           \n" +
  "|                      \n" +
  "|                      \n" + 
  "|____________________  \n"
]

let wordArr = ["Leighton", "Guang"];
let guessArr = [];
let userInput = document.querySelector("#userInputID");
let guess = document.querySelector("#guessID");
let guessCounter = 0;
hangmanID.innerHTML = (hangmanDiagram[0]);

//========================================

function newWord(){
  let index = Math.floor(Math.random() * (wordArr.length + 1));
  wordToGet = wordArr[index];
  wordToGet = wordToGet.toLowerCase();
  wordToGet = wordToGet.split("");
}

newWord();

//========================================

//setup number of underlines for guessing

let underlineArr = [];

function underline(){
  let underlineArrID = document.querySelector("#underlineArrID");
  for(let i in wordToGet){
    underlineArr.push("_");
  }
  underlineArrID.innerHTML = underlineArr;
}
underline();

//========================================
//run guessEnterButton() with enter key
userInput.addEventListener("keydown", (e) => {
  if(e.keyCode == 13){
    guessEnterButton();
  }
});

//========================================

function guessEnterButton(){
  let regex = /[a-z]/i;
  userInput = document.querySelector("#userInputID").toLowerCase;
  let letter = userInput.value;
  guess = document.querySelector("#guessID");
  
  //check if user entered a single alphabet character
  if(letter.length == 1 && regex.test(userInput)){
    //check for duplicate
    for (let i in guessArr){
      if(letter == guessArr[i]){
        alert("duplicate letter");
        userInput.value = "";
        return;
      }
    }
    guessArr.push((letter).toLowerCase());
  
  }else{
    alert("Please enter a single alphabet character");
    userInput.value = "";
    return;
  }

  let counter = 0;
  for (let i in wordToGet){
    //user guessed a correct character
    if(wordToGet[i] == letter){
      //alert("you guessed a right character");
      underlineArr[i] = letter;
      underlineArrID.innerHTML = underlineArr;
      counter++;

    //count how many time the user guessed wrong
    }else if(counter == 0 && i == wordToGet.length - 1){
      guessCounter++;
      if(guessCounter == 7){
        alert("You lost!");
        gameRestart();
      }
    }
  }
  guess.innerHTML = `your guesses: ${guessArr}`;
  userInput.value = "";
  hangmanID.innerHTML = (hangmanDiagram[guessCounter]);

  //check if all letters are correct
  for (let i in underlineArr){
    if(underlineArr[i] != wordToGet[i]){
      return;
    }else if(i == underlineArr.length - 1){
      alert("you won");
      gameRestart();
    }
  }
}

//========================================

function gameRestart(){
  let again = confirm("Do you want to play again?");
  if(again){
    newWord();
    resetVariables();
  }else{
    alert("gg");
  }
}

//========================================

function resetVariables(){
  underlineArr = [];
  guessArr = [];
  guessCounter = 0;
  underline();
  guess.innerHTML = "your guesses:";
  hangmanID.innerHTML = (hangmanDiagram[0]);
}

//========================================