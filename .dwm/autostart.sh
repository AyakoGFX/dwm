#!/bin/bash

# Restore wallpaper using Nitrogen
nitrogen --restore &

# Start Picom for compositing
picom &

# emacs --daemon &
clipmenud &

# Set keyboard repeat rate
xset r rate 250 60 &

# set screan to  1920x1080 --rate 144.00
xrandr --output eDP --mode 1920x1080 --rate 144.00 &

dwmblocks &

nm-applet &

blueman-applet &

volapplet &

cbatticon &

/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &

setxkbmap -option caps:swapescape &
