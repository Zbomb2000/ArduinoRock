# Rock
This is a program for an Arduino project. It uses hcsr04 modules detect if there is an object in range. If there is, it plays sound from a car horn.
It is titled "Rock" becuase the hardware will probably be inside a fake rock to make it blend in and not be noticed.

## SCRIPTS
This lists all the scripts in this project

### rock.ino
This is the main script of the program.
(That's pretty much it)

### hcsr04.ino
This contains the functions related to the hcsr04 modules.
The functions are:
 - ```distanceCompare()```
	This function checks if an object is in range of the hcsr04 modules
 - ```printDistance()```
	This function prints the distance of an object from the hcsr04 modules. The distance is measured in millimeters

### sound.ino
This contains the functions related to playing sound.
The functions are:
 - ```playSound1()```, ```playSound2()```, and ```playSound3()```
	These functions play each sound from the soundboard.

## ADDITIONAL INFORMATION
 - Files in "/sound" are the sound files on the soundboard.
 - I will probably not upload wiring diagrams for this project any time soon, mainly because I don't know how to.
 - There are probably spelling errors in comments in the code.
