#!/bin/bash

if [ -f /etc/os-release ]; then
  . /etc/os-release
  DISTRO=$ID
fi

main() {
  
  case $DISTRO in
    arch)
      echo "Install packages..."
      sudo pacman -Sy --needed base-devel sdl3 sdl3_image
      ;;
    debian|ubuntu)
      echo "Install packages..."
      sudo apt update && sudo apt install build-essential libsdl3-image-dev libsdl3-dev
      ;;
    *)
      echo "You Distro not support, Install SDL3 in you OS"
      ;;

    esac
    make

    python ./test.py
}

main
