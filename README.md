# Ambient Display (for Dell)

This small utility is used for controlling your Dell monitor brightness level. It's using an Arduino Micro microcontroller in combination with a photonic resistor as light sensor.

### Prerequiries
- Arduino Micro/Nano/Uno etc. (as long it has analog inputs)
- Photonic resistor.
- Dell monitor (by example the U2515H or U2715H) that works with the Dell Display Manager utility.
- Dell Display Manager installed.
- Optional: pywin32 installed

### Setup
1. Download this repository.
2. Upload the Arduino sketch, which is located in the /arduino folder.
3. Change the COM port in run.py, on line 27.
4. Run ```python run.py``` to startup the brightness handler.
5. Optional: run ```python setup.py``` if you have installed pywin32.
6. Optional: move the generated .exe in the /dist folder into the Startup Common folder.

### Notes
This is a small hobby project. Don't expect perfectly written code ;)

Disclaimer: this project is created by a third party and not associated with Dell, Dell Display Manager or other mentioned companies.
