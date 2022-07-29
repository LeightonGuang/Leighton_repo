number = [0, 1, 2, 3, 4, 5, 6, 7, 8];

let winner = false;

let display = [
["+---+---+---+"],
[`| ${number[0]} | ${number[1]} | ${number[2]} |`],
["+---+---+---+"],
[`| ${number[3]} | ${number[4]} | ${number[5]} |`],
["+---+---+---+"],
[`| ${number[6]} | ${number[7]} | ${number[8]} |`],
["+---+---+---+"],
]

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function displayField(){
  for(let i in display){
    console.log(display[i][0]);
  }
}

for(let i in number){
  displayField();

  if(i % 2 == 0){
    rl.question("Player O's turn"),function (pos){
      console.log(`position ${pos}`);
      rl.close();
    }

    rl.on("close", function(){process.exit(0)});
  }

  winner = true;
}
