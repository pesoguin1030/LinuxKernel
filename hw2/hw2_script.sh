#!/bin/bash
execute() {
    echo "kernel@ubuntu:~$ $1"
    eval $1
}
execute "sudo dmesg -C"
execute "sudo insmod process_list.ko"
execute "dmesg -T > proces_list_output.txt"
execute "sudo rmmod process_list"
execute "ps -ax -opid,uid,comm"
