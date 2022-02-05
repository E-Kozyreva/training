#Import modules
from tkinter import*
import time

#Creating a window
root = Tk()
#Window name
root.title('Time with Python')

def tick():
    watch.after(200, tick)
    # Changing the time to the current one
    watch['text'] = time.strftime('%H:%M:%S')

#Setting the font and text size
watch = Label(root, font='Serif 40')
#Location in the center
watch.pack()

#Launching the function
tick()

root.mainloop()
