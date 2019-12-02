# Video-Control-Surface
This is project of MIDI video control panel. The device is based on Arduino board. Author destination is to using device with vMix software to Audio-Video mixing.
Program supports digital inputs for toggle buttons and analog inputs for analog controllers like as potentiometer to control faders to volume or faders to picture transformation and transition.
Device uses standard USB port in Your computer to MIDI communication with switching software like as vMix.

## Prototype device
Protype device is in preparing process. Working system is ready on the contact plate at the moment.

### First version circuit diagram 
Download device's circuit diagram [here](https://github.com/janjedrzejak/Video-Control-Surface/blob/master/Switcher-sketch_bb.pdf)

### Elements used
* Arduino Nano CH340 ATmega 328
* 9 toggle buttons
* 9 resistors 1kΩ 
* 5 potentiometers 20kΩ
* ribbon wires
* contact plate

### Additional software used in project
I used The Hairless MIDI<->serial bridge software to send and receive MIDI signals. This is 100% free software. You can download it from 
[here](https://projectgus.github.io/hairless-midiserial/). Secound software is loopMIDI to create virtual MIDI port from Your USB port with Arduino in operating system. You can download it from [here](http://www.tobias-erichsen.de/software/loopmidi.html).

### Futures
The project is developmental. Furture functionalities is red and green LED's for active program and preview buttons in console.
