# Smart Methods IoT

##  About this repository 
This repository contain all my work in the IoT track as a trainee at **Smart Methods**


## Installation
 
To use **ESP32** device using Arduino IDE there are few steps before we can start upload code to ESP32.

1. Make sure you have [Arduino IDE](https://www.arduino.cc/en/software) installed.
1. In Arduino IDE go to *File>Preferences>Settings* , in **Additional Boards Manager URLs**, past this URL

```sh
https://dl.espressif.com/dl/package_esp32_index.json
```
then click OK button
1. In your IDE go to Sketch>Include Library>Manage Libraries, in the search field type ESP32, then install **esp32** by **Espressif Systems**.
![board manager window](/images/esp32_library.PNG)

1. After you install esp32 packege, in your IDE navigate to *Tools>Board>ESP32 Arduino*, then select **ESP32 Dev Module** (if you have a different esp32 module you should select it).
![boards window](/images/esp32_boards.png)

1. Plug in the esp32 module to your computer then navigate to *Tools>Port* then select the ESP32 port.
![serial ports window](/images/esp32_port.png)

Now you are ready to upload code to ESP32 module, the shortcut to upload code is **Ctrl + U**

## Task 1: Working with ESP32 & Speech To Text Recognition 

In the first task we have to do two things:
1. The first thing is to work with ESP32 module, from installing the libarary to upload code to the ESP32 module, in Task1 folder there is a file **Serial_Blink.ino** , where you can control the on board LED using the Serial Monitor window:

| Command  | Result |
| ------------- |:-------------:|
| off      | turn off LED     |
| on      | turn on LED     |
| delay 100 | LED blink every 100ms |

2. The second thing we have to do is to develop a simple website that transform the speech from the user to a Arabic text.
![speech recongintion website](/images/speechToText.png)
