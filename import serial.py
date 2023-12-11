import serial
import datetime
import time

ser = serial.Serial('COM10', 9600)  # Replace 'COM3' with your Arduino's serial port
file_path = r"C:\Users\Käyttäjä\Desktop\School2\School\Sensors and Signal Connection\data.txt"  # Replace with your actual file path



while True:
        time.sleep(5 * 60)
        if ser.in_waiting > 0:
            with open(file_path, 'a') as file:
                current_time = datetime.datetime.now()
                current_time = str(current_time)
                new_current_time = ""

                for i in current_time:
                    if i == ".":
                        break
                    else:
                        new_current_time += i

                data = ser.readline().decode('utf-8').strip()
                print (f"{new_current_time} \t {data}")
                file.write(f"{new_current_time} \t {data} \n")

