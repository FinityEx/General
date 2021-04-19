#Aim of this project is to learn communicating with APIs by creating an app that has access to my liked youtube videos to be played in tkinter GUI randomly.
#Sadly, as this was first project I have done from scratch, I didn't think about how many URLs can youtube api return. Turns out, it's only 50 per page.
import pafy
import os
os.add_dll_directory(r'C:\Program Files\VideoLAN\VLC') #path to VLC installation folder
import yt
import vlc
import tkinter as tk


def play():
    url = yt.get_url()
    video = pafy.new(url)
    best = video.getbest()
    playurl = best.url
    Media = Instance.media_new(playurl)
    Media.get_mrl()
    player.set_media(Media)
    player.play()


def stop():
    player.stop()
    
Instance = vlc.Instance()
player = Instance.media_player_new()
root = tk.Tk()
tk.Button(root, text="play",  command = play).pack()
tk.Button(root, text="stop",  command = stop).pack()
root.mainloop()



