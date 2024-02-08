from tkinter import *

colors = {
    "Dark Slate Gray": "#79cdcd",
    "Dark Turquoise": "#00ced1",
    "Dark Violet": "#9400d3",
    "Deep Pink 1": "#ff1493",
    "Deep Pink 4": "#8b0a50",
    "Deep Sky Blue 1": "#00bfff",
    "Deep Sky Blue 3": "#009acd",
    "Dim Gray": "#696969",
    "Dodger Blue 1": "#1e90ff",
    "Dodger Blue 3": "#1874cd"
}

def create_palette():
    root = Tk()
    root.title("Color Picker!")
    root.geometry("580x380")
    root.resizable(False, False)

    for color, hex_code in colors.items():
        frame = Frame(root, width=80, height=40)
        frame.pack(fill=X)
        label = Label(frame, text=f"{color}", width=20, height=2)
        label.pack(side=LEFT)
        label.config(highlightbackground="lightgrey", highlightthickness=1)
        color_frame = Frame(frame, bg=hex_code, width=300, height=38)
        color_frame.pack(side=LEFT)
        color_frame.config(highlightbackground="lightgrey", highlightthickness=1)
        label_hex = Label(frame, text=f"{hex_code}", width=20, height=2, fg="#268bd2")
        label_hex.pack(side=LEFT)
        label_hex.config(highlightbackground="lightgrey", highlightthickness=1)

    root.mainloop()

create_palette()