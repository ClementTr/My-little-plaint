#!/bin/bash

#Colors attribution
red=`tput setaf 1`
green=`tput setaf 2`
blue=`tput setaf 4`
reset=`tput sgr0`

echo "${red}Welcome on my Vagrant-VM${reset}"

# Install everything we will need in our VM (pip/virtualenv/etc.)
apt-get update
apt-get -y install g++
apt-get -y install qt5-default
apt-get -y install qttools5-dev-tools