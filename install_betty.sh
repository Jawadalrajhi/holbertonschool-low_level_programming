#!/bin/bash
# Install Betty linter in the sandbox

# Clone Betty repo if not already there
if [ ! -d "$HOME/Betty" ]; then
    git clone https://github.com/hs-hq/Betty.git ~/Betty
    cd ~/Betty
    sudo ./install.sh
    cd ~
    echo "Betty installation complete!"
else
    echo "Betty already installed."
fi
