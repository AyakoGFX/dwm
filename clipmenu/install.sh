#!/bin/bash

sudo make
sudo make clean install 
cd init/
mv clipmenud.service.in clipmenud.service
sudo cp clipmenud.service /etc/systemd/system/