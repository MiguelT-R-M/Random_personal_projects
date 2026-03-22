import pyautogui as PYG
import time
import keyboard as KEY
import mouse as MOU

def printNonStop():
    PYG.PAUSE = 0.5
    CRAZY = True
    while CRAZY == True: 

        PYG.press('1')
            
        PYG.press('backspace')

        if(KEY.is_pressed('ctrl+shift+q')):
            CRAZY = False
            print("STOP")

def clickNonStop():
    PYG.PAUSE = 0
    CRAZY = True
    while CRAZY == True: 
        if(MOU.is_pressed(button="right")):
            print("Is pressed!")
            PYG.click()

        if(KEY.is_pressed('ctrl+shift+q')):
            CRAZY = False
            print("STOP")

def Main():
    print("AUTOCLICKER BEGIN")
    print("ctrl+shift+alt+k for auto press")
    print("ctrl+shift+alt+m for auto click")
    print("ctrl+shift+alt+q to stop")
    while True == True:
        CRAZY = True
        time.sleep(1)

        if (KEY.is_pressed('ctrl+shift+alt+k')): ## Starts auto press
            print("START")
            printNonStop()

        if (KEY.is_pressed('ctrl+shift+alt+m')): ## Starts auto press
            print("START")
            clickNonStop()

Main()


