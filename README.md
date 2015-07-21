kayw's DWM fork
===============

Source
-----------
-Taken from [frank604](https://github.com/frank604/dwm), [KieranQuinn](https://github.com/KieranQuinn/dwm)
-Merge with dwm master except the drw impl(__WIP__)

Requirements
------------
* Xlib header files
* ohsnap font

Instructions
------------

    git clone https://github.com/kayw/dwm.git
    cd dwm && sudo make clean install
    
    
Patches
----------------
* statuscolors
* statusallmons
* centredfloating
* savefloats
* notitle
* pertag2
* systray
* occupiedcol
* uselessgaps
* keysymfix
* bstack
* runorraise
* Push
* Cycle

Difference with dwm master
---
* re-wrote drawbar
* selected tag underline (configurable via config.h)
* tag spacing & padding (configurable via config.h)
* bstack horizonal gaps
    
To do
-----
* monocle gaps?
* fix monocle to tile layout/resizing

![Screenshot](screenshot1.png "my dwm")
![Screenshot](screenshot2.png "my dwm")
![Screenshot](screenshot3.png "my dwm")
