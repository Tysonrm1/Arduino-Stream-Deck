# Arduino-Stream-Deck
This is the git repo where I will be posting the code, circuits and the instructions for the arduino stream deck as found on printables here https://www.printables.com/model/180765-arduino-stream-deck. Being a student working a part time job I will have limited time to continue to develop the instructions and code. While the stream deck is completed and has been sent to its final owner. I still plan to further the development of this project by streamlining the effort required to build it as well as adding functionality and compatibility for other microcontrollers. Suggestions for features and ways that I can improve the stream deck are appreciated and I am open to colaborating in the development of this project.    

# Description
This stream deck was designed as a tool to allow the user more efficient control over their pc and workflow. all of the code will be published on github as well as the steps I took while creating this device. I designed this to be budget friendly while still maintaining an acceptable amount of features.

# Skills Required
As this was not initially created to be posted. The circuitry and design is all custom handmade on perf board. This means that you will need to be comfortable soldering circuits and have at least a basic understanding of what the individual parts do and how they interact with each other. This will greatly reduce the headache when debugging and troubleshooting the hardware.

# Parts List
The parts I used in this stream deck are listed as follows.

24x or 32x 5mm momentary push buttons depending on which top plate you print. I purchased this set off of amazon https://amzn.to/3vsRNdS 

1x rotary encoder. I purchased this set of 5 from WayinTop https://amzn.to/3rUyA2r 

1x 16mm diameter latching toggle push button. I couldn't find the exact one that I used for this build but any 16mm toggle like the set linked should work https://amzn.to/37SqHUj

1x arduino uno r3. I used the uno because I had one lying around but it is possible to adapt this to work with other microcontrollers. If requested I can revisit the design and work on adding compatibility.

3x 3cm x 7cm perfboard, 2x 2cm x 8cm perfboard, 1x 4cm x 6cm perfboard, and various pins and headers. I bought this kit that lasted me around a year and a half over various projects https://amzn.to/38yPlsV

various wire, I use old dupont wires that had long since had the crimped connections fall apart, though this could be any wire within reason.

I also recommend getting Jst connectors to allow for a much easier time disconnecting and reconnecting all of the buttons on the top plate from the arduino when disassembling to troubleshoot. https://amzn.to/37SCYrV 

11x or 13x M3 heat set inserts depending on which top plate was printed. I linked the pack that I used but any with similar dimensions will work https://amzn.to/3rYByTF

2x or 4x 12mm M3 socket head cap screws depending on which top plate was printed, 9x 8mm M3 Socket head cap Screws. I bought this pack https://amzn.to/3rYByTF quite a while ago but any will work.

# Microcontroller choice
I chose the uno because I had an old one with a blown 3v3 regulator lying around. This was convenient because the arduino uno has enough pins without needing an 8-bit shift register like the 74HC595N. The main downside of the uno is having to reflash the firmware to the ATmega16u2 every time you want to update the code. Luckily this is fairly straightforward using Atmel Flip and I will cover it extensively later on in the instructions.

# Firmware

## Arduino Code
Before you can upload the Arduino_stream_deck.ino file to your arduino uno you will need to download and install the RotaryEncoder library by mathertel found here https://github.com/mathertel/RotaryEncoder.git.

## HID Functionality
As previously mentioned the Arduino Uno does not come with HID functionality from factory so we will have to flash new firmware to the ATmega16u2 chip.
The two hex files included contain the firmware required to convert your arduino to an HID device and back again. To do this we will use the Atmel Flip software found here https://www.microchip.com/en-us/development-tool/flip#Software.
The images below show the steps to reflash your atmel chip.

### *Note the arduino stream deck code must be uploaded on the arduino before the firmware is updated.*

### Step 1: click on the top left button and confirm that the chip selected is the ATmega16u2

![First step](https://user-images.githubusercontent.com/86377881/166090975-e85c889c-b857-4f89-b279-84607302c108.PNG)

![Seccond step](https://user-images.githubusercontent.com/86377881/166090985-bd3a59b0-562a-4f2a-9590-cf149dafb68f.PNG)

### Step 2: Use a jumper wire to short the first two jumper pins on the arduino closest to the usb port. Note you only have to do this momentarily as it will set your ATmega16u2 into a Firmware Update mode.

![Step three](https://user-images.githubusercontent.com/86377881/166090991-4e7f12be-3b89-497d-bf57-a3ef3f05ad70.png)

### Step 3: Remove the jumper cable from the pins and click on the select communication medium button. Select usb and click open, if you did it right there will be no errors and at the bottom right you will see USB ON. 

![Step four](https://user-images.githubusercontent.com/86377881/166090993-d6277721-18df-430c-bf93-3d9bc265b554.PNG)

![Step five](https://user-images.githubusercontent.com/86377881/166090996-8cd9788a-62c0-41ea-95cb-552acc9c1146.png)

![Step six](https://user-images.githubusercontent.com/86377881/166090997-f7b783c5-9126-4b1e-b229-f35e2f03311f.PNG)

### Step 4: Click on file in the top left and use the Load HEX File button to select the new firmware to flash to your Atmega. If you are configuring it for the stream deck select the Arduino-keyboard-0.3.hex file and if you are returning it to its default state select the Arduino-usbserial-uno.hex file both of which are included in this repository. 

![Step seven](https://user-images.githubusercontent.com/86377881/166091000-fab45503-9390-4870-bd08-16760043204d.PNG)

![Step eight](https://user-images.githubusercontent.com/86377881/166091023-da8ddc44-1d22-4c78-a382-4994d59d047b.png)

### Step 5: You should see the name of the file you are going to flash to the chip in the middle of the window. If this is the correct file click on Run and let it load. Once it finishes you should see three green indicators and a Verify PASS tag in the bottom left. 

![step nine](https://user-images.githubusercontent.com/86377881/166091888-d202638b-63db-49d4-becc-91d76b4d29dc.PNG)

![step ten](https://user-images.githubusercontent.com/86377881/166091895-edee7d7d-bb97-4ef8-9b8e-41dd6dc4c338.PNG)

![step eleven](https://user-images.githubusercontent.com/86377881/166091899-6000f97e-8553-48d3-b728-fcc95415d469.PNG)

### Step 6: If you experienced no errors in the previous steps click Start Application. This will disconect your arduino and you can unplug and replug it back in to the computer to complete the installation.  

![step twelve](https://user-images.githubusercontent.com/86377881/166091900-560ed590-8963-47b8-98a7-efcf96c84314.PNG)

# Wiring & Circuitry

## Arduino Uno Breakout Board
The breakout board for the arduino uno requires the most soldering of all the boards for this project. It is built on 5cm x 7cm perfboard with a pitch of 2.54mm. Below is a picture of the circuit with pins listed. It should be noted that in order to reach pin 9 you will have to bend your header and may have to move it over by one on the perf board. I reccomend building this circuit on a breadboard prior to soldering it on perfboard so that any issues can be fixed before hand. The easiest way to solder this circuit is to cut all of the headers and install them in the arduino before placing the perfboard on top, this will hold the perfboard and ensure all of the pins will line up correctly and fit in the arduino when removed. The spacing may be tight and the arduino female headers may need to be pulled together slightly in order to fit the pins in the perfboard. Be cautious when soldering the pins like this as too much heat can melt the arduinos female headers, I recommend not soldering pins back to back but rather switching sides of the header after each pin to allow for heat dissapation. All of the Pins / wires are 2 wire 22 AWG JST connectors with the exception of pins D2 D3 and D4 which are the three pins for the rotary encoder and its button, for these I soldered on a male 3 pin header. the +5v and GND out pins also go to the rotary encoder module where I replaced the power input pins with a JST connector for easier access.    


![arduino uno breakout board stream deck](https://user-images.githubusercontent.com/86377881/167210740-661cc363-2b2f-4ef8-b9f9-64ac5a71ae45.png)

![IMG_1524 (2)](https://user-images.githubusercontent.com/86377881/167215690-d0f52fda-2d5b-44d1-82a8-e2a115c5ef4b.JPEG)

![IMG_1527](https://user-images.githubusercontent.com/86377881/167215155-38148b17-a169-42b4-bd24-2a277a6510b5.JPEG)

## Arduino Usb Port
The arduino uno uses a printer cable to communicate with the computer. I wanted to retain this connector while allowing a cleaner fitment at the back of the Stream Deck. In my case I already had a printer cable port lying around but you can also use the one that came with your arduino. It is very important to keep the pinout correct throughout this proccess and I made sure to take note of each pins connection before hand. Since I already had an extra printer cable port I opted to start by soldering it on to the center of a 8cm x 2cm perfboard with a pitch of 2.54mm. I reccomend printing the Usb Port Fitment Guide first to test fitment tolerances and to mark the location of the usb port. To mark the location first put the perfboard in its mounts on the guide then set the usb port on top of it, it may help to flip the usb port upside down and use the flat top during this step. Then line up the port with the hole in the case and use a sharpie to mark the board on both sides of the usb port. You will have to bend the mounting pins so that the port sits flush with the surface of the board when the signal and power pins are seated correctly. After this is done you can line up the port with your marks and determine how far out you need to solder the usb port in order for it so sit flush in the hole of the case. Once the signal and power pins are soldered to the board you can do some fine adjustments if needed before soldering the mounting pins flush to the surface of the board to secure its position. Now that this is done and you have confirmed that the board fits by reinserting it in the mounting guide you are ready to work on the circuit itself. If your arduino still has its usb port on it I reccomend desoldering that now as it will make the next step much easier. In the photos below you can see that I left the usb port on while testing but I went back and removed it later. To begin I recommend that you solder all of the pins from the perf board directly to the arduino with 4 wires to confirm that it functions as intended. If everything works correctly you can desolder the power and ground pins from the arduino as we will have to add our power button inline. I dont have a photo of the header itself but I added a 3 pin header with the 5v wire of the usb on one of the pins and the ground on the other, we will come back to the third pin in a minute. the 5v pin is where we will plug our power buttons common into and the ground will go to the buttons led negative. Depending on the rated voltage of your power buttons led you may need to solder a resistor from the NO (normally open) pin of the button to the led positive pin but if your buttons led is rated for 5v or higher you can just directly connect it without the resistor. Next you will need to add another wire from the NO pin of the button, this one is going to go to the third pin on the header that we added to the perf board. From here you are ready to resolder your ground to the arduino making sure to not disconnect it from the header on the perf board in the proccess. the last step is to take the 3rd pin on the board which connects to the NO pin on your button and solder it to the correct pin on the arduino.  

![IMG_1417](https://user-images.githubusercontent.com/86377881/167230654-fd9d217d-a540-4537-b1e0-d57afc3bdd6e.JPEG)

![IMG_1419](https://user-images.githubusercontent.com/86377881/167230663-f7d6e41b-4d00-4800-9049-01de8414e822.JPEG)

![IMG_1497](https://user-images.githubusercontent.com/86377881/167230676-17e8cdb1-347d-4062-8a8a-d643b8167b26.JPEG)

![IMG_1418](https://user-images.githubusercontent.com/86377881/167230687-4abca6bb-9768-48c3-8b92-0fbb32855341.JPEG)

![printer cable conector usb_LI (2)](https://user-images.githubusercontent.com/86377881/167230915-644c3494-ccaa-4bbd-ab26-a5068a5f98e2.jpg)

## Project Closed. I am open to answering questions regarding the project but I no longer have the time to continue with the guide,
