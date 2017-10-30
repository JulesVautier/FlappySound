FlappySound
===============

A Flappy Bird Clone made using [python-pygame][1] playable with your voice using arduino and sound sensor
It's a fork from an [existing project](https://github.com/sourabhv/FlappyBirdClone.git).
The code was great and well documented, really big thanks to the author [sourabhv](https://github.com/sourabhv).
I modified some element of the game to make it easier to play with voice.

How-to
------

1. Clone this repository.

Arduino setup
-----

2. Download [Arduino IDE](https://www.arduino.cc/en/Main/OldSoftwareReleases).

3. Setup your arduino like this 
![alt text](https://github.com/JulesVautier/SensorsClasses/blob/master/FinalProject/Presentation/montage_schema_bb.png)

 Hardware:
- arduino zero
- sound sensor
- 3 links
- use the analogic output to have more precises value with a big-sound sensor

4. With the Arduino IDE, open sound_reader/sound_reader.ino and upload the code on your arduino.

Python setup
-----
5. Install Python 2.7.X or 3.5.x from [here](https://www.python.org/download/releases/).

6. Go in the `FlappySound` folder and `pip install requirement.txt`.

7. Edit `flappy.py` and change the variable `Port` by the port used by your arduino.

8. Run `python flappy.py`.

9. use <kbd>&uarr;</kbd> or <kbd>Space</kbd> key to play and <kbd>Esc</kbd> to close the game.
I game: speak loudly or use your blow to make the bird fly.

Monitoring with GUI
----
10. Go in the `GUI` folder and `pip install requirement.txt`.

11. Run `python gui.py` while playing to see the values from the sound sensor.

Works on Windows


[1]: http://www.pygame.org
