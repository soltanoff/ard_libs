# Numpad
========================

Class for interaction with a matrix key block (3x3 or 4x4). 
This class processes keystrokes and collects them into a `string` buffer (from `ArduinoSTL.h`).


To interact with other devices, a pointer is passed to the `SoftwareSerial` object, 
and by pressing the key keys, the data is sent, the buffer is cleared, or the buffer 
is changed.


List of keys:
* A - send data;
* B - remove the last character from the buffer;
* C - clear the buffer;
* Other keys - write them to the end of the buffer.


The connection diagram is shown in the file.