#Google translate, working only from English to Polish as I can't seem to have it working in versataile mode. 

from googletrans import Translator
import tkinter as tk

translator = Translator()

#function def
def trans():
    result = translator.translate(text1.get(), src='en', dest='pl')
    result.src='en'
    result.dest='pl'
    transText.set(result.text)
    print(result)
    
#main window
window = tk.Tk()
window.geometry("800x800")
window.title("Poor man's translator.")

#text variable
text1 = tk.StringVar()
transText = tk.StringVar()

#Labels
tk.Label(window, text="Translate from English:", font="Arial 20 bold").pack()
tk.Label(window, text="To Polish ", font="Arial 20 bold").place(x=250, y=300)

#entry box
tk.Entry(window, textvariable=text1).place(x=120, y=70, width=500, height=100)
tk.Entry(window, textvariable=transText).place(x=120, y=400, width=500, height=100)
#button
tk.Button(window, text="translate", bg="seashell2", command = trans).pack(side=tk.BOTTOM)

window.mainloop()