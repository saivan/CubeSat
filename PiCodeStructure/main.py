## Main loop for Raspberry Pi

#Call functions from the functions.py file
import functions


##This is lika a switch to turn on and turn off the satellite.
start = input('enter 0 or 1 to make all the satellite work or sleep: ')
start = int(start)

##0 means satellite is not work;
while start == 0:
    break

##1 means satellite is ready to work.
while start == 1:

##a here is defined as a satellite mode
    a = input('Input your mode number: ')
    a = int(a)

    if a == 0:
        safe_mode()
                   


    elif a == 1:
        recovery_mode()
            


    elif a == 2:
        normal_mode()
            


    elif a == 3:
        payload_mode()
            


    elif a == 4:
        transmit_mode()
            

            
            
