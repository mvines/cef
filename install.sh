#!/bin/bash -ex

if [[ $(uname) != Linux ]]; then
  echo Sorry, Linux only
  exit 1
else

source $(dirname $0)/setup

curl 'https://chromium.googlesource.com/chromium/src/+/master/build/install-build-deps.sh?format=TEXT' | base64 -d > install-build-deps.sh
chmod 755 install-build-deps.sh
sudo ./install-build-deps.sh
sudo apt-get install gtk+-3.0
sudo apt-get install x11proto-randr-dev

