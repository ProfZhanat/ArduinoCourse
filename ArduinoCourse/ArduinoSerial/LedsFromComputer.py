import serial
import time
import tkinter as tk
from functools import partial

# Define the serial port and baud rate.
# Ensure the 'COM#' corresponds to what was seen in the Windows Device Manager
ser = serial.Serial('/dev/cu.usbserial-1420', 9600)
time.sleep(2) # wait for the serial connection to initialize
window = tk.Tk()
window.title("ArduinoFromComputer")
window.geometry("100x200")

def led_on_off(direction):
    if direction == "up":
        time.sleep(0.1) 
        ser.write(b'U') 

btnLed = tk.Button(window, text="LED")
btnLed.configure(height=4,width=8,command=partial(led_on_off,"up"))
btnLed.place_configure(relx=0.5,rely=0.5,anchor="center")

window.mainloop()
