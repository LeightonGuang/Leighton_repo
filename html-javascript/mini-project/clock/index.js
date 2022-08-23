let lastTime, hours, minutes, seconds;
let am_pm = document.querySelector("#am-pm");
let degree = [0, 0, 0, 0, 0, 0, 0, 0];
let currentDisplay = [0, 0, 0, 0, 0, 0, 0, 0];
let showFront = [true, true, true, true, true, true, true, true];

let h1f = document.querySelector("#h1f");
let h1b = document.querySelector("#h1b");
let h1bg = document.querySelector("#h1bg");

let h2f = document.querySelector("#h2f");
let h2b = document.querySelector("#h2b");
let h2bg = document.querySelector("#h2bg");

let colon_f = document.querySelectorAll(".colon-f");
let colon_b = document.querySelectorAll(".colon-b");
let colon_bg = document.querySelectorAll(".colon-bg");

let m1f = document.querySelector("#m1f");
let m1b = document.querySelector("#m1b");
let m1bg = document.querySelector("#m1bg");

let m2f = document.querySelector("#m2f");
let m2b = document.querySelector("#m2b");
let m2bg = document.querySelector("#m2bg");

let s1f = document.querySelector("#s1f");
let s1b = document.querySelector("#s1b");
let s1bg = document.querySelector("#s1bg");

let s2f = document.querySelector("#s2f");
let s2b = document.querySelector("#s2b");
let s2bg = document.querySelector("#s2bg");

let flap = document.querySelectorAll(".flap");

function updateTime() {
	hours = new Date().getHours().toString();
	minutes = new Date().getMinutes().toString();
	seconds = new Date().getSeconds().toString();

	if(am_pm.checked && parseInt(hours) > 12){
		hours = hours - 12;
		hours = hours.toString();
	}

	if (hours.length == 1) {
		hours = "0" + hours;
	} else if (hours.length == 0) {
		hours = "00";
	}
	if (minutes.length == 1) {
		minutes = "0" + minutes;
	} else if (minutes.length == 0) {
		minutes = "00";
	}
	if (seconds.length == 1) {
		seconds = "0" + seconds;
	} else if (seconds.length == 0) {
		seconds = "00";
	}
	if (hours == "00"){
		hours = "12";
	}
}

function flip(back, frontID, backID, backgroundID, arrIndex) {
	if (showFront[arrIndex]) {
		backgroundID.innerHTML = back;
		backID.innerHTML = back;
		showFront[arrIndex] = false;
	} else if (showFront[arrIndex] == false) {
		backgroundID.innerHTML = back;
		frontID.innerHTML = back;
		showFront[arrIndex] = true;
	}
	degree[arrIndex] -= 180;
	flap[arrIndex].style.transform = `rotateX(${degree[arrIndex]}deg)`;
	//don't move currentDisplay
	currentDisplay = [
		h1bg.innerHTML,
		h2bg.innerHTML,
		colon_bg[0].innerHTML,
		m1bg.innerHTML,
		m2bg.innerHTML,
		colon_bg[1].innerHTML,
		s1bg.innerHTML,
		s2bg.innerHTML
	];
}

function flipTime() {
	if (currentDisplay[0] != hours[0]) {
		flip(hours[0], h1f, h1b, h1bg, 0);
	}
	if (currentDisplay[1] != hours[1]) {
		flip(hours[1], h2f, h2b, h2bg, 1);
	}

	if (currentDisplay[2] == ":") {
		flip(" ", colon_f[0], colon_b[0], colon_bg[0], 2);
	} else {
		flip(":", colon_f[0], colon_b[0], colon_bg[0], 2);
	}

	if (currentDisplay[3] != minutes[0]) {
		flip(minutes[0], m1f, m1b, m1bg, 3);
	}
	if (currentDisplay[4] != minutes[1]) {
		flip(minutes[1], m2f, m2b, m2bg, 4);
	}

	if (currentDisplay[5] == ":") {
		flip(" ", colon_f[1], colon_b[1], colon_bg[1], 5);
	} else {
		flip(":", colon_f[1], colon_b[1], colon_bg[1], 5);
	}

	if (currentDisplay[6] != seconds[0]) {
		flip(seconds[0], s1f, s1b, s1bg, 6);
	}
	if (currentDisplay[7] != seconds[1]) {
		flip(seconds[1], s2f, s2b, s2bg, 7);
	}
}

function run() {
	updateTime();
	flipTime();
}

updateTime();
setInterval(run, 500);