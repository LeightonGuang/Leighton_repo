const computerChoiceDisplay = document.getElementById('computer-choice')
const yourChoiceDisplay = document.getElementById('your-choice')
const resultDisplay = document.getElementById('result')
const possibleChoices = document.querySelectorAll('button')
let userChoice
let result

possibleChoices.forEach(possibleChoice => possibleChoice.addEventListener('click', (e) => {
    userChoice = e.target.id
    yourChoiceDisplay.innerHTML = userChoice
    generateComputerChoice()
    getResult()
}))

function generateComputerChoice(){
    const randomNumber = Math.floor(Math.random() * possibleChoices.length)

    if (randomNumber === 1){
        computerChoice = 'rock'
    }
    if (randomNumber === 2){
        computerChoice = 'paper'
    }
    if (randomNumber === 3){
        computerChoice = 'scissors'
    }

    console.log(computerChoice)
    computerChoiceDisplay.innerHTML = computerChoice
}

function getResult(){
    if(computerChoice === userChoice){
        result = 'draw'
    }
    if(computerChoice === 'rock' && userChoice === 'paper'){
        result = 'you win'
    }
    if(computerChoice === 'rock' && userChoice === 'scissors'){
        result = 'you lost'
    }
    if(computerChoice === 'paper' && userChoice === 'scissors'){
        result = 'you lost'
    }
    if(computerChoice === 'paper' && userChoice === 'rock'){
        result = 'you lost'
    }
    if(computerChoice === 'scissors' && userChoice === 'rock'){
        result = 'you win'
    }
    if(computerChoice === 'scissors' && userChoice === 'paper'){
        result = 'you lost'
    }

    resultDisplay.innerHTML = result
}