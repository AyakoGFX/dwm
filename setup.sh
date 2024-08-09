#!/bin/bash

sudo pacman -S --needed --noconfirm base-devel extra/git extra/libx11 extra/libxcb extra/libxinerama extra/libxft extra/imlib2
sudo pacman -S --noconfirm picom flameshot rofi dmenu acpi nitrogen polkit-gnome google-chrome pcmanfm xfce4-taskmanager btop brightnessctl

cp -r .dwm ~/

make

cd dwm-sessionsx
sudo cp dwm.desktop /usr/share/xsessions/
cd ..

cd dwmblocks
sudo make clean install
cd ..

sudo make clean install && rm *.o && rm *.orig



