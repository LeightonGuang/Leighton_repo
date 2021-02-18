from threading import Timer
import tkinter as tk
w = tk.Tk()
w.title("Pomodoro Timer")

#counter for how many clicks from the button
counter = 0
#if timer is running
running = False
#if time short then its 25 mins and long is 50
time = "short"

#add how many key presses to counter
def keyPress():
    if running == False:
        print ("program not running")
        global counter
        counter += 1
        click.config(text = counter)

    elif running == True:
        print ("program is running")

def run():

    pass

#blinkng lights
def light():
    blink = True
    while blink:


    pass

#what to do when twenty five minute timer is selected
def twentyFive():
    pass

#what to do when 50 minute timer is selected
def fifty():
    pass

#Frame for lights
frame = tk.LabelFrame(w, text = "Lights")
frame.grid(row = 1, column = 0)

L1 = tk.Label(frame, bg = "yellow", padx = 5, pady = 5)
L1.grid(row = 0, column = 0)

L2 = tk.Label(frame, bg = "red", padx = 5, pady = 5)
L2.grid(row = 0 , column = 1)

L3 = tk.Label(frame, bg = "red", padx = 5, pady = 5)
L3.grid(row = 0, column = 2)

L4 = tk.Label(frame, bg = "red", padx = 5, pady = 5)
L4.grid(row = 0, column = 3)

L5 = tk.Label(w, bg = "green", padx = 5, pady = 5)
L5.grid(row = 2, column = 0)

click = tk.Label(w, text = "")
click.grid(row = 0, column = 0)

#button for control
button = tk.Button(w, text = 'button', command = keyPress)
button.grid(row = 3, column = 0)

w.mainloop()
