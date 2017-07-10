import serial
from subprocess import call
from time import sleep

def setBrightness(brightness):
    call("C:/Program Files (x86)/Dell/Dell Display Manager/ddm.exe SetBrightnessLevel " + str(brightness))

def connect(ser):
    connected = False
    print("Connecting...")

    while not connected:
        try:
            ser.open()
            connected = True
        except Exception as e:
            #raise Exception("Unable to connect to COM17")
            pass

        sleep(5)

    print("Connected!")


ser = serial.Serial()

ser.port = 'COM17'
ser.baudrate = 9600

connect(ser)

try:
    while True:
        sleep(1)
        try:
            if ser.inWaiting() > 0:
                brightness = int(ord(ser.read()))
                if brightness >= 0 and brightness <= 100:
                    print("Setting brightness to " + str(brightness))
                    setBrightness(brightness)
        except Exception as e:
            ser.close()
            connect(ser)

except KeyboardInterrupt:
    pass

ser.close()
