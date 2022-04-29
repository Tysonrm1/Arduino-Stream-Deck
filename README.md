# Arduino-Stream-Deck
This is the git repo where I will be posting the code, circuits and the instructions for the arduino stream deck as found on printables. Being a student working a part time job I will have limited time to continue to develop the instructions and code. While the stream deck is completed and has been sent to its final owner. I still plan to further the development of this project by streamlining the effort required to build it as well as adding functionality and compatibility for other microcontrollers. Suggestions for features and ways that I can improve the stream deck are appreciated and I am open to colaborating in the development of this project.    

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

# Instructions
## work in progress, check back later...


