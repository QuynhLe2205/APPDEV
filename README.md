### This is my readme file
GitHub link: https://github.com/QuynhLe2205/APPDEV

RASPBERRY PI ACOUSTIC SENSOR PROJECT

This project will turn a Raspberry Pi 3 into an acoustic sensor.

=====================
|  1. Configuration |
=====================
1.1. Hardware configuration

A raspberry Pi 3 is recommended. If an older version of Pi is used, corresponding configuration might be changed.
The Pi is mounted with a USB sound card, and plugged in a microphone.
It is recommended to have Ethernet connection for your Pi.

1.2. Software configuration

The USB sound card has to be set as default audio device. To do so, you need to modify two files ("/etc/asound.conf" and ".asoundrc") with the same 
following contents:
 _______________________________
| pcm.!default {                |
|	type plug               |
|	slave {                 |
|		pcm "hw:1,0"    |
|	}                       |
| }                             |
| ctl.!default {                |
|	type hw                 |
|	card 1                  |
| }                             |
|_______________________________|
If you are usings Raspbian Jessie, you have to roll back alsa-utils to an earlier version (1.0.25). Instructions can be found here.

Step 1> Add these lines as the last lines of the file /etc/apt/sources.list
 _____________________________________________________________________________________
| deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi   |
| # Uncomment line below then 'apt-get update' to enable 'apt-get source'             |
| #deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rib     |
| deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rib   |
|_____________________________________________________________________________________|
Step 2> Run "sudo apt-get update"
Step 3> Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-util is available
 _______________________________________________________________
| pi@raspberrypi:~$ sudo aptitude versions alsa-utils		|
| Package alsa-utils:						|
| i	1.0.25-4		oldstable		500     |
| p	1.0.28-1		stable			500	|
|_______________________________________________________________|
Step 4> Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade
Step 5> Reboot (if necessary)

===================
| 2. File list    |
===================
main.c		sound detection using  microphone sensor
screen.c	screen implementation functions
screen.h	screen header
comm.c		cursor implementation functions
comm.h		cursor header
wave.c		wave implementation functions
wave.h		wave header
makefile	makefile to analize wave data
README.md	this file
sound.php	tranfer data from raspberrypi through server to a text file 



