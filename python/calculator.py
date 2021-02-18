import tkinter as tk
r = tk.Tk()
r.title('Calculator')

def numClick(num):
    current = result.get()
    result.delete(0, tk.END)
    result.insert(0, str(current) + str(num))

def add():
    global operation
    global num1
    operation = 'plus'
    num1 = int(result.get())
    result.delete(0, tk.END)
    print(num1)
    print(operation)

def subtract():
    global operation
    global num1
    operation = 'subtract'
    num1 = int(result.get())
    result.delete(0, tk.END)
    print(num1)
    print(operation)

def multi():
    global operation
    global num1
    operation = 'multi'
    num1 = int(result.get())
    result.delete(0, tk.END)
    print(num1)
    print(operation)

def divide():
    global operation
    global num1
    operation = 'divide'
    num1 = int(result.get())
    result.delete(0, tk.END)
    print(num1)
    print(operation)

def clear():
    result.delete(0, tk.END)

def equal():
    global operation
    global num2

    num2 = int(result.get())
    result.delete(0, tk.END)

    if operation == 'plus':
        result.insert(0, num1 + num2)
        print(num1 + num2)

    elif operation == 'subtract':
        result.insert(0, num1 - num2)
        print(num1 - num2)

    elif operation == 'multi':
        result.insert(0, num1 * num2)
        print(num1 * num2)

    elif operation == 'divide':
        result.insert(0, num1 / num2)
        print(num1 / num2)

    else:
        result.insert(0, num2)
        print(num2)

    operation = ''


num1 = 0
num2 = 0
operation = ''


result = tk.Entry(r, width = 35, borderwidth = 5)

bnum1 = tk.Button(r, text = '1', padx = 40, pady = 40, command = lambda: numClick(1))
bnum2 = tk.Button(r, text = '2', padx = 40, pady = 40, command = lambda: numClick(2))
bnum3 = tk.Button(r, text = '3', padx = 40, pady = 40, command = lambda: numClick(3))
bnum4 = tk.Button(r, text = '4', padx = 40, pady = 40, command = lambda: numClick(4))
bnum5 = tk.Button(r, text = '5', padx = 40, pady = 40, command = lambda: numClick(5))
bnum6 = tk.Button(r, text = '6', padx = 40, pady = 40, command = lambda: numClick(6))
bnum7 = tk.Button(r, text = '7', padx = 40, pady = 40, command = lambda: numClick(7))
bnum8 = tk.Button(r, text = '8', padx = 40, pady = 40, command = lambda: numClick(8))
bnum9 = tk.Button(r, text = '9', padx = 40, pady = 40, command = lambda: numClick(9))
bnum0 = tk.Button(r, text = '0', padx = 40, pady = 40, command = lambda: numClick(0))

bdiv = tk.Button(r, text = '/', padx = 40, pady = 40, command = divide)
bmul = tk.Button(r, text = 'x', padx = 40, pady = 40, command = multi)
bsub = tk.Button(r, text = '-', padx = 40, pady = 40, command = subtract)
badd = tk.Button(r, text = '+', padx = 40, pady = 40, command = add)
bequ = tk.Button(r, text = '=', padx = 40, pady = 40, command = equal)
bclr = tk.Button(r, text = 'clear', padx = 40, pady = 40, command = clear)


result.grid(row = 0, column = 0, columnspan = 4)
bnum1.grid(row = 3, column = 0)
bnum2.grid(row = 3, column = 1)
bnum3.grid(row = 3, column = 2)
bnum4.grid(row = 2, column = 0)
bnum5.grid(row = 2, column = 1)
bnum6.grid(row = 2, column = 2)
bnum7.grid(row = 1, column = 0)
bnum8.grid(row = 1, column = 1)
bnum9.grid(row = 1, column = 2)
bnum0.grid(row = 4, column = 0)

bdiv.grid(row = 1, column = 3)
bmul.grid(row = 2, column = 3)
bsub.grid(row = 3, column = 3)
badd.grid(row = 4, column = 3)
bequ.grid(row = 4, column = 2)
bclr.grid(row = 4, column = 1)

r.mainloop()
