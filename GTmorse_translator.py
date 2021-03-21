#Morse translator
import re
morse = {'A':'.-', 'B':'-...', 'C':'-.-.', 'D':'-..', "E":'.', 'F':'..-.', 'G':'--.', 'H':'....', 'I':'..', 'J':'.---', 'K':'-.-', 'L':'.-..', 'M':'--', 'N':'-.', 'O':'---', 'P':'.--.', 'R':'.-.', 'S':'...', 'T':'-', 'U':'..-', 'W':'.--', 'Y':'-.--', 'Z':'--..'}
morse_val = list(morse.values())
morse_key = list(morse.keys())


s = input("Input text in lating or Morse: ").upper()
    
def ttom():   #text to morse 
    str = list(s) #split s into list of characters
    for c in str:
        if c == " ":
            print("/", end = ' ')
        elif c in morse_key:
            ind = morse_key.index(c)
            print(morse_val[ind], end=' ')
        else:
            print("\nwrong symbol: ", c)


def mtot(): #morse to text
    str = re.findall(r'\S+', s) #used re because doesn't work with .split()
    for x in str:
        if x == "/":
            print(" ", end=' ')
        elif x in morse_val:
                ind = morse_val.index(x)
                print(morse_key[ind], end='')
        else:
            print("\nwrong symbol: ", x)
                
if '-' in s:
    mtot()
else:
    ttom()