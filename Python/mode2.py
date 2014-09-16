##This code is written for design the modes for the gammasat.

##This is lika a switch to turn on and turn off the satellite.
start = input('enter 0 or 1 to make all the satellite work or sleep: ')
start = int(start)

##0 means satellite is not work;
##1 means satellite is ready to work.
while start == 0:
    break
while start == 1:

##a here is defined as a satellite mode
    a = input('Input your mode number: ')
    a = int(a)

    class safe_mode():
        def __init__(self):
            print('This is safe_mode')
            
    class recovery_mode():
        def __init__(self):
            print('This is recovery_mode')
            
    class normal_mode():
        def __init__(self):
            print('This is normal_mode')
            
    class science_mode():
        def __init__(self):
            print('This is science_mode')
            
    class payload_mode():
        def __init__(self):
            print('This is payload_mode')
            
    class tranmit_mode():
        def __init__(self):
            print('This is transmit_mode')


    if a == 0:
        safe_mode()
                   


    elif a == 1:
        recovery_mode()
            


    elif a == 2:
        normal_mode()
            


    elif a == 3:
        science_mode()
            


    elif a == 4:
        payload_mode()
            


    elif a == 5:
        transmit_mode()
            

            
            
