#!/bin/bash

# Function to install packages with error handling
install_packages() {
    for package in "$@"; do
        if ! pacman -Qi "$package" &> /dev/null; then
            sudo pacman -S --needed --noconfirm "$package" || echo "Failed to install $package, skipping..."
        else
            echo "$package is already installed."
        fi
    done
}

# Install base development tools and dependencies
echo "Installing base development tools and dependencies..."
install_packages \
    base-devel \
    extra/git \
    extra/libx11 \
    extra/libxcb \
    extra/libxinerama \
    extra/libxft \
    extra/imlib2

# Install desktop environment and utility applications
echo "Installing desktop environment and utility applications..."
install_packages \
    picom \
    dmenu \
    flameshot \
    rofi \
    acpi \
    nitrogen \
    polkit-gnome \
    google-chrome \
    pcmanfm \
    xfce4-taskmanager \
    btop \
    brightnessctl \
    xclip \
    slock \
    trash-cli \
    sxiv \
    network-manager-applet

# Install fonts
echo "Installing fonts..."
install_packages \
    ttf-firacode-nerd \
    ttf-jetbrains-mono-nerd \
    noto-fonts \
    emoji-font \
    ttf-font \
    ttf-ms-fonts \
    ttf-liberation \
    terminus-font

# yay -S ttf-defenestration
# yay -S ttf-ms-win11-auto

# installing yay
# removed dep
# dmenu 

# sudo apt install build-essential git libx11-dev libx11-xcb-dev libxcb-res0-dev libxinerama-dev libxft-dev libimlib2-dev
# below pkg not tested
#sudo pacman -S --noconfirm picom flameshot rofi dmenu acpi nitrogen polkit-gnome google-chrome pcmanfm xfce4-taskmanager btop brightnessctl

mkdir -p ~/Pictures/SS/


# Copy .dwm directory to home
echo "Copying .dwm directory to home..."
cp -r .dwm ~/

# Set up rofi scripts
echo "Setting up rofi scripts..."
cd rofi-scripts
chmod +x *
sudo cp * /usr/bin/
cd ..

# Install dmenu-distrotube
echo "Installing dmenu-distrotube..."
cd dmenu-distrotube
sudo make clean install
cd ..

# Set up clipmenu
echo "Setting up clipmenu..."
cd clipmenu/
sudo cp clipmenud.service /etc/systemd/system/
sudo make clean install 
cd ..

# Set up dwm sessions
echo "Setting up dwm sessions..."
cd dwm-sessionsx
sudo cp dwm.desktop /usr/share/xsessions/
cd ..

# Install dwmblocks
echo "Installing dwmblocks..."
cd dwmblocks
sudo make clean install
cd ..

# Final installation step
echo "Performing final installation..."
sudo make clean install 

# Uncomment the following line to remove object files and backups
# rm *.o *.orig

