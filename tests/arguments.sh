#!/usr/bin/env bash

. functions.sh

create_test "./client"
create_test "./client -h"
create_test "./client -p"
create_test "./client -p 4242 -h"
create_test "./client -p abcd"
create_test "./client -h a.b.c.d"
create_test "./client -h abcd"
create_test "./client -p abcd -h a.b.c.d"
create_test "./client -p abcd -h 127.0.0.1"
create_test "./client -p 4242 -h abcd"
create_test "./client -p 4242 -h 127.0.0.1"
