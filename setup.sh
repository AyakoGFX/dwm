#!/bin/bash

cp -r .dwm ~/

cd dwm-sessionsx
sudo cp dwm.desktop /usr/share/xsessions/
cd ..

cd dwmblocks
sudo make clean install
cd ..

sudo make clean install && rm *.o && rm *.orig
