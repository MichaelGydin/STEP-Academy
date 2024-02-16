from tkinter import *
from tkinter import messagebox
import pickle
import subprocess

def registration():
    label_error = None

    frame = Frame(root, bd=10)
    frame.place(relx =0.5, rely = 0.2, relwidth=0.7, relheight=0.6, anchor="n")

    label = Label(frame, text="Sign Up", font ='16')
    label.place(relwidth=1, relheight=0.1)

    label_login = Label(frame, text="Login: ")
    label_login.place(rely=0.2, relwidth = 0.35, relheight=0.1)

    loginREG = Entry(frame)
    loginREG.place(rely=0.2, relwidth=0.55, relheight=0.1, relx=0.4)

    label_password1 = Label(frame, text="Password: ")
    label_password1.place(rely=0.4, relwidth=0.35, relheight=0.1)

    password1 = Entry(frame, show="*")
    password1.place(rely=0.4, relwidth=0.55, relheight=0.1, relx=0.4)

    label_password2 = Label(frame, text="Confirm password: ")
    label_password2.place(rely=0.6, relwidth=0.35, relheight=0.1)

    password2 = Entry(frame, show="*")
    password2.place(rely=0.6, relwidth=0.55, relheight=0.1, relx=0.4)
    
    but = Button(frame, text = "Sign Up", command = lambda: signup())
    but.place(relx = 0.3, rely = 0.8, relheight = 0.15, relwidth = 0.5)

    def signup():
        nonlocal label_error
        error = ""

        if label_error:
            label_error.destroy()
        
        if len(loginREG.get()) == 0:
            error = "*login error"
        elif len(password1.get()) <5:
            error = "*Your password needs to be at least 5 characters"
        elif not password1.get() == password2.get():
            error = "*Your password nedds to be the same"
           
        else:
            save()
            
        label_error = Label(frame, text = error, fg = "red")
        label_error.place(rely = 0.7)
                
    def save():
        data = dict()
        data[loginREG.get()] = password1.get()
        with open("login.txt", 'wb') as f:
            pickle.dump(data, f)
        login()

def login():
    frame = Frame(root, bd=10)
    frame.place(relx =0.5, rely = 0.2, relwidth=0.7, relheight=0.6, anchor="n")
    
    label = Label(frame, text="Sign In", font ='16')
    label.place(relwidth=1, relheight=0.1)
    
    label_login = Label(frame, text="Login: ")
    label_login.place(rely=0.2, relwidth = 0.35, relheight=0.1)

    loginREG = Entry(frame)
    loginREG.place(rely=0.2, relwidth=0.55, relheight=0.1, relx=0.4)

    label_password1 = Label(frame, text="Password: ")
    label_password1.place(rely=0.4, relwidth=0.35, relheight=0.1)

    password1 = Entry(frame, show="*")
    password1.place(rely=0.4, relwidth=0.55, relheight=0.1, relx=0.4)
    
    but = Button(frame, text = "Login", command = lambda: loginPass())
    but.place(relx = 0.3, rely = 0.8, relheight = 0.15, relwidth = 0.5)

    def loginPass():
        with open("login.txt", 'rb') as f:
            a = pickle.load(f)
        if loginREG.get() in a and password1.get() == a[loginREG.get()]:
            messagebox.showinfo("Welcome", "Welcome to Bang Bomb!")
            subprocess.run(['python', 'index 1.py'])
        else:
            messagebox.showerror("ERROR", "Invalid password or login!")

    
root = Tk()
root.title("Registration/Login Form")
root.geometry("550x600")
root.resizable(False, False)

root.option_add("*Font", "Calibri")
root.option_add("*Background", "yellowgreen")

img = PhotoImage(file = "bg3.gif")
backgroundLabel = Label(root, image = img)
backgroundLabel.place(relwidth = 1, relheight = 1)

butSignup = Button(root, text = "Sign Up", command=registration)
butSignup.place(relx = 0.15, rely = 0.1, relwidth=0.3)

butSignin = Button(root, text = "Sign In", command=login)
butSignin.place(relx = 0.55, rely = 0.1, relwidth=0.3)

root.mainloop()