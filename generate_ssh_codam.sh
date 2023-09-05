#!/bin/bash
cd ~/.ssh
yes | ssh-keygen -t rsa -b 2048 -C "YOUR@EMAIL" -f "PATH_TO/.ssh/id_rsa" -P ""
pbcopy < id_rsa.pub

