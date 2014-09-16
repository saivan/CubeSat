##This code is written for design the modes for the gammasat.
  
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


while a == 0:
    safe_mode()
               


while a == 1:
    recovery_mode()
        


while a == 2:
    normal_mode()
        


while a == 3:
    science_mode()
        


while a == 4:
    payload_mode()
        


while a == 5:
    transmit_mode()
        

        
        
