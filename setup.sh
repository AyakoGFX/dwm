#!/bin/bash

sudo pacman -S --needed --noconfirm base-devel extra/git extra/libx11 extra/libxcb extra/libxinerama extra/libxft extra/imlib2
sudo pacman -S --noconfirm picom flameshot rofi dmenu acpi nitrogen polkit-gnome google-chrome pcmanfm xfce4-taskmanager btop brightnessctl


# sudo apt install build-essential git libx11-dev libx11-xcb-dev libxcb-res0-dev libxinerama-dev libxft-dev libimlib2-dev
# below pkg not tested
#sudo pacman -S --noconfirm picom flameshot rofi dmenu acpi nitrogen polkit-gnome google-chrome pcmanfm xfce4-taskmanager btop brightnessctl


cp -r .dwm ~/

make

cd dwm-sessionsx
sudo cp dwm.desktop /usr/share/xsessions/
cd ..

cd dwmblocks
sudo make clean install
cd ..

sudo make clean install 
#&& rm *.o && rm *.orig

