#Simple downloader from Youtube URLs that uses Tkinter GUI.

import tkinter as tk
import pytube as yt

window = tk.Tk()
window.geometry("800x400")
window.title("Youtube Downloader")

def download():
    try:
        url = yt.YouTube(str(link.get()))
        video = url.streams.first()
        video.download()
        tk.messagebox.showinfo(message="Success!")
    except:
        tk.messagebox.showerror(message="Invalid URL!")
    

link = tk.StringVar()

tk.Label(window, text="YOUTUBE VIDEO DOWNLOADER", font="Arial 20 bold").pack()
tk.Label(window, text="paste your link here:", font="Arial 10 bold").pack()

tk.Entry(window, textvariable = link).place(x=200, y=100, width=400)

tk.Button(window, text="DOWNLOAD", font="Arial 10 bold", bg="seashell2", command=download).pack(side=tk.BOTTOM)

window.mainloop()