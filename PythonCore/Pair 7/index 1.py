from tkinter import *

bomb = 100
score = 0
pressReturn = True

def start(event):
    global pressReturn
    global bomb
    global score
    if not pressReturn:
        fuseLabel.pack()
        label.pack_forget()
        bombLabel.pack_forget()
        scoreLabel.pack_forget()
        pass
    else:
        bomb = 100
        score = 0
        label.config(text = "")
        updateBomb()
        updatePoint()
        updateDisplay()
        pressReturn = False

def updateDisplay():
    global score
    global bomb
    if bomb > 50:
        bombLabel.config(image = normIMG)
    elif 0 < bomb < 50:
        bombLabel.config(image = noIMG)
    else:
        bombLabel.config(image = bangIMG)
    fuseLabel.config(text = "Fuse: " + str(bomb))
    scoreLabel.config(text = "Score: " + str(score))
    fuseLabel.after(100, updateDisplay)

def updatePoint():
    global score
    score += 10
    if isAlive():
        scoreLabel.after(3000, updatePoint)

def updateBomb():
    global bomb
    bomb -= 5
    if isAlive():
        fuseLabel.after(400, updateBomb)        

def click():
    global bomb
    if isAlive():
        bomb += 4

def isAlive():
    global bomb
    global pressReturn
    if bomb <= 0:
        label.config(text = "Bang! Bang! Bang!")
        pressReturn = True
        return False
    elif bomb > 150:
        label.config(text = "YEY YOU SAVE BOMB!!!")
        pressReturn = True
        return False
    else:
        return True
    
def save_max_score():
    global score
    try:
        with open('max_score.txt', 'r') as f:
            max_score = int(f.read())
    except FileNotFoundError:
        max_score = 0

    if score > max_score:
        with open('max_score.txt', 'w') as f:
            f.write(str(score))

def load_max_score():
    try:
        with open('max_score.txt', 'r') as f:
            return int(f.read())
    except FileNotFoundError:
        return 0

root = Tk()
root.title("!!!Bomb Bang!!!")
root.geometry("500x550")
root.resizable(False, False)

label = Label(root, text = "Press [Enter] to start the game!", font = ("Protest Strike", 12))
label.pack()

fuseLabel = Label(root, text = "Fuse HP: " + str(bomb), font = ("Protest Strike", 12))
fuseLabel.pack()

scoreLabel = Label(root, text = "Score: " + str(score), font = ("Protest Strike", 12))
scoreLabel.pack()

MscoreLabel = Label(root, text = "Max Score: " + str(score), font = ("Protest Strike", 12))
MscoreLabel.config(text = "Max Score: " + str(load_max_score()))
MscoreLabel.pack()

normIMG = PhotoImage(file="bomb_normal.png")
noIMG = PhotoImage(file = "bomb_no.png")
bangIMG = PhotoImage(file = "pow.png")

bombLabel = Label(root, image = normIMG)
bombLabel.pack()

clickB = Button(root, text="Click to BANG", bg="grey", command=click, font=("Protest Strike", 14), width=20)
clickB.pack()

save_max_score()

root.bind('<Return>', start)

root.mainloop()