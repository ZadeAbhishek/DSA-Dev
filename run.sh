#!/bin/bash
sudo systemctl start docker
echo Docker started
echo opeining VsCode 
code -n
echo startng contianer
sudo docker run -it --rm -v `pwd`:/work dsa
echo Container Started