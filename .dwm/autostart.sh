#!/bin/bash

# Restore wallpaper using Nitrogen
nitrogen --restore &

# Start Picom for compositing
picom &

# yay -S picom-ftlabs-git
# picom --animations -b &

emacs --daemon &

clipmenud &

# Set keyboard repeat rate
xset r rate 250 60 &

# set screan to  1920x1080 --rate 144.00
# xrandr --output eDP --mode 1920x1080 --rate 144.00 &

dwmblocks &

nm-applet &

blueman-applet &

volapplet &

cbatticon &

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &

setxkbmap -option caps:swapescape &

# mouse speed
xinput --set-prop '19' 'libinput Accel Profile Enabled' 0 1 0
xinput --set-prop '19' 'libinput Accel Speed' -0.1


# setwall 1 &
# for more info >> https://github.com/zeroruka/video-wallpaper-scripts.git
