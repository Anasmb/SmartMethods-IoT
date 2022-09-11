# Smart Methods IoT



## Table of Contents
1. [About](#about)
2. [Task 1: Speech To Text Website, Initialize ESP32 Module](#task1)
3. [Task 2: Control Arduino using speech](#task2)
4. [Task 3: POST and GET from database](#task3)
5. [Task 4: Control robot movement using a website](#task4)


<div id='about'/>

##  About this repository 
This repository contain all my work in the IoT track as a trainee at **Smart Methods**



<div id='task1'/>

## Task 1: Working with ESP32 & Speech To Text Recognition:

### Installation
 
To use **ESP32** device using Arduino IDE there are few steps before we can start upload code to ESP32.

1. Make sure you have [Arduino IDE](https://www.arduino.cc/en/software) installed.
1. In Arduino IDE go to *File>Preferences>Settings* , in **Additional Boards Manager URLs**, past this URL

```sh
https://dl.espressif.com/dl/package_esp32_index.json
```
then click OK button
1. In your IDE go to Sketch>Include Library>Manage Libraries, in the search field type ESP32, then install **esp32** by **Espressif Systems**. <br>
![board manager window](/images/esp32_library.PNG)

1. After you install esp32 packege, in your IDE navigate to *Tools>Board>ESP32 Arduino*, then select **ESP32 Dev Module** (if you have a different esp32 module you should select it).
![boards window](/images/esp32_boards.png)

1. Plug in the esp32 module to your computer then navigate to *Tools>Port* then select the ESP32 port.
![serial ports window](/images/esp32_port.png)

Now you are ready to upload code to ESP32 module, the shortcut to upload code is **Ctrl + U**

### Get Started

In the first task we have to do two things:
1. The first thing is to work with ESP32 module, from installing the libarary to upload code to the ESP32 module, in Task1 folder there is a file **Serial_Blink.ino** , where you can control the on board LED using the Serial Monitor window:

| Command  | Result |
| ------------- |:-------------:|
| off      | turn off LED     |
| on      | turn on LED     |
| delay 100 | LED blink every 100ms |

2. The second thing we have to do is to develop a simple website that transform the speech from the user to a Arabic text.
![speech recongintion website](/images/speechToText.png)


<div id='task2'/>

## Task 2: Control Arduino/ESP32 Using Speech To Text:

In this task we have to control the Arduino/ESP32 using speech to text website we have made in **Task 1** <br>
To be able to control and communicate with the Arduino, we should use the serial port, and to use the serial port in a website
we should use the [Web Serial API](https://web.dev/serial/)

**Note:** We recommend to use **Google Chrome** browser to be able to use **Web Serial API**.

1. Connect a servo to pin 9 in Arduino, similar to the circuit below.
![Sweep Circuit](https://docs.arduino.cc/static/943895f1f578104f7af98741d69a7c97/29114/servo-sweep-circuit.png) 

2. Connect the Arduino to your computer and use the file "SpeechCommand.ino" in "Task 2" folder, then upload the code.

3. In "Task 2" folder use the html and css files, the page should look like this ![Control Arduino Using Speech](/images/cntrl_arduino_website.JPG) 

4. Click **Start Recording** button, then select the serial port for the connected Arduino
![request serial port connection window](/images/serial_port_request.png)

**Note:** Port number is different from computer to computer, in my computer it is *COM6*, it may be different in your computer.

5. Allow the browser to use your microphone, then try to say "Right" or "Left", or in **Arabic** you can say "يمين" or "يسار".
<br> if you say *"Right"* or *"يمين"* the servo should turn right, same thing if you say *"Left"* or *"يسار"* the servo should turn left.

<div id='task3'/>

## Task 3: POST and GET from database:

In this task we will have a ESP32 with dht11 sensor (temperature & humidity sensor). <br>
we will read the temperature and humidity values and send it to **MYSQL** database, then we will get data from the database
and display the values to a website.<br>
**Note:** we can collect any type of data from any sensor and send it to the database.

### Pre-requisites:

To be able to send and get data from MYSQL database we have to install MYSQL database, you can use [XAMPP](https://www.apachefriends.org/) which i an open-source cross-platform web server.

### Explanation Walkthrough:

1. After installing **XAMPP** create a folder named "sensors" in xampp path *xampp>htdocs*

2. Copy the two files in Task3, **insert_temp.php** and **getSensorValues.php** to sensors folder

3. connect dht sensor to the ESP32 like this circut ![dht11 circut](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/04/dht_esp32_bb.png?w=714&quality=100&strip=all&ssl=1)

**Note:** use can use any sensor you would like.

4. Before uploading the code **DHT_MYSQL.ino** in Task3 folder, make sure to change the **ssid** and **password** to your WiFi

5. In **phpMyAdmin**, create a database named "esp32", then create a table named "dht" with values shown in below image 
![dht table values](/images/phpMyAdmin.JPG)

6. Now power ON the ESP32 and use the **index.html** and **app.css** files in *Task3* to test it.

7. Let the ESP32 run for few minutes to send data to MYSQL database, and as you can see database now have temperature and humidity data as shown below: ![dht data](/images/dht_data.JPG)

8. the website should GET these data from the database and display it (display last added row) as shown below:
![website get data](/images/mysql_get_website.JPG)

<div id='task4'/>

## Task 4: Control robot movement using a website:
In this task we have made a website with buttons to control the robot, either move forward/backward or turn right/left
![website joystick](/images/joystick_website.JPG)

The way this work, we made a new table name "movement" in the database, similar to **Task3**, and the ESP32 code **Movement.ino**
in **Task4** will read the data from the database frequently using GET method. <br>
when the user click the forward button, the website will send "forward" to the database and ESP32 will read it to move forward, and when the user click the right button, we will send "right" to the database and ESP32 will also turn right. <br>
![movement database](/images/movement_db.JPG)

As you see in the image above, we also register how long did the user pressed the button, he clicked the forward button for **3.3** seconds and clicked the right button for **1.6** seconds. This is useful later if we want the robot replay what the user clickd before.
