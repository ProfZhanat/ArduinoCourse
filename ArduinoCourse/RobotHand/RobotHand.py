import serial
import time
import tkinter as tk

# Define the serial port and baud rate.
# Ensure the 'COM#' corresponds to what was seen in the Windows Device Manager
ser = serial.Serial('/dev/cu.usbserial-1420', 9600)
time.sleep(2) # wait for the serial connection to initialize
window = tk.Tk()
window.title("ArduinoHand")
window.geometry("400x400")

curGrab = False

def rotate(which, move):
    if move == 1:
        if which == "CORE":
            ser.write(str("X" + str(1) + ":Y" + str(0)).encode())
            print(str("X" + str(1) + ":Y" + str(0)))
        elif which == "MID":
            ser.write(str("X" + str(0) + ":Y" + str(1)).encode())
            print(str("X" + str(0) + ":Y" + str(1)))
    elif move == -1:
        if which == "CORE":
            ser.write(str("X" + str(-1) + ":Y" + str(0)).encode())
            print(str("X" + str(-1) + ":Y" + str(0)))
        elif which == "MID":
            ser.write(str("X" + str(0) + ":Y" + str(-1)).encode())
            print(str("X" + str(0) + ":Y" + str(-1)))
    elif move == 0:
        ser.write(str("X" + str(0) + ":Y" + str(0)).encode())
        print(str("X" + str(0) + ":Y" + str(0)))
    time.sleep(0.1)

def grab(really):
    if(really):
        global curGrab
        curGrab = not curGrab
        if(curGrab):
            ser.write(str("G").encode())
            print("G R A B")
        else:
            ser.write(str("S").encode())
            print("S T O P")

btnCoreUP = tk.Button(window, text="CoreUP")
btnCoreUP.configure(height=4,width=8)
btnCoreUP.place_configure(relx=0.2,rely=0.8,anchor="center")
btnCoreUP.bind('<ButtonPress-1>',lambda event, which="CORE", move=1: rotate(which, move))
btnCoreUP.bind('<ButtonRelease-1>',lambda event, which="CORE", move=0: rotate(which, move))

btnCoreDOWN = tk.Button(window, text="CoreDOWN")
btnCoreDOWN.configure(height=4,width=8)
btnCoreDOWN.place_configure(relx=0.7,rely=0.8,anchor="center")
btnCoreDOWN.bind('<ButtonPress-1>',lambda event, which="CORE", move=-1: rotate(which, move))
btnCoreDOWN.bind('<ButtonRelease-1>',lambda event, which="CORE", move=0: rotate(which, move))

btnMidUP = tk.Button(window, text="MiddleUP")
btnMidUP.configure(height=4,width=8)
btnMidUP.place_configure(relx=0.2,rely=0.5,anchor="center")
btnMidUP.bind('<ButtonPress-1>',lambda event, which="MID", move=1: rotate(which, move))
btnMidUP.bind('<ButtonRelease-1>',lambda event, which="MID", move=0: rotate(which, move))

btnMidDOWN = tk.Button(window, text="MiddleDOWN")
btnMidDOWN.configure(height=4,width=8)
btnMidDOWN.place_configure(relx=0.7,rely=0.5,anchor="center")
btnMidDOWN.bind('<ButtonPress-1>',lambda event, which="MID", move=-1: rotate(which, move))
btnMidDOWN.bind('<ButtonRelease-1>',lambda event, which="MID", move=0: rotate(which, move))

btnGrab = tk.Button(window, text="Grab")
btnGrab.configure(height=4,width=8)
btnGrab.place_configure(relx=0.5,rely=0.1,anchor="center")
btnGrab.bind('<ButtonPress-1>',lambda event, really=True: grab(really))
btnGrab.bind('<ButtonRelease-1>',lambda event, really=False, move=False: grab(really))

window.mainloop()