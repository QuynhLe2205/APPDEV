## This is my readme file
Raspberry Pi acoustic sensor project

This project will turn a raspberry Pi 3 into an acoustic sensor.

1. Configuration 

1.1. Hardware configuration

A raspberry Pi 3 is recommended. If an older version of Pi is used,
corresponding configuration might be changed.
The Pi is mounted with a USB sound card, and plugged in a microphone.
It is recommended to have Ethernet connection for your Pi.

1.2. Software configuration

The USB sound card has to be set as default audio device. To do so, you need
to modify two files ("/etc/asound.conf" and ".asoundrc") with the same 
following contents:

pcm.!default {
	type plug
	slave {
		pcm "hw:1,0"
	}
}
ctl.!default {
	type hw
	card 1
}

If you are usings Raspbian Jessie, you have to roll back alsa-utils to an
earlier version (1.0.25). Instructions can be found here.

Step 1> Add these lines as the last lines of the file /etc/apt/sources.list
deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
# Uncomment line below then 'apt-get update' to enable 'apt-get source'
#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rib
deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rib

Step 2> Run "sudo apt-get update"
Step 3> Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of
alsa-util is available

Step 4> Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade
Step 5> Reboot (if necessary)
