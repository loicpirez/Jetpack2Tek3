#!/usr/bin/env bash

. functions.sh

create_test "env -i ./client -p 4242 -h 127.0.0.1"
create_test "env -u DISPLAY ./client -p 4242 -h 127.0.0.1"
create_test "DISPLAY=42 ./client -p 4242 -h 127.0.0.1"