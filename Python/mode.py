##This code is written for design the modes for the gammasat.
  
a = input('Input your mode number: ')
a = int(a)


while a == 0:
    def safe_mode():
        print('This is safe_mode')       
    safe_mode()
    def check_mode():
        a = input('Input your mode number: ')
        a = int(a)
    check_mode()

while a == 1:
    def recovery_mode():
        print('This is recovery_mode')
    recovery_mode()

while a == 2:
    def normal_mode():
        print('This is normal_mode')
    normal_mode()

while a == 3:
    def science_mode():
        print('This is science_mode')
    science_mode()

while a == 4:
    def payload_mode():
        print('This is payload_mode')
    payload_mode()

while a == 5:
    def transmit_mode():
        print('This is transmit_mode')
    transmit_mode()

        
        

        
