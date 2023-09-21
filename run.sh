#!/bin/bash
echo opeining VsCode 
code -n
echo startng contianer
docker run -it --rm -v ${pwd}:/work dsa
echo Container Started