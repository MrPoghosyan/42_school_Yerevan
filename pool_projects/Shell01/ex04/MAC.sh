#!/bin/sh
ifconfig | grep -o 'ether [0-9a-f:]*' | awk '{print $2}'
