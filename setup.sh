#!/bin/bash

sudo pacman -S --needed --noconfirm base-devel extra/git extra/libx11 extra/libxcb extra/libxinerama extra/libxft extra/imlib2
sudo pacman -S  --needed --noconfirm picom dmenu flameshot rofi acpi nitrogen polkit-gnome google-chrome pcmanfm xfce4-taskmanager btop brightnessctl xclip slock  trash-cli

#font
sudo pacman -S  --needed --noconfirm ttf-firacode-nerd ttf-jetbrains-mono-nerd noto-fonts emoji-font ttf-font ttf-ms-fonts ttf-liberation terminus-font

# yay -S ttf-defenestration
# yay -S ttf-ms-win11-auto

# installing yay
# removed dep
# dmenu 

# sudo apt install build-essential git libx11-dev libx11-xcb-dev libxcb-res0-dev libxinerama-dev libxft-dev libimlib2-dev
# below pkg not tested
#sudo pacman -S --noconfirm picom flameshot rofi dmenu acpi nitrogen polkit-gnome google-chrome pcmanfm xfce4-taskmanager btop brightnessctl


cp -r .dwm ~/

cd rofi-scripts
chmod +x *
sudo cp * /usr/bin/
cd ..

cd dmenu-distrotube
sudo make clean install
cd ..

cd clipmenu/
sudo cp clipmenud.service /etc/systemd/system/
sudo make clean install 
cd ..

cd dwm-sessionsx
sudo cp dwm.desktop /usr/share/xsessions/
cd ..

cd dwmblocks
sudo make clean install
cd ..

sudo make clean install 
#&& rm *.o && rm *.orig

