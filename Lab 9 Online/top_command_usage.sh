#!/usr/bin/env bash

top -b -n1>top_output.txt

tar -cvf 'lab 9 online.tar' 'top_output.txt'
