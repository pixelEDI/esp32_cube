![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)

<img src="https://github.com/pixelEDI/esp32_cube/blob/7101cef0eae3d0636a241fbe2dc87245dcbea2cb/rubikscube_holder.jpg" width="500">

## Source for this project
https://github.com/playfultechnology/esp32-smartcube/blob/master/esp32-smartcube.ino

## General info 

* ESP32 to Bluetooth Rubiks Cube
* Practice and track your solving speed
* I push the results via MQTT to Node-RED, process the data and save it to a Database
* After a solve, the time is be saved and afterwards the top 3 solves of the month get fetched via MQTT and displayed on the OLED

## Adapt the Sketch
* find MAC from your Cube
* edit your MAC in "ble_rubikscube.h" line 11
* edit your crednetials wifi + mqtt
* partition scheme has to be changed because wifi + ble needs a lot of flash space

## Database
The

You like it? Then I would be very happy if you treat me to a coffee on [ko-fi.com/pixeledi](https://www.ko-fi.com/pixeledi)
