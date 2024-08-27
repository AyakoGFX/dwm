# after making changes in  my.wks file
#
# check with this cmd
# ./wk --key-chords my.wks
#
# if ecerythng working as expected convert wks file yo key_chords.def.h
wk --transpile my.wks > config/key_chords.def.h

rm config/key_chords.h
rm config/config.h

# Make wk for X11
make x11

# Make wk for wayland
# make wayland

sudo make install

#https://github.com/3L0C/wks-mode.git
# https://github.com/3L0C/wk.git
