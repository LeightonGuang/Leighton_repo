function convertToRoman(num) {
  let romanOutput = [];
  let numbers = {
    roman: ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"],
    arabic: [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
  }

  while(num != 0){
    for(let i in numbers.arabic){
      if (numbers.arabic[i] <= num){
        num -= numbers.arabic[i];
        romanOutput.push(numbers.roman[i]);
        break;
      }
    }
  }

  console.log(romanOutput.join(""));
  return romanOutput.join("");
}

convertToRoman(83);