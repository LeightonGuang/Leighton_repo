let lastTime, hours, minutes, seconds;

let hours1 = document.getElementById('hours1');
let hours2 = document.getElementById('hours2');
let minutes1 = document.getElementById('minutes1');
let minutes2 = document.getElementById('minutes2');
let seconds1 = document.getElementById('seconds1');
let seconds2 = document.getElementById('seconds2');

function getTime(){
  hours = (new Date().getHours()).toString();
  minutes = (new Date().getMinutes()).toString();
  seconds = (new Date().getSeconds()).toString();

  lastTime = (`${hours} : ${minutes} : ${seconds}`);
  console.log(`${hours} : ${minutes} : ${seconds}`);
}

function changeTime(){
  getTime();
  if(hours.length == 2){
    hours1.innerHTML = hours[0];
    hours2.innerHTML = hours[1];
  }else{
    hours1.innerHTML = 0;
    hours2.innerHTML = hours;
  }

  if(minutes.length == 2){
    minutes1.innerHTML = minutes[0];
    minutes2.innerHTML = minutes[0];
  }else{
    minutes1.innerHTML = 0;
    minutes2.innerHTML = minutes;
  }

  if(seconds.length == 2){
    seconds1.innerHTML = seconds[0];
    seconds2.innerHTML = seconds[1];
  }else{
    seconds1.innerHTML = 0;
    seconds2.innerHTML = seconds;
  }
}

getTime();

setInterval(changeTime, 1000);
