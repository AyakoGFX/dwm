#!/usr/bin/env bash
function run {
    if ! pgrep $1 > /dev/null ;
    then
        $@&
    fi
}
run sxhkd &

# Restore wallpaper using Nitrogen
run nitrogen --restore &

# Start Picom for compositing
run picom &

# yay -S picom-ftlabs-git
# picom --animations -b &

run emacs --daemon &

#clipmenud &

# Set keyboard repeat rate
run xset r rate 250 60 &

# set screan to  1920x1080 --rate 144.00
# xrandr --output eDP --mode 1920x1080 --rate 144.00 &
# xrandr --output eDP --mode 1920x1080 --rate 60.02 &

# dwmblocks &

run nm-applet &

run copyq &

#blueman-applet &

#volapplet &

#cbatticon &

# /usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
/usr/lib/policykit-1-gnome/polkit-gnome-authentication-agent-1 &
/usr/lib/x86_64-linux-gnu/xfce4/notifyd/xfce4-notifyd &
setxkbmap -option caps:swapescape &

# mouse speed
# xinput --set-prop '19' 'libinput Accel Profile Enabled' 0 1 0
# xinput --set-prop '19' 'libinput Accel Speed' -0.1


# setwall 1 &
# for more info >> https://github.com/zeroruka/video-wallpaper-scripts.git
