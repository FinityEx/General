#text-too-speech
import tkinter as tk
import gtts 
import playsound as ps
import os

def play():
    message = text.get()
    speech = gtts.gTTS(text = message, lang='en', slow=False)
    speech.save("playback_audio.mp3")
    ps.playsound("playback_audio.mp3")
    
def reset():
    os.remove("playback_audio.mp3")
    text.set("")
    
def exit():
    window.destroy()

window = tk.Tk()
window.geometry("400x400")
window.title("Text to speech")

text = tk.StringVar()

tk.Label(window, text="ENTER TEXT:", font="Arial 15 bold").place(x=50, y=150)
tk.Entry(window, textvariable = text).place(x = 200, y=140, height=50, width=150)
tk.Button(window, text="start", bg = "seashell2", font="Arial 15 bold", command = play).place(x=70, y=250)
tk.Button(window, text="reset", bg = "seashell2", font="Arial 15 bold", command = reset).place(x=170, y=250)
tk.Button(window, text="exit", bg = "seashell2", font="Arial 15 bold", command = exit).place(x=270, y=250)
window.mainloop()

