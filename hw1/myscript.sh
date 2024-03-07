#!/bin/bash

# 模拟在终端中输入命令的效果
execute() {
    echo "root@ubuntu:/home/kernel/Assignment/hw1# $1"
    eval $1
}

# 显示系统信息
execute "uname -a"

# 加载hello模块
execute "insmod hello.ko"

# 加载hellop模块，带参数
execute "insmod hellop.ko howmany=2 whom=\"IIS\""

# 加载hellop3模块，带参数
execute "insmod hellop3.ko a=3 b=2 c=mytext"

# 列出所有含有"hello"的模块
execute "lsmod | grep hello"

# 移除hellop模块
execute "rmmod hellop"

# 移除hello模块
execute "rmmod hello"

# 移除hellop3模块
execute "rmmod hellop3"

# 再次列出所有含有"hello"的模块，确认它们已被移除
execute "lsmod | grep hello"

# 查看最后的内核消息
#execute "dmesg | tail"

# 清屏
#execute "clear"

