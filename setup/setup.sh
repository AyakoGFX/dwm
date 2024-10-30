# #!/bin/bash

# Function to install packages with error handling
# install_packages() {
#     for package in "$@"; do
#         if ! pacman -Qi "$package" &> /dev/null; then
#             sudo pacman -S --needed --noconfirm "$package" || echo "Failed to install $package, skipping..."
#         else
#             echo "$package is already installed."
#         fi
#     done
# }

# # Install base development tools and dependencies
# echo "Installing base development tools and dependencies..."
# install_packages \
#     base-devel \
#     extra/git \
#     extra/libx11 \
#     extra/libxcb \
#     extra/libxinerama \
#     extra/libxft \
#     extra/imlib2 \
#     extra/xcb-util\
#     extra/xorg-xauth \
#     xorg-xinput \
#     extra/libxcb


# # Install desktop environment and utility applications
# echo "Installing desktop environment and utility applications..."
# install_packages \
#     picom \
#     sxhkd \
#     dmenu \
#     flameshot \
#     rofi \
#     acpi \
#     cbatticon \
#     nitrogen \
#     polkit-gnome \
#     google-chrome \
#     pcmanfm \
#     xfce4-taskmanager \
#     btop \
#     brightnessctl \
#     xclip \
#     slock \
#     trash-cli \
#     sxiv \
#     rofi-emoji \
#     network-manager-applet \
#     aspell \
#     copyq \
#     xclip \
#     gvfs \
#     xdotool \
#     xorg-xwininfo \
#     gvfs-mtp \
#     aspell-en
#     # pasystray  use yay -S volapplet-git


# # Install fonts
# echo "Installing fonts..."
# install_packages \
#     ttf-firacode-nerd \
#     ttf-jetbrains-mono-nerd \
#     noto-fonts \
#     emoji-font \
#     ttf-font \
#     ttf-ms-fonts \
#     ttf-liberation \
#     terminus-font

# yay -S ttf-defenestration
# yay -S ttf-ms-win11-auto

# applet 
# yay -S volapplet-git

sudo apt install nala 
sudo nala update && sudo nala upgrade

sudo nala install \
    fonts-terminus \
    build-essential \
    stow \
    libx11-dev \
    libx11-xcb-dev \
    libxcb-res0-dev \
    libxinerama-dev \
    libxft-dev \
    libimlib2-dev \
    policykit-1-gnome \
    rofi \
    picom \
    thunar \
    nitrogen \
    x11-xserver-utils \
    unzip \
    wget \
    copyq \
    pipewire \
    wireplumber \
    pavucontrol \
    zoxide \
    sxhkd \
    xdg-utils -y

cd ..
mkdir -p ~/Pictures/SS/
cp .Xresources ~/

# Copy .dwm directory to home
echo "Copying .dwm directory to home..."
cp -r .dwm ~/

# Set up rofi scripts
echo "Setting up rofi scripts..."
cd rofi-scripts
chmod +x *
sudo cp * /usr/bin/
cd ..
clear

# Install dmenu-distrotube
echo "Installing dmenu-distrotube..."
cd dmenu-distrotube
sudo make clean install
cd ..
clear

cd keybind-demon
./stow.sh
cd ..
clear

# Set up clipmenu
# echo "Setting up clipmenu..."
# cd clipmenu/
# sudo make
# sudo make clean install 
# cd init/
# mv clipmenud.service.in clipmenud.service
# sudo cp clipmenud.service /etc/systemd/system/
# cd ..
# clear

# Set up dwm sessions
echo "Setting up dwm sessions..."
mkdir -p /usr/share/xsessions/
sudo cp dwm.desktop /usr/share/xsessions/
clear

# Install dwmblocks
echo "Installing dwmblocks..."
cd dwmblocks
sudo make clean install
cd ..
clear

# Final installation step
echo "Performing final installation..."
sudo make clean install 
clear

