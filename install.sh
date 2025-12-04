#!/bin/bash

#pre-requisite
sudo mkdir /usr/local/bin/grosh
sudo mkdir /usr/local/bin/grosh/lib

#grossfortune build
sudo /usr/bin/gcc ./src/grossfortune.c -o /usr/local/bin/grossfortune
sudo cp ./src/lib/fortunes /usr/local/bin/grosh/lib

#ewsay build
sudo /usr/bin/gcc ./src/ewsay.c -o /usr/local/bin/ewsay

#caramelldansen build
sudo /usr/bin/gcc ./src/caramelldansen.c -o /usr/local/bin/caramelldansen