//1.1 shell概述
/*
1、shell概述

    1.1 shell 的两层含义
    既是一种应用程序（软件，用于解决
用户与用户沟通问题），又是一种程序设计语言（编程语言）

        1.1.1 作为应用程序

          * 作为应用程序:
          * 交互式地解释、执行用户输入的命令，将用户的操作翻译成机器可以识别的语言（所以shell起到翻译的作用），完
          * 成相应功能

          * 因此，称之为 shell 命令解析器（用于解释一些命令的）

          * shell 是 用户 和 Linux内核 之间的接口程序

            用户在 提示符下 输入的命令 都由shell 先解释 然后传给 Linux 核心
            它调用了系统核心的大部分功能 来执行程序 、并以 并行的方式
协调各个程序的运行

         * 这句话说明，我们用户
最终是希望和硬件打交道的，但是我们不被允许直接操作硬件，而是交给Linux核心（即：Linux内核）来直接控制硬件。这个程序并不是仅运行一次，而是可能运行很多次，而且都是并行地执行的。


                Linux 系统中提供了好几种不同的shell
命令解释器，如sh、ash、bash等。一般 默认使用 bash
作为默认的解释器。我们后面编写的 shell 脚本， 都是由上述 shell 命令
            解释器解释执行的。

          * 例如：
                shell是用户 与 内核通信几种方式的一种：
                用户输入ls -l命令   然后由bash种类的shell来解释
再由shell来控制内核(kernel内核)     最后才能操作硬件 用户 用户使用文字或图形界面
操作 操作系统
                    ||
                使用者界面shell、KDE、application      接受来自用户的命令 与
内核进行沟通
                    ||
                   内核 真正控制硬件进行工作，进程管理，存储管理等
                    ||
                   硬件 cpu,内存，显卡，显示器，硬盘等。

            * shell本质是对内核起到保护作用，只有shell能够识别的命令才能够直接操作内核来控制硬件。

        1.1.2 shell作为一门语言
            作为程序设计语言:

          * 它定义了各种 变量 和
参数，并提供了许多在高级语言中才具有的控制结构，包括 循坏 和 分支
          * 完成类似于 windows 下批处理操作，简化我们对 系统的管理 与
应用程序的部署 称之为 shell 脚本
          * 我们学过的 c/c++等语言，属于编译性语言 (编写完成后需要 使用编译器
完成编译、汇编、链接等过程变为二进制代码方可执行)
          * shell
脚本是一种脚本语言，我们只需使用任意文本编相器，按照语法编写相应程序，增加可执行权限，即可在安装shell
命令解释器的环境下执行 (编译性语言 与
脚本语言的差异：脚本语言不需要gcc进行编译之类的操作，代码写完直接运行即可；编译性语言则需要
预处理、编译、汇编、链接等等，最终生成.exe可执行文件，才能直接去运行使用。反而麻烦了)

            shell 脚本主要用于:
            帮助开发人员或系统管理员将复杂而又反复的操作放在一个文件中，通过简单的一步执行操作完成相应任务，从而解放他们的负担。


            ** shell脚本是shell命令的有序集合**
（将shell命令与程序代码结合形成脚本  如：if(){ls} else{cd..}这种操作）

            shell 脚本大体可分为两类:
                1.系统进行调用
                这类脚本无需用户调用，系统会在合适的时候调用，如：/etc/profile、~/.bashrc等
（配置文件）

                /etc/profile
                    此文件为系统的每个用户设置环境信息,当用户第一次登录时,该文件被执行，系统的公共环境变量在这里设置.
                        开始自启动的程序，一般也在这里设置

                ~/.bashrc
                    用户自己的家目录中的.bashrc
                    登录时会自动调用，打开任意终端时也会自动调用
                    这个文件一般设置与个人用户有关的环境变量，如交叉编译器的路径等等
                (ls ~  进入家目录  ls -a查看若有文件
里面就有.bashr文件————家目录下的隐藏文件）

                2.用户编写，需要手动调用的
                例如我们上面编写的脚本都属于此类
                无论是系统调用的还是需要我们自己调用的，其语法规则都一样

    1.2 shell语法
        1.2.1 shell脚本的定义与执行

        1、定义以开头 ： #!/bin/bash
            #!用来声明脚本由什么shell解释，否则使用默认shell
        2、单个‘#’ 号代表注释当前行
        3、执行：
            (shell脚本可以直接执行，但需要考虑权限问题，一般情况下，我们在Ubuntu里面创建的文件是不具有可执行权限的，所以需要先修改文件的权限，让其拥有可执行权限，然后再像c语言可执行文件一样
直接执行即可)

            chmod +x test.sh       ./test.sh      增加可执行权限后执行
            bash test.sh                          直接指定使用bash解释test.sh
            . test.sh(source test.sh)             这种方法是
使用当前shell读取解释test.sh,前两种都会另开shell去执行脚本（所以它要看你当前的终端用的是哪一种shell解释器）

            * 三轴执行脚本的方式不同点：
                * ./和 bash 执行过程基本一致，但后者明确指定 bash
解释器去执行脚本，脚本中#!指定的解释器不再起作用，而前者首先检测
#!，使用#!指定的 shell，如果没有，则使用默认的 shell
                * 用./和 bash 去执行会在后台启动一个新的 shell 去执行脚本
                * 用.去执行脚本不会启动新的 shell,直接由当前的 shell
去解释执行脚本。

        注意:如果是在 windows 通过 notepad++ 编辑脚本程序
            需要用vi打开脚本，在最后 行模式下执行
            :set ff=unix

        1.2.2 变量
            1.2.2.1 自定义变量

            定义变量:（shell是没有数据类型这一概念的，因此，是
不需要加数据类型的 直接 ：变量名 = 变量值 即可） 变量名 = 变量值 如：num = 10

            引用变量：
                $变量名
                如：i = $num 把变量num的值 赋给 变量 i。

            显示变量：
                使用echo命令可以显示单个变量取值
                如：echo $num

            清除变量
                使用 unset 命令清除变量
                如：unset varname
            注意：清除之后再打印，显示的是空

            变量的其它用法
                read string         //类似于scanf，把
从终端输入的数据保存在变量当中 从键盘输入一个字符串 赋给 变量 string readonly
var=100 定义一个只读变量,只能在定义时初始化,以后不能改变,不能被清除。 export
var=300      //定义一个环境变量 使用 export
说明的变量，会被导出为环境变量，其它shell均可使用

                注意:此时必须使用 source 2_var.sh 才可以生效
                注意：在shell脚本中 命令是
一行一行执行的，哪一行执行失败是不会影响后面的代码的。

            注意事项：
                1. 变量名只能包含英文字母下划线，不能以数字开头
                2. 赋值时，“=”两边不能加空格，否则会报错：不能识别

            1.2.2.2 环境变量
            shell 在开始执行时就已经定义了一些和系统的工作环境有关的变量，我们在
shel 中可直接使用 $name 引用.
            (类似于c中的全局变量，任意打开一个文件都可以使用这些环境变量)

            定义:
            一般在 ~/.bashrc（家目录下的bashrc，是当前用户的配置文件）
或/etc/profile(根目录下的etc文件里的profile，是系统自带的配置文件)
文件中(系统会自动调用的脚本)（这两个脚本文件在系统重启之后，系统会自动调用）使用
export 设置，允许用户后来更改 VARNAME=value; export VARNAME

            传统上，所有环境变量均为大写

            * 显示环境变量
                使用 env 命令可以查看所有的环境变量
            * 清除环境变量
                使用 unset 命令 清除环境变量
            * 常见环境变量
                HOME：用于保存 注册目录的 完全路径名
                PATH：用于保存
用冒号分隔的目录路径名,shell将按PATH变量给出的顺序搜索这些目录，找到的第一个与命令名称一致的可执行文件将被执行。
                    PATH=$HOME/bin:/bin:/usr/bin;   export PATH
                HOSTNAME：主机名
                SHELL：默认的shell命令解释器
                LOGNAME：此变量保存登录名
                PWD：当前工作目录的绝对路径
                ...

            定义一个环境变量：
                1.终端定义一个临时环境变量
                例：（操作流程）
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_shell$ MYVAL=999
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_shell$ export MYVAL
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_shell$ env
                    ...
                    MYVAL=999
                    ...
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_shell$ echo $MYVAL
                    999

            注意：通过 终端 定义的 环境变量，只是临时的环境变量，当终端关闭时 或 操作系统重启 或 重新再开启一个终端，该环境变量便被释放。
                 如果想要定义一个永久的 环境变量，则需要在~/.bashrc 或 /etc/profile文件中定义

            2. 在~/.bashrc 或 /etc/profile文件中定义永久环境变量

            例：(操作流程)
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_shell$ vi ~/.bashrc
                a
                MYVAL1=666
                export MYVAL1
                Esc
                shift + :
                wq
                source ~/.bashrc
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_shell$ env

            注意：当配置文件被修改，并不会马上生效，而是当系统重启或再开一个终端才会生效，若就想要在当前终端生效，则终端输入： source ~/.bashrc
                 使用环境变量：一般环境变量类似于c语言的全局变量，可以在shell脚本文件中任意使用：
                 例：
                        #!/bin/bash

                        echo "You are welcome to use bash"
                        echo "Current work dirctory is $PWD"
                        echo "the host name is $HOSTNAME"
                        echo "your home dir $HOME"
                        echo "Your shell is $SHELL"
                        echo "Myval is $MYVAL and $MYVAL1"



//    12.13.2 vi的使用
//        使用 vi 打开文件
//            vi filename:
//                打开或创建文件，并将光标置于第 1 行行首
//                vi test.txt

//            vi +n filename:
//                打开存在文件，并将光标置于第 n 行行首
//                vi +8 test.txt

//        vi的使用：
//            vi 文件名  在 vi编辑器中打开或者创建一个文件，并将光标置于行首。
//        12.13.3 vi的3种模式
//            1.插入模式(敲代码)
//                这种模式可以直接编辑文档....

//                注意： vi创建一个不存在文件时（.c 文件可以，txt文件不可以），默认进入插入模式

//            2、编辑模式（写命令）
//                在编辑模式下可以敲一些命令，执行例如：复制n行、剪切n行、粘贴等功能
//                注意:vi在打开一个已经存在的文件的时候，默认进入的是编辑模式

//            3、命令模式(最后一行模式)
//                在此模式下可以保存文件，退出 vi 等功能
//        4、三种模式之间的切换:
//            1)由 编辑模式 进插入模式 按a i o 这几个字母
//              区别是 插入的位置不一样:
//                    a：起始位置为下一个位置
//                    i：起始位置为当前位置
//                    o：起始位置为新换行的位置
//            2)由插入模式进编辑模式
//              按 ESC 键

//            3)只能由编辑模式才能进最后一行模式
//              在编辑模式下按 shift: 进入 最后一行模式

//              在最后一行的模式下的命令：
//                :w  ：保存文件
//                :wq ：保存文件并退出vi
//                :x  ：保存文件并退出vi
//                :q! ：不保存文件，强制退出vi
//                :w filename：另存为 filename
//            4)由命令模式（最后一行模式）也可以进编辑模式
//                按 ESC
//            总结：
//                a)由 插入模式 或者 命令模式(最后一行模式)  进 编辑模式，方法是按 ESC 键
//                b)由 编辑模式 进 命令模式(最后一行模式) 按 shift + :
//                c)由 编辑模式 进 插入模式 按 a i o
//                d)插入模式 和 命令模式(最后一行模式) 不能直接切换


            1.2.2.3 预设变量
                $#：传给 shell 脚本参效的数量。
                $*：传给 shell 脚本参数的内容
                $1、$2、$3、…、$9：运行脚本时传递给其的参数，用空格隔开
                $?：命令执行后返回的状态
                "$?"：用于检查上一个命令执行是否正确(在 Unux中，命令退出状态为0表示该命令正确执行，任何非0值表示命令出错)。
                $0：当前执行的进程名
                $$：当前进程的进程号.
                "$$"：变量最常见的用途是用作临时文件的名字 以保证临时文件不会重复
                例：
                    #! /bin/bash

                    #位置变量$0 - $9 保存从终端输入的每一个参数
                    echo "\$0 = $0"
                    echo "\$1 = $1"
                    echo "\$2 = $2"
                    echo "\$5 = $5"
                    echo "\$6 = $6"
                    echo "\$7 = $7"
                    echo "\$8 = $8"
                    echo "\$9 = $9"
                    echo “\$10 = ${10}”
                    #当需要保存的数大于10个，需要加{}使其成为整体否则输出的是$1 + 0

                    # $#:保存命令行传入的参数的个数，不包含$0
                    echo "\$# = $#"

                    # $@ 或$*: 保存所有的命令行传入的参数，但是不包括$0
                    echo "\$@ = $@"
                    echo "\$* = $*"

                    # $$:获取当前进程的进程号
                    echo "\$$ = $$"

                    #要获取进程号时，需要加这句话，使程序不会运行完成后退出，而是卡在这儿
                    # read NUM

                    ls

                    # 返回上一条命令的执行结果，如果执行成功返回0，执行失败返回非零
                    echo "\$? = $?"

            1.2.2.4 脚本变量的特殊用法： "" '' \ () {}
                ""(双引号) ：包含的变量会被解释
                ''(单引号) ：包含的变量会被当作字符串解释
                ``(反引号) ：反引号中的内容作为系统命令，并执行其内容，可以替换输出为一个变量。 其作用与$()相同。
                    $ echo "today is `date`"
                    today is 2012年07月29日星期日 12：55：21CST
                \ 转义字符：同c \n \t \r \a等echo命令需加-e转义
                （命令序列）：由子shell来完成，不影响当前shell中的变量。
                {命令序列} ：在当前shell中执行，会影响当前变量
                例:
                    #!/bin/bash

                    name="wangcheng"
                    #双引号里面的特殊字符会被解释
                    string1="good morning $name"
                    #单引号里面的特殊字符不会被解释
                    string2='good morning $name'

                    echo $string1
                    echo $string2

                    # ``反引号 的内容为 系统命令
                    echo "today is`date`"
                    echo 'today is`date`'
                    echo "My dir is $(ls)"  # $() 与 ``作用相同


                    echo "***********************"
                    # 转义字符 在同 echo连用时要加-e
                    echo -e "this \n is\ta\ntest"
                    echo "***********************"

                    num=100
                    # （）的内容 由 子shell 来完成，不影响当前shell中的变量
                    ( num=999;echo "1 $num")
                    echo 1:$num
                    # {} 的内容 在当前shell中执行，会影响当前变量
                    { num=666; echo "2 $num"; }     #注意：这里 （）和 {} 里面左右需要加空格
                    echo 2:$num

        1.2.3 条件测试语句
            在写 shell 脚本时，经常遇到的问题就是判断字符用是否相等，可能还要检查文件状态
            或进行数字测试，只有这些测试完成才能做下一步动作。
            test命令:用于测试字符串、文件状态和数字

            test 命令有两种格式:
                test condition 或[ condition ]
                使用方括号时，要注意在条件两边加上空格。

            shell 脚本中的条件测试如下:

                文件测试、字符串测试、数字测试、复合测试

                测试语句一般与后面讲的条件语句联合使用

            1.2.3.1 文件测试（判断文件类型，文件是否有内容，查看文件的权限）
                文件测试：测试文件状态的条件表达式
                1、按文件类型
                    -e  文件名     文件是否存在
                    -s  文件名     文件是否非空

                    -b  文件名     块设备文件
                    -c  文件名     字符设备文件
                    -d  文件名     目录文件
                    -f  文件名     普通文件

                    -L  文件名     软链接文件
                    -S  文件名     套接字文件   注意这两个都是大写的

                    -p  文件名     管道文件

                在Linux里面 一共有7种文件类型：bcd-lsp  通过ls -l命令来查看
                    b:块设备文件
                    c:字符设备文件
                    d:目录文件
                    -：普通文件
                    l:软链接文件
                    s:套接字文件
                    p:管道文件

                2、按照文件权限
                    -r 文件名      可读
                    -w 文件名      可写
                    -x 文件名      可执行

                3、两个文件之间的比较
                    文件1 -nt 文件2     文件1的修改时间是否比文件2新
                    文件1 -ot 文件2     文件1的修改时间是否比文件2旧
                    文件1 -ef 文件2     两个文件的inode节点号是否一样，用于判断是否是 硬链接

                复习：
                    touch file.txt    创建一个普通文件
                    mkdir   dir       创建一个根目录文件

                对于创建的根目录文件，当输入：
                    ls -l dir/
                会显示:
                    总用量 0

                例：
                    #! /bin/bash

                    echo "please input a filename >>>"
                    read FILE

                    test -e $FILE      #查看文件是否存在
                    echo "存在？ $?"    # #? 命令执行后返回的状态

                    test -s $FILE      #查看文件是否存在
                    echo "存在？ $?"

                    #条件测试语句 test condition 或 [ condition ]
                    [ -r $FILE ]        # 可读？
                    echo "可读？ $?"

                    [ -w $FILE ]        # 可写？
                    echo "可写？ $?"

                    [ -x $FILE ]        # 可执行？
                    echo "可执行？ $?"

                    test -b $FILE
                    echo "块设备文件？ $?"

                    test -c $FILE
                    echo "字符设备文件？ $?"

                    test -d $FILE
                    echo "目录文件？ $?"

                    test -f $FILE
                    echo "普通文件？ $?"

                    test -L $FILE
                    echo "软链接文件？ $?"

                    test -S $FILE
                    echo "套接字文件？ $?"

                    test -p $FILE
                    echo "管道文件？ $?"

            1.2.3.2 字符串的测试
                字符串测试
                    s1 = s2         测试两个字符串是否完全一致（内容和长度）
                    s1 != s2        测试两个字符串的内容是否有差异
                    -z s1           测试s1字符串的长度是否为0
                    -n s1           测试s1字符串的长度是否不为0
            例：
                #! /bin/bash

                test "hello" = "hello"
                echo "相等？ $?"    #0

                test "hello" = "hella"
                echo "相等？ $?"    #1

                test "hello" != "hello"
                echo "不相等？ $?"  #1

                test "hello" != "hella"
                echo "不相等？ $?"  #0

                test -z "hello"     #s1字符串的长度是否为0
                echo "长度是否为0? $?"      #1

                test -n "hello"     #s1字符串的长度是否为0
                echo "长度是否不为0? $?"    #0

            1.2.3.2 数字测试
                a -eq b         测试a与b是否相等      equal
                a -ne b         测试a与b是否不相等     not equal
                a -gt b         测试a是否大于b        greater than
                a -ge b         测试a是否大于等于b     greater equal
                a -lt b         测试a是否小于b        less than
                a -le b         测试a是否小于等于b     less equal

                例：
                    #! /bin/bash

                    echo "please input two numbers >>>"
                    read NUM1 NUM2

                    test $NUM1 -eq $NUM2
                    echo "相等? $?"

                    test $NUM1 -ne $NUM2
                    echo "不相等? $?"

                    test $NUM1 -gt $NUM2
                    echo "大于? $?"

                    test $NUM1 -ge $NUM2
                    echo "大于等于? $?"

                    test $NUM1 -lt $NUM2
                    echo "小于? $?"

                    test $NUM1 -le $NUM2
                    echo "小于等于? $?"

            1.2.3.3 复合测试
                1.命令执行控制
                &&：
                    command && command2
                    &&左边命令 （command1）执行成功（即返回0）shell才执行&&右边的命令（command2）

                ||:
                    command || command2
                    ||左边命令 （command1）未执行成功（即返回非0）shell才执行||右边的命令（command2）

                例：
                    test -e /home && test -d /home && echo "true"
                    test 2 -lt 3 && test 5 -gt 3 && echo "equal".
                    test "aaa" = "aaa" || echo "not equal" && echo "equal".

                2.多重条件判定（shell中独有的）
                多重条件判定 区分于 上面的两个（&& 和 ||）： &&和|| 的 左右两个必须是完整的条件。而多重条件不需要再加test了，直接跟两个条件即可。

                    -a          (and)两状况同时成立!
                                test -r file -a -x file
                                file同时具有r和x权限时，才为true

                    -o          (or)两状况任何一个成立！
                                test -r file -o -x file
                                file具有r 或 x权限时，就传回true

                                相反状态
                     !          test ! -x file
                                当file不具有x时，传回true

                例：
                        #! /bin/bash

                        num=100
                        #判断 0<=num<=200

                        # 命令执行控制:&&
                        test $num -ge 0 && test $num -le 200
                        echo "$?"
                        #多重条件判断:-a
                        test $num -ge 0 -a $num -le 200
                        echo "$?"

                        #判断 num<= 0 或者 num >= 200
                        # 命令执行控制:||
                        test $num -le 0 || test $num -ge 200
                        echo "$?"
                        #多重条件判断:-o
                        test $num -le 0 -o $num -ge 200
                        echo "$?"

                        file="file.txt"

                        #判断文件是否不是普通文件
                        test ! -f $file
                        echo "$?"   #1
                        #判断文件是否 存在 并 是否 是目录文件
                        test -e $file && test -d $file
                        echo "$?"   #1
                        test -e $file -a -d $file
                        echo "$?"   #1


        1.2.4 控制语句
            if case for while until break.

            1.2.4.1 if控制语句
                格式一:
                    if[ 条件1 ]; then //这里then如果换行写，则可以省略分号
                        执行第一段程序
                    else.
                        执行第二段程序
                    fi      //这里fi是作为一个if语句结束的标识。

                格式二:
                    if[ 条件1 ]; then
                        执行第一段程序
                    elif[ 条件2 ]; then
                        执行第二段程序
                    else
                        执行第三段程序
                    fi

              例：
                        #! /bin/bash

                        echo "please input a number >>>"
                        read NUM
                        # 注意:赋值时。等号两边不能加空格
                        # []里面存放表达式时 必须加空格
                        #一般形式
                        if [ $NUM -gt 50 ]      # 注意: if和 [] 之间要加空格
                        then
                            echo "NUM > 50"
                        fi

                        if [ $NUM -gt 50 ]
                        then
                            echo "NUM > 50"
                        else
                            echo "NUM <= 50"
                        fi

                        echo "**************************"

                        #阶梯形式
                        if [ $NUM -gt 50 ]
                        then
                            echo "NUM > 50"
                        elif [ $NUM -lt 50 ]
                        then
                            echo "NUM < 50"
                        else
                            echo "NUM = 50"
                        fi

                        echo "**************************"

                        #嵌套模式
                        if [ $NUM -gt 50 ]
                        then
                            echo "NUM > 50"
                        elif [ $NUM -eq 50 ]
                        then
                            echo "NUM = 50"
                        else
                            echo "NUM < 50"
                            if [ $NUM -gt 30 ]
                            then
                                echo "NUM > 30"
                            else
                                echo "NUM <= 30"
                            fi
                        fi

            1.2.4.2 case语句
                    case $变量名称 in
                        “第一个变量内容”)
                            程序段一
                            ;;      //用两个;代替了break
                        “第二个变量内容”)
                            程序段二
                            ;;
                        *)          //用*)代替了default
                            其它程序段。
                            exit 1 .
                    esac

                    注意：命令行中输入时。应为： ./文件名 one  再回车。这里才会把one的值赋值给$1

                例：当语句1与语句2不相同：
                            #! /bin/bash

                            echo "This script will print your choice"

                            case "$1" in
                                "one" )
                                    echo "your choice is one"
                                    ;;
                                "two" )
                                    echo "your choice is two"
                                    ;;
                                "three" )
                                    echo "your choice is three"
                                    ;;
                                *)
                                    echo "Error Please try again!"
                                    exit 1
                                    ;;
                            esac

                            echo "hello world"


                例：当语句1与语句2相同：
                            #! /bin/bash

                            echo "Please input your choice"
                            read choice

                            case "$choice" in
                                Y | yes |Yes | YES)
                                    echo "It is true!"
                                    ;;
                                N* | n* )   # * 可以匹配任意 数量的 任意 字符，只要是N或 n开头的都可以
                                    echo "It is wrong!"
                                    ;;
                                * )
                                    exit 1
                            esac


            1.2.4.3 for控制语句

            形式1：
                for((初始值;限制值;执行步阶))
                do
                    程序段
                done

                初始值:变量在循环中的起始值。

                限制值:当变量值在这个限制范围内时，就继续进行循环。

                执行步阶:每作一次循环时，变量的变化量。

                declare 是 bash 的一个内建命令。可以用来 声明 shell 变量、设置变量的属性。
                declare 也可以写作 typeset。.

               * dcclare -i s 代表 强制把 s 变量 当傚 int 型参数运算。

               例1：
                        #! /bin/bash

                        #声明变量sum是整数型变量 只能保存整数
                        declare -i sum

                        for ((i = 1;i<100;i++))
                        do
                            sum=sum+i
                        done

                        echo "The result is $sum"

                例2：
                        #! /bin/bash

                        #注意for循环后的变量之前不能加 $ 符
                        for i in 1 2 3 4 5 6 7 8 9
                        do
                            echo $i
                        done

           * 形式二：
                for var in conl con2 con3...        //var是变量名
                do
                    程序段
                done

                第一次循环时，$var 的内容为 con1.
                第二次循环时，$var 的内容为 con2.
                第三次循环时。$var 的内容为 con3.
                ...

            创建根目录文件 mkdir
            创建管道文件  mkfifo

            注意：
                当in后面所有的值都赋值完毕并执行命令后，循环才结束

            例：
                #! /bin/bash
                # `ls`` : 输出当前文件的文件名 执行ls命令，并把结果放到in后面
                for name in `ls`
                do
                    # #先来看看运行的是什么结果:输出 当前的文件名
                    # echo $name
                    # echo "###############"

                    if [ -f $name ];then    #判断当前文件是否为普通文件
                        echo "$name is file"
                        echo "####################"
                    elif [ -d $name ];then  #若不是普通文件，再判断当前文件是否为目录文件
                        echo "$name is directory"
                        echo "####################"
                    else
                        echo "^_^"
                        echo "####################"
                    fi
                done

            1.2.4.4 while 控制语句
                    while [ condition ]     //while后面跟一个条件测试语句
                    do
                        程序段
                    done

                    当 condition 成立的时候进入 while 循环，直到 condition 不成立时才退出循环

                例:12_while.sh
                            #! /bin/bash

                            declare -i i
                            declare -i s

                            while [ "$i" != "101" ]
                            do
                                s+=i;
                                i=i+1;
                            done

                            echo "The count is $s"


            1.2.4.5 until 控制语句

            until [ condition ]
            do
                程序段·
            done

            这种方式与 while 恰恰相反。当 condition 成立的时候退出循坏，否则继续循环

            例:13_until.sh
                #! /bin/bash

                declare -i i
                declare -i s

                until [ "$i" = "101" ]
                do
                    s+=i;
                    i=i+1;
                done

                echo "The count is $s"

            1.2.4.6 break、continue 控制语句
            break：
                break 命令允许跳出循环。
                break 通常在进行一些处理后退出循环或 case 语句
            continue：
                conlinue 命令类似于 break命令
                只有一点重要差别，它不会跳出循坏，只是跳过这个循环步骤，

            例：
                    #! /bin/bash

                    for ((num=1;num<=10;num++))
                    do
                        if [ $num -eq 8 ]
                        then
                            break
                        elif [ $num -eq 5 ]
                        then
                            continue
                        fi
                        echo "num = $num"
                    done

        1.2.5 函数
                有些脚本段间互相重复，如果能只写一次代码块而在任何地方都能引1用那就提高
            了代码的可重用性。
                shell 允许将一组命令集或语句形成一个可用块，这些块称为 shell函数。

            定义函数的两种格式:
            格式一:
                函数名 () {
                    命令...
                }
            格式二:
                function 函数名() {
                    命令...
                }

            函数可以放在 同一个文件中 作为一段代码，也可以放在 只包含函数的 单独文件中。

            所有函数在使用前必须定义，必须将函数放在脚本开始部分，直至shel解释器首次发
            现它时，才可以使用


            调用函数的格式为:
                无参调用：
                    函数名
                有参调用：
                    函数名 param1 param2...

      * 注意：
            函数的传参 并不像 c那样，在括号内传，而是通过外部传参之后，内部使用，通过 像$1，$2...这样的预设的变量 来接收其值
        即：
            使用参数同在一般脚本中使用特殊变量
                $1,$2...$9一样

            函数可以使用 return 提前结束并带回返回值
                return 从函数中返回，用最后状态命令决定返回值

                return 0 无错误返回

                return 1 有错误返回
        例：
                #! /bin/bash

                myadd()
                {
                    A=$1
                    B=$2

                    SUM=`expr $A + $B`

                    return $SUM
                }

                # 用最后 状态命令 决定返回值    $?
                myadd 100 200
                # 函数的返回值 一般通过 $? 可以获取到，但是，$? 获取的最大值为255，若超过该值会出错。
                # echo "num = $?"


                # 若希望 输出大于255的值，可以直接把 sum 拿来用
                # 因为，在同一个shell中，除了（）里定义的变量
                # 只要没修饰，无论哪里定义的变量，都可以在任意一个位置调用。
                echo "SUM = $SUM"

*/

//第二章：系统调用
/*
    本章类似于c的文件操作，学的库函数open fwrite fread(标准IO)
    2.1系统编程概述（系统调用）

      * 操作系统的职责:
            操作系统 用来 管理所有的资源，并 将不同的设备 和 不同的程序 关联起来。

      * 什么是 Linux 系统编程:
            （对硬件进行操作：二进制、汇编 （这两种移植性不强，）、Linux操作系统编程（对于不同的开发板，若有同一个操作系统，可操作流程就是相同的））
            在有操作系统的环境下编程，并使用操作系统提供的系统调用及各种库，对系统资源进行访问。

            学会了c，再了解一些使用系统调用的方法，就可以进行Linux系统编程了。（对内存，键盘，显示器，打印机等硬件进行操作）

    总结：
      * 系统编程主要就是为了让用户能够更好更方便地操作硬件设备，并且对硬件设备也起到保护作用。 我们所写的程序，本质就是对硬件设备的操作，所以操作系统提供接口，可以对硬件进行操作。

    2.2 系统调用概述（系统调用）
        类UNIX系统的软件层次
        见 图1
        本质都是要对硬件设备进行操作，但是linux操作系统在硬件之上设置了内核，也就是只有内核才能直接操作硬件设备，如果想操作内核，需要调用内核的系统调用，如果要操作内核中的系统调用，
        有3种方式：
            1. shell ,用户通过shell命令,由shell解释器操作内核的系统调用
            2. 库函数，用户通过应用层库函数的接口，如fread对内核的系统调用进行操作
            3. 应用层系统调用，他可以通过应用层的一些接口，直接对内核的系统调用进行操作


      * 系统调用是操作系统操供给用户程序的一组“特殊”函数接口。
        Linux的不同版本提供了两三百个系统调用。
        用户程序可以通过这组接口获得操作系统(内核)提供的服务。。
        例如:.
            用户可以通过文件系统相关的系统调用，请求系统打开文件、关闭文件或读写文件。

      * 系统调用按照 功能逻辑 大致可分为:
            进程控制、进程间通信、文件系统控制、系统控制、内存管理、网络管理、socket控制（套接字控制）、用户管理。

        见 图2

      * 系统调用的返回值:
            通常，用一个负的返回值来表明错误，返回一个0值表明成功。错误信息存放在全局变量 errno 中，用户可用 perror 函数打印出错信息。

      * 系统调用遵循的规范
            在 Linux 中，应用程序编程接口(API)道循 POSIX标准
            POSIX 标准基于当时现有的 UNIX 实践和经验，描述了操作系统的系统调用编程接口(实际上就是 API)，用于保证应用程序可以在源代码 级上在多种操作系统上移植运行。
        如：
            linux下写的open、write、read可以直接移植到unix操作系统下。

    2.3 系统调用I/O函数
        (库函数/标准IO 针对于文件指针，即：FILE*的结构体指针变量，而在系统调用中都是针对文件描述符的。)

      * 系统调用中操作 I/O 的函数，都是针对文件描述符的
        通过文件描述符可以直接对相应的文件进行操作。
            如:open、close、write、read、ioctl

        2.3.1 文件描述符

        文件描述符 是非负整数。打开现存文件或新建文件时，系统(内核)会返回一个文件描述符。文件描述符用来指定已打开的文件。

    总结：
        在系统调用（文件IO）中，文件描述对文件起到标识作用。若要操作文件，实质就是对文件描述符的操作。

        当一个程序运行或一个进程开启时，系统会自动创建三个文件描述符：（类似于标准IO中，系统自动创建三个文件指针）

        0   //标准输入的文件描述符
        1   //标准输出的文件描述符
        2   //标准错误的文件描述符

    即 三个宏定义：
        #define        STDIN_FILENO     0   //标准输入的文件描述符
        #define        STDOUT_FILENO    1   //标准输出的文件描述符
        #define        STDERR_FILENO    2   //标准错误的文件描述符
        程序运行起来后这三个文件描述符是默认打开的。

    文件IO的文件描述符 与 标准IO的文件指针 的对应关系：
        文件IO            标准IO
        0               stdin
        1               stdout
        2               stderr

    若自己打开文件，会返回文件描述符，而文件描述符一般按照从小到大依次创建的顺序。
        2.3.2 open 函数

            打开一个文件
            #include <sys/types.h>
            #include <sys/stat.h>
            #inelude <fcntl.h>
            当文件存在时使用:
                int open(const char *pathname, int flags);
            当文件不存在时使用:
                int open(const char "pathname, int flags, mode_t mode);
            参数:
                pathname:文件的路径及文件名，
                flags   :open函数的行为标志。
                mode    :文件权限(可读、可写、可执行)的设置
            返回值：
                成功 返回 打开的文件描述符
                失败 返回 -1，可以利用perror去查看原因

                            flags 的取值及其含义
                取值              含义
                O_RDONLY        以只读的方式打开
                O WRONLY        以只写的方式打开
                O_RDIR          以可读、可写的方式打开

                            flags除了取上述值外，还可与下列值位或
                O_CREAT         文件不存在，则创建文件，使用此选项时需使用 mode说明文件的权限
                O_EXCL          如果同时指定了O_CREAT，且文件已经存在，则出错
                O_TRUNC         如果文件存在，则清空文件内容
                O_APPEND        写文件时，数据添加到文件末尾
                O NONBLOCK      当打开的文件是FIFO、字符文件、块文件时，此选项为 非阻塞标志位

                                mode的取值及其含义
                取值                八进制数              含义
                S_IRWXU             00700               文件所有者的读、写、可执行权限
                S_IRUSR             00400               文件所有者的读权限
                S_IWUSR             00200               文件所有者的写权限
                S_IXUSR             00100               文件所有者的可执行权限
                S_IRWXG             00070               文件所有者同组用户的读、写、可执行权限
                S_IRGRR             00040               文件所有者同组用户的读权限
                S_IWGRP             00020               文件所有者同组用户的写权限
                S_IXGRP             00010               文件所有者同组用户的可执行权限
                S_IRWXO             00007               其他组用户的读、写、可执行权限
                S_IROTH             00004               其他组用户的读权限
                S_IWOTH             00002               其他组用户的写权限
                S_IXOTH             00001               其他组用户的可执行权限

                对于使用8进制时需注意：
                    以 0664 例    0664代表其为8进制 化为2进制为： 110 110 100   ：110(文件所有者可读可写权限) 110（同组用户可读可写权限） 100（其他组可读权限）

//        插:
//            man man ：查询man手册的使用方法（man手册默认查询shell命令。）
//
//                下表显示了手册的 章节 号及其包含的手册页类型。（一般查询前三章：man 1 man）
//
//                       1   可执行程序或 shell 命令
//                       2   系统调用(内核提供的函数)
//                       3   库调用(程序库中的函数)
//                       4   特殊文件(通常位于 /dev)
//                       5   File formats and conventions, e.g. /etc/passwd
//                       6   游戏
//                       7   杂项(包括宏包和规范，如 man(7)，groff(7))
//                       8   系统管理命令(通常只针对 root 用户)
//                       9   内核例程 [非标准
//
//            man 2 open:使用man指令查询系统调用下的open函数
//            NAME
//                   open, openat, creat - open and possibly create a file
//
//            SYNOPSIS
//                   #include <sys/types.h>
//                   #include <sys/stat.h>
//                   #include <fcntl.h>
//
//            由此可知：open函数有两种结构：文件存在时使用 和 文件不存在时使用
//                   int open(const char *pathname, int flags);
//                   int open(const char *pathname, int flags, mode_t mode);
//
//                   int creat(const char *pathname, mode_t mode);
//
//                   int openat(int dirfd, const char *pathname, int flags);
//                   int openat(int dirfd, const char *pathname, int flags, mode_t mode)


                2.3.2.1 文件IO 和 标准IO权限对比：

                标准IO            文件IO                        权限含义
                r               O_RDONLY                    以只读方式打开文件，如果文件不存在则报错
                r+              O_RDWR                      以读写的方式打开文件,如果文件不存在则报错
                w       O_WRONLY | O_CREAT | O_TRUNC ,0664  以只写方式打开文件，如果文件不存在则创建，如果文件存在则清空
                w+        O_RDWR | O_CREAT | O_TRUNC ,0664  以读写方式打开文件，如果文件不存在则创建，如果文件存在则清空
                a       O_WRONLY | O_CREAT | O_APPEND,0664  以只写方式打开文件，如果文件不存在则创建，如果文件存在则追加
                a+        O_RDWR | O_CREAT | O_APPEND,0664  以读写方式打开文件，如果文件不存在则创建，如果文件存在则追加


                2.3.2.2 函数调用出错后输出出错信息
                    1.通过全局变量 errno
                        需要头文件：#include <errno.h>
                        errno 是一个全局变量，当函数调用失败后，可以通过errno获取错误码。

                    2.通过一个函数 perror
                        需要头文件：#include <stdio.h>
                        void perror(const char *s);

                        功能：输出函数调用失败的错误信息
                        参数：
                            s：打印错误信息的提示消息
                        返回值：
                            无
            例1：
            当运行此代码时：
                    #include <stdio.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>

                    #include <errno.h>


                    int main(int argc, char const *argv[])
                    {
                        //使用open函数打开或创建一个文件
                        int fd = open("file.txt",O_RDONLY);  //以只读方式打开文件,不具有创建文件的能力
                        // int fd = open("file.txt",O_RDONLY | O_CREAT,0664);   //在使用flags的O_CREAT时，需跟一个文件权限mode,
                        //8进制0664代表 110(文件所有者可读可写权限) 110（同组用户可读可写权限） 100（其他组可读权限）

                        if(fd == -1)
                        {
                            //通过全局变量 errno打印错误码
                            //需要头文件：#include <errno.h>
                            printf("errno = %d\n",errno);
                            return -1;
                        }

                        printf("fd = %d\n",fd);

                        return 0;
                    }
            输出结果为：
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/2_system_call$ ./a.out
                errno = 2
            要想知道 errno = 2 对应的是什么错误，需要在下面的路径下 找到errno-base.h文件，里面对应了错误信息
                /usr/include/asm-generic
            再终端输入命令:
                cat errno-base.h
            得：
                #ifndef _ASM_GENERIC_ERRNO_BASE_H
                #define _ASM_GENERIC_ERRNO_BASE_H

                #define	EPERM		 1	//Operation not permitted
                #define	ENOENT		 2	//No such file or directory
                #define	ESRCH		 3	// No such process
                #define	EINTR		 4	// Interrupted system call
                #define	EIO          5  // I/O error
                #define	ENXIO		 6	// No such device or address
                #define	E2BIG		 7	// Argument list too long
                #define	ENOEXEC		 8	//Exec format error
                #define	EBADF		 9	// Bad file number
                #define	ECHILD		10	// No child processes
                #define	EAGAIN		11	// Try again
                #define	ENOMEM		12	// Out of memory
                #define	EACCES		13	// Permission denied
                #define	EFAULT		14	// Bad address
                #define	ENOTBLK		15	// Block device required
                #define	EBUSY		16	// Device or resource busy
                #define	EEXIST		17	// File exists
                #define	EXDEV		18	// Cross-device link
                #define	ENODEV		19	// No such device
                #define	ENOTDIR		20	// Not a directory
                #define	EISDIR		21	// Is a directory
                #define	EINVAL		22	// Invalid argument
                #define	ENFILE		23	// File table overflow
                #define	EMFILE		24	// Too many open files
                #define	ENOTTY		25	// Not a typewriter
                #define	ETXTBSY		26	// Text file busy
                #define	EFBIG		27	// File too large
                #define	ENOSPC		28	// No space left on device
                #define	ESPIPE		29	// Illegal seek
                #define	EROFS		30	// Read-only file system
                #define	EMLINK		31	// Too many links
                #define	EPIPE		32	// Broken pipe
                #define	EDOM		33	// Math argument out of domain of func
                #define	ERANGE		34	// Math result not representable

                #endif

            例2：
                    #include <stdio.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>

                    #include <errno.h>


                    int main(int argc, char const *argv[])
                    {
                        //使用open函数打开或创建一个文件
                        int fd = open("file.txt",O_RDONLY);  //以只读方式打开文件,不具有创建文件的能力
                        // int fd = open("file.txt",O_RDONLY | O_CREAT,0664);   //在使用flags的O_CREAT时，需跟一个文件权限mode,
                        //8进制0664代表 110(文件所有者可读可写权限) 110（同组用户可读可写权限） 100（其他组可读权限）

                        if(fd == -1)
                        {
                            //1.通过全局变量 errno打印错误码
                            //需要头文件：#include <errno.h>
                        // printf("errno = %d\n",errno);
                            //但返回错误码并不直观，还需要在/usr/include/asm-generic路径下使用cat errno-base.h指令，查询手册

                            //2.使用perror函数输出函数调用失败的错误信息
                            perror("fail to open");//fail to open: No such file or directory

                            return -1;
                        }
                        printf("fd = %d\n",fd);

                        return 0;
                    }


            2.3.3 close 函数
                2.3.3.1
                    关闭一个文件
                        #include <unistd.h>
                            int close(int fd);
                    参数:
                        fd是调用 open 打开文件返回的文件描述符,
                    返回值:
                        成功返回 0。
                        失败返回-1，可以利用 perror去查看原因,

                例1：
                        #include <stdio.h>
                        #include <sys/types.h>
                        #include <sys/stat.h>
                        #include <fcntl.h>

                        #include <unistd.h>


                        int main(int argc, char const *argv[])
                        {
                            int fd;
                            fd = open("file.txt",O_RDONLY);

                            if(fd == -1)
                            {
                                perror("fail to open");
                                return -1;
                            }

                            printf("fd = %d\n",fd);

                            //当不再对文件进行任何操作时，就会关闭文件描述符
                            //使用close 函数 关闭文件描述符
                            //一旦关闭文件描述符，就不能再通过原有的文件描述符操作文件。
                            close(fd);
                            printf("file has been closed\n");
                            return 0;
                        }

                2.3.3.2 文件描述符的相关问题：
            例：
                    #include <stdio.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>

                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        //1.测试一个进程创建的文件描述符的个数（一个进程（一个程序的运行） 最多能创建几个文件描述符）
                        //因此，一个程序运行时，最多可以创建1024个文件描述符（0～1023）。
                    #if 0
                        int fd;
                        while(1)
                        {
                            fd = open("file.txt",O_RDONLY | O_CREAT,0664);

                            if(fd == -1)
                            {
                                perror("fail to open");
                                break;
                                //return -1
                            }
                            printf("fd = %d\n",fd); //由于while一直打开文件，只要文件存在，调用fd就会从起始值3慢慢增加，那么 文件描述符fd 是否有上限值？

                            //执行结果：
                            // fd = 1023
                            // fail to open : Too many open files

                        }
                    #endif


                        //2.测试文件描述符值的规律
                        //文件描述符按照从大到小的顺序依次创建
                        //如果中途有文件描述符被关闭了，则再创建的文件描述符会先补齐之前的，然后再依次递增创建
                        //注意：不要认为最后创建的文件描述符一定是最大的。

                    #if 1
                        int fd1,fd2,fd3,fd4;
                        fd1 = open("file.txt",O_RDONLY | O_CREAT,0664);
                        fd2 = open("file.txt",O_RDONLY | O_CREAT,0664);
                        fd3 = open("file.txt",O_RDONLY | O_CREAT,0664);
                        fd4 = open("file.txt",O_RDONLY | O_CREAT,0664);

                        printf("fd1 = %d\n",fd1);
                        printf("fd2 = %d\n",fd2);
                        printf("fd3 = %d\n",fd3);
                        printf("fd4 = %d\n",fd4);

                        //执行结果：
                        // fd1 = 3
                        // fd2 = 4
                        // fd3 = 5
                        // fd4 = 6

                        //此时关闭一个文件描述符
                        close(fd2);

                        //再创建两个文件描述符，其值为?
                        int fd5,fd6;

                        fd5 = open("file.txt",O_RDONLY | O_CREAT,0664);
                        fd6 = open("file.txt",O_RDONLY | O_CREAT,0664);

                        printf("fd5 = %d\n",fd5);   //fd5 = 4
                        printf("fd6 = %d\n",fd6);   //fd6 = 7
                        //fd5先确保前面的文件描述符是连续的，fd6再在后面创建。
                    #endif
                        return 0;
                    }

            2.3.4 write 函数
                把指定数目的数据写到文件
                #include<unistd.h>
                    ssize_t write(int fd, const void *addr,size_t count);
                参数:
                    fd:文件描述符。
                    addr: 数据首地址。
                    count:写入数据的字节个数。
                返回值:
                    成功 返回 实际写入数据的字节个数。
                    失败 返回 -1，可以利用 perror 去查看原因。

                2.3.4.1 向终端写入数据
                    例：
                        #include <stdio.h>
                        #include <sys/types.h>
                        #include <sys/stat.h>
                        #include <fcntl.h>
                        #include <unistd.h>

                        int main(int argc, char const *argv[])
                        {
                            //向终端写入数据
                            //向1这个文件描述符进行操作

                            //往终端去写是没有缓存区的，应用层的系统调用会直接调用内核的系统调用，所以没有缓冲区一说，只要写一次，他就对磁盘空间执行一次。

                            if(write(1,"hello world\n",12) == -1)   //向终端输出故为1，
                            {
                                perror("fail to write");
                                return -1;
                            }
                            return 0;
                        }

                2.3.4.2 向文件中写入数据
                例：
                        #include <stdio.h>
                        #include <sys/types.h>
                        #include <sys/stat.h>
                        #include <fcntl.h>
                        #include <unistd.h>

                        int main(int argc, char const *argv[])
                        {
                            //向文件中写入数据
                            int fd;
                            //以只写的方式打开文件，若文件不存在则创建文件，若文件存在，则清空重写文件
                            fd = open("file.txt",O_WRONLY | O_CREAT | O_TRUNC,0664) ;

                            if(fd == -1)
                            {
                                perror("fail to open");
                                return -1;
                            }

                            //使用write 函数向文件写入数据
                            ssize_t bytes;
                            if((bytes = write(fd,"hello world\n",12)) == -1)
                            {
                                perror("fail to write");
                                return -2;
                            }
                            printf("bytes = %ld\n",bytes);

                            write(fd,"nihao beijing",5);
                            //关闭文件描述符
                            close(fd);

                            return 0;
                        }

            2.3.5 read 函数
                把指定数目的数据读到内存
                #include<unistd.h>
                    ssize_t read(int fd, void *addr, size_t count):
                参数:
                    fd:文件描述符。
                    addr:内存首地址。 传数组名
                    count:读取的字节个数。
                返回值:
                    成功 返回 实际读取到的字节个数，
                    失败 返回 -1，可以利用 perror 去查看原因
                注意：若读取到文件末尾，返回0。

                2.3.5.1 从终端读取数据
                例：
                    #include <stdio.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        //使用read函数从终端读取数据
                        //使用0文件描述符从终端读取数据

                        //如果终端输入的字节数大于第三个参数
                        //则只会读取第三个参数对应的字节数，返回值也是与第三个参数一致

                        //如果终端输入的字节数小于第三个参数
                        //则只会读取输入的数据加上一个换行符，返回值就是实际输入的数据+1（加的是换行符）

                        ssize_t bytes;
                        char str[30] = "";
                        if((bytes = read(0,str,6)) == -1)
                        {
                            perror("fail to read");
                            return -1;
                        }

                        printf("str = [%s]\n",str);     //读取的内容
                    printf("bytes = %ld\n",bytes);      //实际读取的个数

                        return 0;
                    }


                2.3.5.2 从文件中读取数据
                例：
                    #include <stdio.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>
                    #include <unistd.h>

                    #define N 64

                    int main(int argc, char const *argv[])
                    {

                        //使用read函数从文件中读取数据
                        int fd;
                        if((fd = open("test.txt",O_RDONLY | O_CREAT,0664)) == -1)
                        {
                            perror("fail to open");
                            return -1;
                        }

                        //读取文件内容
                        char buf[N] = "";
                        ssize_t bytes;
                    #if 0
                        if((bytes = read(fd,buf,32)) == -1)
                        {
                            perror("fail to read");
                            return -2;
                        }

                        printf("buf = [%s]\n",buf);     //读取的内容
                        printf("bytes = %ld\n",bytes);      //实际读取的个数

                        //再读取一次
                        //会接着上面的继续读取
                        char buf1[N] = "";
                        bytes = read(fd,buf1,32);

                        printf("buf1 = [%s]\n",buf1);     //读取的内容
                        printf("bytes = %ld\n",bytes);      //实际读取的个数

                        //第三次读取 知：
                        //若文件中的数据都读取完毕，则read会返回0
                        char buf2[N] = "";
                        bytes = read(fd,buf2,32);

                        printf("buf2 = [%s]\n",buf2);     //读取的内容
                        printf("bytes = %ld\n",bytes);      //实际读取的个数
                        // buf2 = []
                        // bytes = 0


                    #endif

                    #if 0
                        //读取文件中的所有内容
                        while((bytes = read(fd,buf,32)) !=  0)
                        {
                            printf("buf = [%s]\n",buf);
                            printf("bytes = %ld\n",bytes);
                        }
                    #endif

                        //关闭文件描述符
                        close(fd);
                        return 0;
                    }


            2.3.6 remove 库函数
                remove是一个库函数。
                删除文件
                    #include <stdio.h>
                    int remove(const char* pathname);
                参数：
                    pathname : 文件的路径名
                返回值：
                    成功返回 0.
                    失败返回 -1，可以利用perror去查看原因。

                例：
                    #include <stdio.h>

                    int main(int argc, char const *argv[])
                    {
                        //使用remove （库）函数删除文件
                        if(remove("./file.txt") == -1)
                        {
                            perror("fail to remove");
                            return -1;
                        }
                        printf("delete done\n");
                        return 0;
                    }

            2.4 系统调用 与 库函数
                库函数由两类函数组成

                2.4.1 不需要调用系统调用
                    不需要切换到内核空间 即可完成 函数全部功能，并且将结果 反馈给应用程序，如strcpy、bzero 等字符串操作函数。

                2.4.2需要调用系统调用
                    需要切换到内核空间，这类函数通过封装系统调用去实现相应功能，如printf、fread 等。

                2.4.3库函数与系统调用的关系:
                    并不是所有的系统调用 都被封装成了库函数，系统提供的很多功能 都必须通过 系统调用 才能实现。
                    （大多数的 库函数 都必须通过系统调用 才能实现）

                               应用程序
            库函数（调用系统调用）   <->   系统调用函数
            库函数（不调用系统调用）            |
                     用户态                  |
             -------------------------- 系统调用接口
                       内核态                |
                                        Linux内核
                                            |
                                        系统资源


            由此图知：我们写的应用程序 最终 都是对硬件系统资源 进行 控制
                    但想要控制硬件系统资源，都是 通过Linux内核 进行直接操作，所以应用程序想控制硬件设备，就相当于应用程序控制Linux内核。
                    但Linux也不能被直接操作（不安全，起保护作用），因此 有了系统调用(接口)
                    所以应用程序想要控制硬件设备，实际上就是想方设法去调用系统调用接口，
                    如果想要调用 系统调用接口，又有两种方式：
                                第一种：就是通过像本章学习的 系统调用函数来操作，如：open、write、read等，他们就能直接去调用Linux系统调用接口，进而控制硬件设备
                                第二种：调用系统调用的库函数(简称库函数)，是在 系统调用函数 之上又封装了一次，最终还是通过调用 系统调用函数 实现与 系统调用接口 的交流。

          * 系统调用 是需要时间的，程序中频繁的使用系统调用 会降低程序的运行效率。
                当运行内核代码时，CPU 工作在内核态，在系统调用发生前 需要保存 用户态的栈 和 内存环境，然后转入内核态工作。
                系统调用结束后，又要切换回用户态。这种环境的切换会消耗掉许多时间。

          * 而库函数访问文件的时候根据需要，设置不同类型的缓冲区，从而减少了直接调用IO系统调用的次数，提高了访问效率。

          总结： 大多数库函数的本质也是系统调用，只不过库函数有了缓冲区，用于减少系统调用的次数。

                内存
        ————————————————————————————————
                     <-   输入缓冲区<-   |                   外存
                    输入                |   <-输入（读）     ——————
        程序数据区                       |                  | 文件|
                    输出                |     输出（写）->   ——————
                      ->  输出缓冲区->   |
        ————————————————————————————————

        应用程序调用 printf 函数时，函数执行的过程，如下图：

        printf()    ——>     向缓冲区写数据，将缓冲区的数据写到文件     ——>  write()

        应用程序                         C库                           系统调用
*/

//错误码对应的错误原因可以在/usr/include/asm-generic/errno-base.h 中查询

//第三章 进程
/*
    3.1进程概述
        3.1.1 进程的定义
            程序:
                程序是存放在存储介质上的一个可执行文件。

            进程:
                进程是程序的执行实例，包括 程序计数器、寄存器 和 变量的当前值。

            程序是静态的，进程是动态的:
                程序是一些指令的有序集合，而进程是程序执行的过程。
                进程的状态是变化的，其包括进程的创建、调度和消亡。

        进程的属性;
            在 linux 系统中，进程 是 管理事务的基本单元。进程拥有自己独立的处理环境和系统资源（处理器、存储器、 IO 设备、数据、程序)。
            可使用 exec 函数由内核将程序读入内存，使其执行起来成为一个进程。

        总结：
            程序和进程的区别:
                程序:是静态的，存放在磁盘上的可执行文件
                进程:是动态的，是运行在内存中的程序的执行实例

            程序是一些指令的有序集合，而 进程 是 程序 的一次执行过程。
            进程的状态是变化的，其包括进程的创建、调度和消亡。
            只要程序运行，此时就是进程，程序每运行一次，就会创建一个进程。

        3.1.2 进程的状态及转换

            进程整个生命周期可以简单 划分为 三种状态：
                就绪态：
                    进程以及具备执行的一切条件，正在等待分配CPU的处理时间。。
                执行态：
                    该进程正在占用CPU运行。
                等待态:
                    进程因不具备某些执行条件而暂时无法继续执行的状态。

                进程的调度机制：
                    时间片轮转，上下文切换。（每一个进程短时间运行）
                    多进程 不是指 一个进程执行完再执行另一个进程，而是交替执行的，一个进程执行一段时间，然后下一个进程再执行一段时间。以此类推，
                    所有进程执行完后再回到第一个进程继续执行。


//                        进程三种状态的转换关系：
//
//            进程调度                        事件发生，被唤醒
//           <——————— —————>      就绪态       <-------
//                    时间片到
//                              等待某事发生
//                执行态      ————————————————>    等待态


        3.1.3 进程控制块

          * OS 是根据 PCB 来对 并发执行的进程 进行控制 和管理的。系统在创建一个进程的时候 会开辟一段内存空间存放与此进程相关的 PCB 数据结构。

          * PCB 是操作系统中最重要的记录型数据结构。PCB中记录了用于描述进程进展情况及控制进程运行所的全部信息。

          * PCB 是 进程存在的唯一标志，在Linux中 PCB存放在 task stnuct 结构体中。

          * PCB结构体中的部分数据：
                调度数据：
                    进程的状态、标志、优先级、调度策略等。
                时间数据：
                    创建该进程的时间、在用户态的运行时间在内核态的运行时间等。
                文件系统数据:
                    umask掩码、文件描述符表等。
                内存数据、进程上下文、进程标识（进程号）
                ...

        总结：
            进程控制块 就是 用于保存一个进程信息的结构体，又称之为PCB（进程控制块缩写）。   ( 此PCB 非彼 PCB)
            task_struct结构体保存在/usr/src/linux-headers-5.15.0-125-generic/include/linux/sched.h中，一般在1300-1500行左右。
            该结构体含有：调度数据、时间数据、文件系统数据、内存数据、进程上下文、进程标识（进程号）等等。

        1.一般情况下，进程控制块是保存在Linux内核中的,Linux内核在 /user/src 路径下，src下存放的就是Linux内核。
        例：
                qinmei@qinmei-virtual-machine:/usr/src$ cd /
                qinmei@qinmei-virtual-machine:/$ ls
                bin    dev   lib    libx32      mnt   root  snap      sys  var
                boot   etc   lib32  lost+found  opt   run   srv       tmp
                cdrom  home  lib64  media       proc  sbin  swapfile  usr
                qinmei@qinmei-virtual-machine:/$ cd usr
                qinmei@qinmei-virtual-machine:/usr$ ls
                bin    include  lib32  libexec  local  share
                games  lib      lib64  libx32   sbin   src
                qinmei@qinmei-virtual-machine:/usr$ cd src
                qinmei@qinmei-virtual-machine:/usr/src$ ls
                gmock                             linux-headers-5.15.0-127-generic      //我们的Linux内核是5.15.0版本
                googletest                        linux-hwe-5.15-headers-5.15.0-125
                gtest                             linux-hwe-5.15-headers-5.15.0-127
                linux-headers-5.15.0-125-generic


            2.但是这么多文件，task stnuct放在哪里是不知道的，因此执行下列命令：
                sudo apt-get install ctags  //下载 ctags 工具
            3.当再次运行上面命令，显示为已经是最新版本则运行下面的命令：
                sudo ctags -R
            4.最终会生成索引文件tags
         执行流程及结果如下：
                qinmei@qinmei-virtual-machine:~$ cd /usr/src
                qinmei@qinmei-virtual-machine:/usr/src$ sudo apt-get install ctags
                [sudo] qinmei 的密码：
                正在读取软件包列表... 完成
                正在分析软件包的依赖关系树
                正在读取状态信息... 完成
                注意，选中 'exuberant-ctags' 而非 'ctags'
                下列【新】软件包将被安装：
                  exuberant-ctags
                升级了 0 个软件包，新安装了 1 个软件包，要卸载 0 个软件包，有 75 个软件包未被升级。
                需要下载 129 kB 的归档。
                解压缩后会消耗 349 kB 的额外空间。
                获取:1 http://mirrors.aliyun.com/ubuntu focal-security/main amd64 exuberant-ctags amd64 1:5.9~svn20110310-12ubuntu0.1 [129 kB]
                已下载 129 kB，耗时 0秒 (898 kB/s)
                正在选中未选择的软件包 exuberant-ctags。
                (正在读取数据库 ... 系统当前共安装有 278410 个文件和目录。)
                准备解压 .../exuberant-ctags_1%3a5.9~svn20110310-12ubuntu0.1_amd64.deb  ...
                正在解压 exuberant-ctags (1:5.9~svn20110310-12ubuntu0.1) ...
                正在设置 exuberant-ctags (1:5.9~svn20110310-12ubuntu0.1) ...
                update-alternatives: 使用 /usr/bin/ctags-exuberant 来在自动模式中提供 /usr/bin/ctags (ctags)
                update-alternatives: 使用 /usr/bin/ctags-exuberant 来在自动模式中提供 /usr/bin/etags (etags)
                正在处理用于 man-db (2.9.1-1) 的触发器 ...
                qinmei@qinmei-virtual-machine:/usr/src$ sudo apt-get install ctags
                正在读取软件包列表... 完成
                正在分析软件包的依赖关系树
                正在读取状态信息... 完成
                注意，选中 'exuberant-ctags' 而非 'ctags'
                exuberant-ctags 已经是最新版 (1:5.9~svn20110310-12ubuntu0.1)。
                升级了 0 个软件包，新安装了 0 个软件包，要卸载 0 个软件包，有 75 个软件包未被升级。
                qinmei@qinmei-virtual-machine:/usr/src$ sudo ctags -R
                qinmei@qinmei-virtual-machine:/usr/src$ ls
                gmock                             linux-headers-5.15.0-127-generic
                googletest                        linux-hwe-5.15-headers-5.15.0-125
                gtest                             linux-hwe-5.15-headers-5.15.0-127
                linux-headers-5.15.0-125-generic  tags
                qinmei@qinmei-virtual-machine:/usr/src$

            5.此时再输入以下命令去查询：
                vim -t task_struct  (vim -t 你想要查询的东西（如宏定义，取别名等）)


    3.2 进程控制
        3.2.1 进程号
            每个进程都由一个进程号来标识，其类型为pid_t，进程号的范围:0~32767。 进程号总是唯一的，但进程号可以重用。当一个进程终止后，其进程号就可以再次使用了。

            进程号是由操作系统随机给当前进程分配的，不能自己控制

            在linux 系统中进程号由0开始。
                进程号为0及1的进程 由 内核创建。
                进程号为0的进程 通常是 调度进程，常被称为 交换进程(swvapper)。
                进程号为1的进程 通常是 init 进程。 init进程是所有进程的祖先。若要创建一个进程，其一定是init进程的子进程。
                除调度进程外，在 linux下面所有的进程 都由进程 init进程 直接 或者 间接 创建。


            进程号(PID)
                标识进程的一个非负整型数。
            父进程号(PPID)
                任何进程(除init 进程)都是由另一个进程创建，该进程称为被创建进程的父进程，对应的进程号称为父进
            进程组号（PGID）
                进程组是一个或多个进场的集合。他们之间相互关联，进程组可以接收同一终端的各种信号，关联的进程有一个进程组号（PGID）。
            （父子进程辨别方法：谁在内部创建了谁?）


            Linux操作系统提供了三个获得进程号的函数 getpid()、getppid()、getpgid().
            (使用man查询)
            #include <sys/types.h>
            #include <unistd.h>

            pid_t getpid(void);
                功能：获取当前进程的进程号。
            pid_t getppid(void);
                功能：获取当前进程的父进程的进程号。
            pid_t getpgid(pid_t pid);
                功能：获取当前进程所在进程组的ID。

            例：
                #include <stdio.h>
                #include <sys/types.h>
                #include <unistd.h>

                int main(int argc, char const *argv[])
                {
                    //获取当前进程的进程号
                    printf("pid = %d\n",getpid());

                    // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                    // pid = 143063
                    //注意，此时用 ps ajx去查看时，由于程序已经运行完毕，因此查不到该进程号对应的进程。

                    //获取当前进程的父进程的ID
                    printf("ppid = %d\n",getppid());

                    //获取当前进程所在组的id
                    printf("pgid = %d\n",getpgid(getppid()));

                    while(1)
                    {

                    }
                    return 0;
                }


         * 在ubuntu中查看当前系统中所有的开启的进程 的命令：
                    ps ajx

            部分 执行结果：
                PPID     PID    PGID     SID TTY        TPGID STAT   UID   TIME COMMAND
                  0       1       1       1 ?             -1 Ss       0   0:05 /sbin/i
                  0       2       0       0 ?             -1 S        0   0:00 [kthrea
                  2       3       0       0 ?             -1 I<       0   0:00 [rcu_gp
                  2       4       0       0 ?             -1 I<       0   0:00 [rcu_pa
                  2       5       0       0 ?             -1 I<       0   0:00 [slub_f
                  2       6       0       0 ?             -1 I<       0   0:00 [netns]

                分析：
           *        PPID:当前进程的父进程的进程号
           *        PID :当前进程的进程号
           *        PGID:当前进程 所在的组的 进程组ID
                   STAT :状态，表示进程现在的状态
                   UID  :用户ID,当前哪一个用户创建的进程。表示进程的所有者，用户ID
                   TIME :进程运行的时间。
           *    COMMAND :当前进程的名字


           若只敲 命令： ps
                查看当前进程所对应的子进程，以及当前进程的信息
            例：
            qinmei@qinmei-virtual-machine:~$ ps
                PID TTY          TIME CMD
             142704 pts/0    00:00:00 bash      //bash 表示终端,是终端进程
             142755 pts/0    00:00:00 ps        //由于敲了ps，因此是ps命令的进程



        3.2.2 进程的创建 fork函数
       （ 为助于理解，可见：https://blog.csdn.net/Front123456/article/details/131998068)

            在 linux环境下，创建进程的主要方法是调用以下两个函数:
            #include <sys/types.h>
            #inelude <unistd.h>

                pid t fork(void):
                pid t vfork(void):

            创建一个新进程
                pid_t fork(void)    //返回的是类似一进程号的东西

            功能:
                fork()函数用于从一个已存在的进程中创建一个新进程，新进程称为子进程，原有的进程称为父进程
            返回值:
                成功:子进程中返回0，父进程中返回子进程ID
                失败:返回-1。
                （当创建了一个进程之后怎么区分：父进程怎么运行，子进程又怎么运行？  就是通过fork的返回值来进行区分。因为代码肯定要写在一个里面）
                （因此，如果fork返回0，就是子进程的代码区，返回值大于0就是父进程的代码区。而失败就返回-1）

               * 使用fork函数得到的子进程 是父进程的一个复制品，它从 父进程处继承了整个进程的地址空间.(父子进程是独立的)

            地址空间:
               * 包括进程上下文、进程堆栈、打开的文件描述符、信号控制设定、进程优先级、进程组号等。

               * 子进程所独有的只有他的进程号，计时器等。因此，使用fork函数的代价是很大的。
            （完完全全创建一个新的进程，而且新进程与原有进程一点关系都没有）


            fork函数执行结果：
                fork函数执行完毕后父子进程的空间示意图：

                父进程   ——> fork  ——>   子进程
                栈区                      栈区
                堆区                      堆区
                BSS区                     BSS区
                数据区                    数据区
                代码区                    代码区


            3.2.2.1 创建子进程
             *  不区分父子进程：（不推荐）
            例：
                    #include<stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        //通过fork函数创建一个子进程
                        fork();

                        //注意：1.只要执行一次fork，就会在原有的进程基础上创建一个新的子进程
                        //     2.而且如果fork之后不区分父子进程的代码区，则后面所有的代码 父子进程都会去执行一次。
                    //所以在写代码的时候，一定要区分父子进程
                        printf("hello world\n");
                        //结果是：打印了两次hello world.

                        while(1)
                        {

                        }
                        return 0;
                    }


              * 区分父子进程：（推荐）
                例：
                    #include<stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                    #if 0
                    //不区分父子进程:
                        //通过fork函数创建一个子进程
                        fork();

                        //注意：1.只要执行一次fork，就会在原有的进程基础上创建一个新的子进程
                        //     2.而且如果fork之后不区分父子进程的代码区，则后面所有的代码 父子进程都会去执行一次。
                        //所以在写代码的时候，一定要区分父子进程
                        printf("hello world\n");
                        //结果是：打印了两次hello world.

                        while(1)
                        {

                        }
                    #endif

                    #if 0
                    //区分父子进程:
                        //通过fork函数的返回值来区分父子进程的独立的代码区
                        //创建子进程是为了让他能干自己的事情。
                        pid_t pid;
                        pid = fork();

                        //返回值 -1:出错    0：//子进程的代码区   >0表示：返回的是子进程的进程号，并且当前的代码区是父进程的代码区
                        if(pid < 0)
                        {
                            perror("fail to fork");
                            return -1;
                        }
                        else if(pid > 0)    //>0表示：返回的是子进程的进程号，并且当前的代码区是父进程的代码区
                        {
                            while(1)
                            {
                                //获取该进程号，获取该父进程的 父进程号，并且pid>0还可以获取子进程的进程号
                                printf("parent: pid = %d,ppid = %d\n",getpid(),getppid());
                                printf("pid = %d\n",pid);
                                printf("this is parent process\n");
                                sleep(1);
                                printf("**********************\n");
                            }
                        }
                        else    //子进程的代码区
                        {
                                while(1)
                            {
                                //获取其进程号，获取该子进程的 父进程号
                                printf("son: pid = %d,ppid = %d\n",getpid(),getppid());
                                printf("this is son process\n");
                                sleep(1);
                                printf("--------------------------\n");
                            }
                        }
                    //执行结果：
                    // parent: pid = 7268,ppid = 4821
                    // pid = 7269
                    // this is parent process
                    // son: pid = 7269,ppid = 7268
                    // this is son process
                    // parent: pid = 7268,ppid = 4821
                    // son: pid = 7269,ppid = 7268
                    // pid = 7269
                    // this is son process


                    #endif

                    #if 1
                    //验证进程的上下文切换实现：
                        //通过fork函数的返回值来区分父子进程的独立的代码区
                        //父子进程是来回交替进行的。谁先运行，谁后运行是不确定的。不要认为父进程执行完后才执行子进程。

                        //创建子进程是为了让他能干自己的事情。
                        pid_t pid;
                        pid = fork();

                        //返回值 -1:出错    0：//子进程的代码区   >0表示：返回的是子进程的进程号，并且当前的代码区是父进程的代码区
                        if(pid < 0)
                        {
                            perror("fail to fork");
                            return -1;
                        }
                        else if(pid > 0)    //>0表示：返回的是子进程的进程号，并且当前的代码区是父进程的代码区
                        {
                            while(1)
                            {
                                //获取该进程号，获取该父进程的 父进程号，并且pid>0还可以获取子进程的进程号
                                printf("parent: pid = %d,ppid = %d\n",getpid(),getppid());
                                printf("pid = %d\n",pid);
                                printf("this is parent process\n");
                                sleep(1);
                                printf("**********************\n");
                            }
                        }
                        else    //子进程的代码区
                        {
                                while(1)
                            {
                                //获取其进程号，获取该子进程的 父进程号
                                printf("son: pid = %d,ppid = %d\n",getpid(),getppid());
                                printf("this is son process\n");
                                sleep(1);
                                printf("--------------------------\n");
                            }
                        }

                        // 执行结果：
                        // parent: pid = 7405,ppid = 4821
                        // pid = 7406
                        // this is parent process
                        // son: pid = 7406,ppid = 7405
                        // this is son process
                        // **********************
                        // --------------------------
                        // son: pid = 7406,ppid = 7405
                        // parent: pid = 7405,ppid = 4821
                        // this is son process
                        // pid = 7406
                        // this is parent process
                        // --------------------------
                        // **********************
                        // son: pid = 7406,ppid = 7405
                        // this is son process
                        // parent: pid = 7405,ppid = 4821
                        // pid = 7406
                        // this is parent process
                        // --------------------------
                        // son: pid = 7406,ppid = 7405
                        // this is son process
                        // **********************

                    #endif
                        return 0;
                    }

。
            3.2.2.2 父子进程拥有独立的地址空间
                例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>

                    int a = 666;


                    int main(int argc, char const *argv[])
                    {
                        pid_t pid;

                        static int b = 777;
                        int c = 888;
                        //a,b,c都是创建子进程之前创建的，是父进程的变量。

                        pid = fork();
                        if(pid < 0)
                        {
                            perror("fail to fork");
                            return -1;
                        }
                        //>0表示：返回的是子进程的进程号，并且当前的代码区是父进程的代码区
                        else if(pid > 0)
                        {
                            printf("this is parent process\n");
                            a++;
                            b++;
                            c++;
                            printf("a = %d,b = %d,c = %d\n",a,b,c);
                        }
                        else
                        {
                            sleep(1);   //由于打印的abc没有标识父子，所以先确保父进程先打印。
                            printf("this is son process\n");
                            printf("a = %d,b = %d,c = %d\n",a,b,c);
                        }
                        while(1)
                        {

                        }
                    //验证：1.父进程的值改变之后，子进程的能不能获取到改变之后的值。
                    //     2.父进程的内容，子进程有没有复制过来。

                    // 执行结果：
                    // this is parent process
                    // a = 667,b = 778,c = 889
                    // this is son process
                    // a = 666,b = 777,c = 888

                        //由结果可知：
                        //  1.子进程把fork()前面的所有内容复制过来了
                        //  2.由于fork()之后，父进程与子进程是完全相互独立的，所以父进程的全局区、代码区、堆区、栈区等与子进程没有任何关系

                        //子进程会复制父进程fork之前的所有内容
                        //但是fork之后，父子进程完全独立，所以不管双方怎么改变（堆区、栈区、数据区、代码区、Bss区等）都不会受对方影响
                        //但像是父子进程修改同一个磁盘文件这种，父子进程还是有联系的。
                        return 0;
                    }


            3.2.2.3 子进程继承父进程的空间
            总结：
              子进程会继承父进程的一些公有的区域，比如：磁盘空间、内核空间
              文件描述符的偏移量保存在内核空间，所以父进程改变偏移量，则子进程获取的偏移量是改变之后的。

            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>

                    int main(int argc, char const *argv[])
                    {
                        int fd;
                        if((fd = open("file.txt",O_RDONLY | O_CREAT,0664)) == -1)
                        {
                            perror("fail to open");
                            return -1;
                        }

                        pid_t pid;
                        pid = fork();
                        if(pid < 0)
                        {
                            perror("fail to fork");
                            return -1;
                        }
                        else if(pid > 0)
                        {
                            printf("This is a parent process\n");
                            char buf[32] = "";
                            if(read(fd,buf,30) == -1)
                            {
                                perror("fail to read");
                                return -1;
                            }
                            printf("buf = [%s]\n",buf);
                        }
                        else
                        {
                            sleep(1);
                            printf("This is a son process\n");

                            char buf[32] = "";
                            if(read(fd,buf,30) == -1)
                            {
                                perror("fail to read");
                                return -1;
                            }
                            printf("buf = [%s]\n",buf);
                        }

                        //如果不加while,输出结果为：
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // This is a parent process
                        // buf = [hello world
                        // nihao beijing
                        // welc]
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ This is a son process
                        // buf = [ome to 1000phone
                        // ]
                        //我们发现: 中间有一个命令终端，原因就是：父进程只要运行结束，就会打印命令终端，而子进程不会
                        //（说明是父进程运行完了才运行子进程）

                        //因此需要加while，但等学到后面就不需要再加while(1)了
                        while(1)
                        {

                        }

                        //执行结果：
                        // This is a parent process
                        // buf = [hello world
                        // nihao beijing
                        // welc]
                        // This is a son process
                        // buf = [ome to 1000phone
                        // ]

                        //之所以会相互影响，是因为：文件的这些信息是保存在内核里面的，相对于父子进程而言，内核是公有的，所以，当第一个进程对文件操作完之后，文件的偏移量就会跑到读取的最后一个字符的下一个位置
                        //那么下一个子进程再去读取的时候，偏移量是直接继承过来的，所以从下一个位置继续再运行。

                    //总结：
                    //  子进程会继承父进程的一些公有的区域，比如：磁盘空间、内核空间
                    //  文件描述符的偏移量保存在内核空间，所以父进程改变偏移量，则子进程获取的偏移量是改变之后的。
                        return 0;
                    }

        3.2.3 进程的挂起
            进程在一定的时间内没有任何动作，称为进程的挂起
            #include <unistd.h>
                unsigned int sleep(unsigned int sec);
            功能:
                进程挂起指定的秒数，直到指定的时间用完或收到信号才解除挂起
            返回值:
                若进程挂起到 sec 指定的时间则返回0，若有信号中断则返回剩余秒数
            注意:
                进程挂起指定的秒数后程序并不会立即执行，系统只是将此进程切换到 就绪态，再到运行态

            例：
                    #include <stdio.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        while(1)
                        {
                            printf("hello world\n");

                            //当运行到sleep函数之后，程序会在此位置等待设定的秒数，当秒数到达之后，代码会接着执行。
                            //sleep运行时，进程为等待态，时间到达后会先切换到就绪态，若代码继续运行，再切换到运行态。
                            sleep(2);
                        }
                        return 0;
                    }

        3.2.4 进程的等待(sleep是进程的挂起)

            父子进程有时需要简单的进程间同步（互斥：原本的进程是交替运行的,而同步则是：必须一个执行完之后再去执行第二个，），如父进程等待子进程的结束，
                （例如之前的程序，不加while(1)后，父进程运行完退出后就直接打印终端提示符了，子进程 不便于 查看它的形式、现象和运行结果）
            1inux下 提供了以下两个等待函数 wait()、waitpid()。
            需要包含头文件:
            #include <sys/types.h>
            #include <sys/wait.h>

            3.2.4.1 wait函数
                头文件:
                    #include <sys/types.h>
                    #include <sys/wait.h>

                pid_t wait(int *status);
                功能:
                    等待子进程终止，如果子进程终止了，此函数会回收子进程的资源。
                    调用 wait 函数的进程会挂起，直到它的一个子进程退出 或 收到一个不能被忽视的信号时才被唤醒。
                    若调用进程没有子进程或它的子进程已经结束，该函数立即返回。
                参数:
                    函数返回时，参数 status 中包含子进程退出时的状态信息。
                    子进程的退出信息在一个 int 中包含了多个字段 ，
                    用宏定义可以取出其中的每个字段。
                    子进程可以通过 exit 或者 _exit 函数发送 退出状态。

                返回值:
                    如果执行成功则返回子进程的进程号
                    出错返回-1，失败原因存于errno中。

                取出子进程的退出信息
                    WIFEXITED(status)
                        如果子进程是正常终止的，取出的字段值非零
                    WEXITSTATUS(status)
                        返回子进程的退出状态，退出状态保存在 status 变量的8~16 位。
                        在用此宏前应先用宏 WIFEXITED判断子进程是否正常退出，正常退出才可以使用此宏。
                    注意:
                        此 status 是个 wait的参数,指向的整型变量 (int *status)

                例：
                        // #include <stdio.h>
                        // #include <stdlib.h>
                        // #include <unistd.h>
                        // #include <sys/types.h>
                        // #include <sys/wait.h>

                        // int main(int argc, char const *argv[])
                        // {
                        //     pid_t pid;
                        //     pid = fork();
                        //     if(pid < 0)
                        //     {
                        //         perror("fail to fork");
                        //         return -1;
                        //     }
                        //     else if(pid > 0)
                        //     {
                        //         printf("this is parent process\n");
                        //     }
                        //     else
                        //     {
                        //         int i = 0;
                        //         for(i = 0;i<5;i++)
                        //         {
                        //             printf("this is son process\n");
                        //             sleep(1);
                        //         }
                        //     }
                        //     return 0;

                        // }

                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <sys/types.h>
                        #include <sys/wait.h>

                        int main(int argc, char const *argv[])
                        {
                            pid_t pid;
                            pid = fork();
                            if(pid < 0)
                            {
                                perror("fail to fork");
                                return -1;
                            }
                            if(pid == 0)
                            {
                                int i = 0;
                                for(i = 0;i<5;i++)
                                {
                                    printf("this is son process\n");
                                    sleep(1);
                                }
                                //使用exit退出进程，并设置退出状态
                                exit(2);
                            }
                            else
                            {
                                //使用wait在父进程中阻塞等待子进程的退出。
                                // wait(NULL);//如果不想接收子进程的退出状态，传NULL即可

                                //接收子进程的退出状态，子进程中必须使用exit或者_exit函数，退出时发送退出状态。
                                int status = 0;
                                wait(&status);

                                //取出子进程的退出信息
                                if(WIFEXITED(status) != 0)  //判断取出的字段值是否非零。
                                {
                                    printf("The son process return status: %d\n",WEXITSTATUS(status));
                                }
                                printf("this is parent process\n");
                            }

                            // 结果1不加wait：
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                            // this is parent process
                            // this is son process
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ this is son process
                            // this is son process
                            // this is son process
                            // this is son process
                            //由于打印了终端提示符，因此父进程已经执行完成了。

                            //结果2：加wait(NULL)
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                            // this is son process
                            // this is son process
                            // this is son process
                            // this is son process
                            // this is son process
                            // this is parent process
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$

                            //结果3，取出子进程的退出信息：
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                            // this is son process
                            // this is son process
                            // this is son process
                            // this is son process
                            // this is son process
                            // The son process return status: 2
                            // this is parent process


                            return 0;

                        }


            3.2.4.2 waipidt函数
                头文件:
                    #include <sys/types.h>
                    #include <sys/wait.h>

                pid t waitpid(pid_t pid, int *status,int options)
                功能:
                    等待子进程终止，如果子进程终止了，此函数会回收子进程的资源。
                返回值:
                    如果执行成功则返回子进程 ID，
                    出错返回 -1，失败原因存于 errno 中
                参数 pid 的值有以下几种类型:

                    参数1 pid：可以指定哪一个子进程的，
                        pid > 0:
                            等待进程 ID 等于 pid 的子进程,
                        pid = 0
                            等待同一个进程组中的任何子进程，如果子进程已经加入了别的进程组，waitpid 不会等待它。
                        pid = -1:
                            等待任一子进程，此时 waitpid 和 wait 作用一样。
                        pid < -1:
                            等待指定进程组中的任何子进程，这个进程组的ID 等于 pid,的绝对值。

                    参数2 status:
                        status 参数中包含子进程退出时的状态信息。
                    参数3 options：
                        options 参数能进一步控制waitpid 的操作:
                        0：
                            同 wait，阻塞父进程，等待子进程退出。
                        WNOHANG:(非阻塞)
                            没有任何己经结束的子进程，则立即返回
                        WUNTRACED：
                            如果子进程暂停了则此函数马上返回，并且不予以理会子进程的结束状态。(跟踪调试，很少用到)
                返回值:
                    成功:：
                        返回状态改变了的 子进程的进程号:如果设置了选项 WNOHANG 并且 pid 指定的进程存在则返回 0。
                    出错:
                        返回-1。当 pid 所指示的子进程不存在，或此进程存在，但不是调用进程的子进程，waitpid 就会出错返回，这时 errno 被设置为 ECHILD。

                wait(status)  <==>    waitpid(-1,status,0)
            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <sys/types.h>
                    #include <sys/wait.h>

                    int main(int argc, char const *argv[])
                    {
                        pid_t pid;

                        pid = fork();

                        if(pid < 0)
                        {
                            perror("fail to fork");
                            return -1;
                        }
                        if(pid == 0)
                        {
                            int i = 0;
                            for(i = 0;i<5;i++)
                            {
                                printf("this is son process\n");
                                sleep(1);
                            }
                            exit(0);
                        }
                        else
                        {
                            waitpid(pid,NULL,0);//NULL表示不接收，0表示阻塞父进程，等待子进程；pid表示：只接收当前子进程的退出状态。
                            printf("this is parent process\n");
                        }
                        return 0;
                    }

            特殊进程：
                僵尸进程(Zombie Process)
                    进程已运行结束，但进程的占用的资源未被回收，这样的进程称为僵尸进程。
                    子进程已运行结束，父进程未调用 wait 或 waitpid 函数回收子进程的资源是子进程变为僵尸进程的原因。
                孤儿进程(Orphan Process)
                    父进程运行结束，但子进程未运行结束的子进程。
                守护进程(精灵进程)(Daemon process)
                    守护进程是个特殊的孤儿进程，这种进程脱离终端，在后台运行。
、                   (系统进程 一般都是 守护进程)

        3.2.5 进程的终止（结束一个进程）
        对于使用return结束进程
            注意：如果实在主函数，使用return确实可以结束一个进程，但如果是在子函数使用return,他只能退出一个函数，只不过主函数刚好是入口函数。
                  所以并不是在任何地方都能使用return 退出进程。

            在 1inwx,下可以通过以下方式结束正在运行的进程:
                void exit(int value);
                void _exit(int value);

        3.2.5.1 exit函数
            结束进程执行

            头文件：
                #include <stdlib.h>

                void exit(int value)
            参数：
                status：退出状态，由父进程通过wait函数接收这个状态（返回给父进程的参数（低8位有效））。
                一般失败退出设置为 非0
                一般成功退出设置为 0
            返回值：
                无

        3.2.5.2 _exit 函数
            结束进程执行

            头文件：
                #include <unist.h>

                void _exit(int value)
            参数：
                status：退出状态，由父进程通过wait函数接收这个状态（返回给父进程的参数（低8位有效））。
                一般失败退出设置为 非0
                一般成功退出设置为 0
            返回值：
                无


            exit 和 _exit函数的区别：
                exit 为 库函数，而 _exit 为 系统调用
                即：exit会刷新缓冲区，而_exit不会刷新缓冲区（系统调用没有缓冲区一说）。
                故，一般使用 exit。

            图解：

                        程序运行
                    |           |
                    |       atexit注册的退出处理函数
                    |           |   exit()
             _exit()|           |
                    |       刷I/O缓冲关于文件描述符
                    |           |
                    |           |
                    调用_exit()系统调用
                            |
                        进程终止运行


                例：
                    #include <stdio.h>
                    #include <unistd.h>
                    #include <stdlib.h>

                    void myfun()
                    {
                        // printf("nihao beijing\n");

                        //如何区分是否刷新了缓冲区？将上面的\n去掉
                        printf("nihao beijing");

                        //使用return
                        //return 除了可以返回值以外，在主函数值使用可以退出进程，但是在子函数中使用只能退出当前函数
                        // return ;

                        //使用exit
                        //exit可以退出一个进程，并刷新缓冲区
                        // exit(0);

                        //使用_exit
                        //_exit可以退出一个进程，但不会刷新缓冲区
                        _exit(0);
                        printf("welcome to 1000phone\n");
                    }

                    int main(int argc, char const *argv[])
                    {
                        printf("hello world\n");

                        myfun();

                        printf("hello kitty\n");


                    //对于exit刷新缓冲区结果：
                    // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                    // hello world
                    // nihao beijingqinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$
                    //其能够打印 nihao beijing

                    //而对于 _exit:
                    // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                    // hello world
                    // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$
                    //不能打印 nihao beijing，因为没有加\n，就没有刷新缓冲区

                        return 0;
                    }


        3.2.6 进程退出清理
        （一个函数，当进程结束时，这个函数对应的内容才会去执行）

            进程在退出前可以用 atexit函数 注册 退出处理函数。
            头文件：
                #include <stdlib .h>

            int atexit(void (*function)(void));     //参数是回调函数
            功能:
                注册 进程正常结束前 调用的函数，进程退出 则执行 注册函数。
            参数:
                function:进程结束前，调用函数的入口地址。
                一个进程中可以多次调用 atexit函数注册 清理函数，正常结束前 调用函数的顺序 和 注册时的顺序相反
                注意：
                    function 既没有参数，也没有返回值，函数体随意写。
            返回值：
                成功：0
                失败：非0

        例：
                    #include <stdio.h>
                    #include <unistd.h>
                    #include <stdlib.h>

                    void clear_fun1(void)
                    {
                        printf("perform clear fun1 \n");
                    }

                    void clear_fun2(void)
                    {
                        printf("perform clear fun2 \n");
                    }

                    void clear_fun3(void)
                    {
                        printf("perform clear fun3 \n");
                    }

                    int main(int argc, char const *argv[])
                    {
                        atexit(clear_fun1);
                        atexit(clear_fun2);
                        atexit(clear_fun3);
                        printf("process exit 3 sec later!!!\n");
                        sleep(3);
                        //由于atexit是在进程结束的时候才执行参水对应的回调函数，
                        //并且，由于atexit在多次调用后，执行顺序与调用顺序相反，故执行结果为：

                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // process exit 3 sec later!!!
                        //（等待3秒之后，打印下面的内容，并且从fun3 -> fun1）
                        // perform clear fun3
                        // perform clear fun2
                        // perform clear fun1


                        return 0;

                    }


        3.2.7 进程的创建 --vfork函数

            pid vfork(void)

            功能：
                vfork 函数和 fork函数一样 都是 在已有的进程中 创建一个新的进程，但它们创建的子进程是有区别的。
            返回值:
                (创建子进程)  成功，则在子进程中返回0,父进程中返回子进程 ID。
                             出错，则返回-1。

            fork和vfork函数的区别:
              * vfork 保证子进程先运行，在它调用 exec 或 exit 之后，父进程才可能被调度运行。
                (子进程运行完毕之后才会运行父进程)

              * vfork 和 fork 一样都创建一个子进程，但它并不将父进程的地址空间完全复制到子进程中，因为子进程会立即调用 exec(或 exit)，于是也就不访问该地址空间。
                （vfork不会复制一份父进程的地址空间的，而是父子进程拥有同一块空间）

              * 相反，在子进程中调用 exec 或 exit之前，它在父进程的地址空间中运行，在 exec之后子进程会有自己的进程空间。
                （子进程在父进程的地址空间运行，exec之后子进程才拥有自己的进程空间。）


            3.2.7.1 子进程在父进程之前运行，并且子进程运行完毕之后才会运行父进程

            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    int main(int argc, char const *argv[])
                    {
                        pid_t pid;

                        pid = vfork();
                        //使用vfork函数创建完子进程后
                        //子进程会先执行,直到子进程执行exit或exec之后,父进程才会执行。
                        if(pid < 0)
                        {
                            perror("fail to vfork");
                            //exit在任何位置都可以直接退出一个进程
                            exit(1);    //至此之后，代码不再使用return -1，而是返回错误信息。
                        }
                        if(pid == 0)    //子进程的代码区
                        {
                            int i = 0;
                            for(i = 0;i<5;i++)
                            {
                                printf("this is son process\n");
                                sleep(1);
                            }
                            exit(0);
                        }
                        else    //父进程的代码区
                        {
                            while(1)
                            {
                                printf("this is father process\n");
                                sleep(1);
                            }
                        }

                        // 执行结果：  打破了父子进程交替运行的规则,子进程执行完成之后,才执行父进程
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // this is son process
                        // this is son process
                        // this is son process
                        // this is son process
                        // this is son process
                        // this is father process
                        // this is father process
                        // this is father process
                        // this is father process
                        // this is father process
                        // this is father process

                        return 0;
                    }

            3.2.7.2 子进程和父进程共享同一块（地址）空间

            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>

                    int a = 10;
                    int main(int argc, char const *argv[])
                    {
                        pid_t pid;
                        int b = 9;

                        //使用vfork创建完子进程
                        //在子进程执行 exit 或者 exec 之前，父子进程共有同一块地址空间。
                        pid = vfork();

                        if(pid < 0)
                        {
                            perror("fail to vfork");
                            exit(1);
                        }

                        if(pid == 0)
                        {
                            a++;
                            b++;
                            printf("in son process a = %d, b = %d\n",a,b);
                            exit(0);
                        }
                        else
                        {
                            printf("in father process a = %d,b = %d\n",a,b);
                        }

                        //执行结果：
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // in son process a = 11, b = 10
                        // in father process a = 11,b = 10

                        return 0;
                    }


        3.2.8 进程的替换
        (可以理解为：在一个进程里面 执行 另外一个进程，这两个进程对应的进程号是相同的，但这两个进程对应的栈区、堆区等会发生改变)
        （进程替换可以做很多事情，比如：在一个程序里面执行一个命令(如ls -l),在这之前是没有办法的（因为ls是命令，与这些没有关系），但有了exec函数族，就可以实现这一点）

            进程的替换
            exec 函数族，是由六个exec 函数组成的。
                1、exec 函数族提供了六种在进程中启动另一个程序的方法。
                2、exec 函数族可以根据指定的文件名或目录名找到可执行文件。
                3、调用 exec 函数的进程并不创建新的进程，故调用 cxec 前后，进程的进程号并不会改变，其执行的程序完全由新的程序替换，而新程序则从其 main 函数开始执行。

          * exec 函数族 取代调用进程的 数据段、代码段 和 堆 栈段。但进程号不变

            原进程   ——> exec  ——>   新进程
            栈区                      栈区
            堆区                      堆区
            BSS区                     BSS区
            数据区                    数据区
            代码区                    代码区

            exec 函数族
            #include <unistd.h>

            int execl(const char *pathname,const char *arg0,...,NULL);

            int execlp(const char *pathname,const char *arg0,...,NULL);

            int execle(const char *pathname,const char *arg0,...,NULL,char *const envp[]);


            int execv(const char *pathname,const char *argv[]);

            int execvp(const char *filename,char *const argv[]);

            int execve(const char *pathname,char *const argv[],char *const envp[]);

            六个 exec 函数中只有 execve (最后一个)是真正意义的系统调用(内核提供的接口)，其它函数都是在此基础上经过封装的库函数。

            exec + l/v + p/e : +参数列表/数组   + PATH 环境变量指定的目录/存有环境变量字符串地址的指针数组的地址

            l(list):
                参数地址列表，以空指针结尾。

                参数地址列表
                    char *arg0,char *arg1,...,char *argn, NULL
            v(vector):
                存有各参数地址的指针数组的地址。
                使用时 先构造一个指针数组 ，指针数组存各参数的地址，然后将该指针数组地址作为函数的参数。


            p(path)
                按 PATH 环境变量指定的目录搜索可执行文件。
                以p结尾的 exec 函数取文件名做为参数。当指定filename 作为参数时，若 filename 中包含/，则将其视为
                路径名，并直接到指定的路径中执行程序。

            e(environment):
                存有环境变量字符串地址的指针数组的地址。execle和execve,改变的是 exec 启动的程序的环境变量(新的
                环境变量完全由envirnoment指定），其他四个函数启动的程序则使用默认系统环境变量。

            注意:
                exec 函数族 与 一般的函数 不同，exec 函数族中的函数执行成功后不会返回。只有调用失败了，它们才会返回-1，失败后从原程序的调用点接着往下执行。
                在平时的编程中，如果用到了 exec 函数族，一定要记得加错误判断语句。

        例：

                #include <stdio.h>
                #include <stdlib.h>
                #include <unistd.h>
                #include <sys/types.h>
                #include <sys/wait.h>

                int main(int argc, char const *argv[])
                {
                    pid_t pid;
                    if((pid = fork()) < 0)
                    {
                        perror("fail to fork");
                        exit(1);
                    }
                    else if(pid > 0) //父进程
                    {
                        printf("This is parent process\n");

                        wait(NULL);
                        printf("The child process has quited\n");
                    }
                    else //子进程
                    {
                        printf("This is child process\n");

                        //调用exec函数族中的函数，执行其他命令或者程序
                        //查看命令的路径：whereis 命令或者which 命令

                        //***************exec函数族调用shell命令******************
                        //不带p的函数，命令的路径一定要用绝对路径
                #if 0

                        // if(execl("ls", "ls", "-l", NULL) == -1)
                        // {
                        //     perror("fail to execl");
                        //     exit(1);
                        // }
                        //执行结果：报错：fail to execl: No such file or directory

                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // This is parent process
                        // This is child process
                        // fail to execl: No such file or directory
                        // The child process has quited

                        //那么如何查询ls的绝对路径？
                        //使用 whereis ls
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ whereis ls
                        // ls: /usr/bin/ls      /usr/share/man/man1/ls.1.gz

                        //所以 ls路径为：/usr/bin/ls

                        if(execl("/usr/bin/ls", "ls", "-l", NULL) == -1)
                        {
                            perror("fail to execl");
                            exit(1);
                        }
                        //执行结果：

                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // This is child process
                        // This is parent process
                        // 总用量 76
                        // -rw-rw-r-- 1 qinmei qinmei  1387 1月   4 16:26 10_vfork_1.c
                        // -rw-rw-r-- 1 qinmei qinmei   791 1月   4 17:09 11_vfork_2.c
                        // -rw-rw-r-- 1 qinmei qinmei  3039 1月   4 17:23 12_exec.c
                        // -rw-rw-r-- 1 qinmei qinmei   624 1月   3 17:04 1_pid.c
                        // -rw-rw-r-- 1 qinmei qinmei  4395 1月   4 12:22 2_fork_1.c
                        // -rw-rw-r-- 1 qinmei qinmei  1739 1月   4 12:43 3_fork_2.c
                        // -rw-rw-r-- 1 qinmei qinmei  2463 1月   4 13:43 4_fork_3.c
                        // -rw-rw-r-- 1 qinmei qinmei   457 1月   4 14:06 5_sleep.c
                        // -rw-rw-r-- 1 qinmei qinmei  2865 1月   4 14:53 6_waitpid.c
                        // -rw-rw-r-- 1 qinmei qinmei   677 1月   4 15:22 7_waitpid.c
                        // -rw-rw-r-- 1 qinmei qinmei  1254 1月   4 15:43 8_exit.c
                        // -rw-rw-r-- 1 qinmei qinmei   923 1月   4 16:04 9_atexit.c
                        // -rwxrwxr-x 1 qinmei qinmei 16912 1月   4 17:23 a.out
                        // -rw-rw-r-- 1 qinmei qinmei    47 1月   4 12:51 file.txt
                        // The child process has quited

                        //注意：exec 函数族 取代调用进程的数据段、代码段 和 堆栈段，因此，结束后不会打印main函数最后的hello world

                #endif


                        //带p的函数，第一个参数既可以是相对路径，也可以是绝对路径
                #if 0
                        // if(execlp("/usr/bin/ls", "ls", "-l", NULL) == -1)
                        // {
                        //     perror("fail to execlp");
                        //     exit(1);
                        // }
                        //执行结果：可以执行，结果同上，故execlp 可以跟 绝对路径

                        if(execlp("ls", "ls", "-l", NULL) == -1)
                        {
                            perror("fail to execlp");
                            exit(1);
                        }
                        //执行结果：可以执行，结果同上，故execlp 也可以跟 相对路径

                #endif

                        //带v的函数需要使用指针数组来传递
                #if 0
                        //定义一个指针数组 用于保存参数列表（ls -l NULL）
                        char *str[] = {"ls", "-l", NULL};
                        //第二个参数变成了str,第一个参数传绝对/相对路径，看有没有p
                        if(execv("/bin/ls", str) == -1)
                        {
                            perror("fail to execv");
                            exit(1);
                        }
                #endif


                        //***************exec函数族调用 可执行文件******************
                #if 0
                        //带p的执行相对路径
                        if(execlp("./hello", "./hello", NULL) == -1)
                        {
                            perror("fail to execlp");
                            exit(1);
                        }
                        //执行结果：
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ touch hello.c
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ vim hello.c
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ cat hello.c
                        // #include <stdio.h>
                        //
                        // int main(int argc,const char *argv[])
                        // {
                        // 	printf("***************************\n");
                        // 	printf("正在执行hello.c的可执行文件\n");
                        // 	printf("---------------------------\n");
                        //
                        // 	return 0;
                        // }
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ gcc hello.c  -o hello
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ls
                        // 10_vfork_1.c  1_pid.c     4_fork_3.c   7_waitpid.c  a.out     hello.c
                        // 11_vfork_2.c  2_fork_1.c  5_sleep.c    8_exit.c     file.txt
                        // 12_exec.c     3_fork_2.c  6_waitpid.c  9_atexit.c   hello
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./hello
                        // ***************************
                        // 正在执行hello.c的可执行文件
                        // ---------------------------
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ gcc 12_exec.c
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // This is parent process
                        // This is child process
                        // ***************************
                        // 正在执行hello.c的可执行文件
                        // ---------------------------
                        // The child process has quited
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$
                #endif

                #if 0
                        //不带p的执行相对路径
                        if(execl("./hello", "./hello", NULL) == -1)
                        {
                            perror("fail to execl");
                            exit(1);
                        }
                        //执行结果：也可以执行
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ ./a.out
                        // This is parent process
                        // This is child process
                        // ***************************
                        // 正在执行hello.c的可执行文件
                        // ---------------------------
                        // The child process has quited

                #endif


                        //***************exec函数族调用 shell脚本 ******************
                #if 1
                        //相对路径执行。
                        if(execlp("./myshell.sh", "./myshell.sh", NULL) == -1)
                        {
                            perror("fail to execl");
                            exit(1);
                        }
                #endif
                        //exec函数族取代调用进程的数据段、代码段和堆栈段
                        // #所以当exec函数执行完毕后，当前进程就结束了，所以原本进程中的代码不会再执行
                        printf("hello world\n");
                    }

                    return 0;
                }

            一个进程调用 exec 后，除了进程 ID，进程还保留了下列特征不变:(了解)
                父进程号
                进程组号
                控制终端
                根目录
                当前工作目录
                进程信号屏蔽集
                未处理信号
                ...



*/





//                                                    -无名管道
//                            |——  Unix进程间通信方式 {  -有名管道
//            同一主机进程间通信{|                        -信号*
//                            |
//                            |                             |消息队列
//                            |——System V进程间通信方式 —— }{ |共享内存*
//                            |——POSIX进程间通信方式    ——    |信号量

//                            不同主机（网络）进程间通信       ——————————————    Socket

//第四章：信号
/*
    4.1进程间通信概述(进程间通信方式)
        （通信：本质上来说就是 读写操作。（本章主要介绍，多个进程之间，到底怎样进行通信。）
        信号就是进程间通信的一种。）

        进程间通信(IPC:Inter Processes Communication)
                进程 是一个 独立的 资源分配单元，不同进程(这里所说的 进程 通常指的是 用户进程)之间的资源是独立的，没有关联，
              不能在一个进程中直接访问另一个进程的资源(例如打开的文件描述符)。
                进程不是孤立的，不同的进程需要进行信息的交互和状态的传递等，因此需要进程间

        进程间通信功能:
            数据传输:一个进程 需要 将它的数据 发送给另一个进程。
            资源共享:多个进程之间共享同样的资源。
            通知事件:一个进程 需要向 另一个或一组进程 发送消息，通知它们发生了某种事件。
            进程控制:有些进程希望完全控制另一个进程的执行(如Debug进程)，此时控制进程希望拦截另一个进程的所有操作，并能够及时知道它的状态改变。

        Linux进程间通信（IPC）由以下几个部分发展而来
            最初的 UNIX    进程间通信
            SYSTEM V      进程间通信
            POSIX         进程间通信(POSIX:Portable Operating System interface 可移植操作系统接口)
            Socket        进程间通信

        Linux把优势都继承了下来并形成了自己的IPC

            Linux操作系统支持的主要进程间通信的通信机制：
           * 见图：
                                                    -无名管道
                            |——  Unix进程间通信方式 {  -有名管道
            同一主机进程间通信{|                        -信号*
                            |
                            |                             |消息队列
                            |——System V进程间通信方式 —— }{ |共享内存*
                            |——POSIX进程间通信方式    ——    |信号量

            不同主机（网络）进程间通信       ——————————————    Socket

        进程间通信的实质：
            系统只要创建一个进程，就会给当前进程分配4G的虚拟内存（32位操作系统）。虚拟内存不是常说的内存条的空间，内存条的空间称为物理内存，虚拟内存和物理内存之间存在映射关系

            4G的虚拟内存 又分为：3G的用户空间（0~3G） 和 1G(3~4G)的内核空间。
                * 用户空间：
                    用户空间是进程私有的，每一个进程的用户空间只能自己访问和使用。我们之前说的栈区、堆区、数据区、代码区等都是用户空间的区域。
                    （这就是为什么说fork创建的子进程与父进程一点关系都没有，原因就是fork创建子进程之后，就开辟了3G的用户空间，这3G用户空间只属于子进程，与父进程没有任何关系）
                * 内核空间：
                    内核空间是所有进程所共有的，故，绝大多数 进程间通信方式 本质 就是内核空间的操作。（只是绝大多数，像共享内存等就不是）

            * 特殊的进程间通信方式(对于上面的7种通信方式)：
                    socket通信：可以实现不同 主机间通信，其它6个只能在一台主机的 多个进程间通信。
                    信号通信   ：是唯一的一种 异步通信机制（就是类似于硬件 中断 的 软件形式）。
                    共享内存   ：是所有进程间通信方式中效率最高的，他是 直接对物理内存进程操作。（大多数进程通信方式都是对内核空间操作，唯独共享内存是直接对物理内存进程操作）


    4.2 信号
            4.2.1.1 概述
                信号 是 软件中断，它是在软件层次上 对 中断机制 的一种模拟。
                    信号 可以导致 一个正在运行的进程 被 另一个正在运行的异步进程 中断，转而处理某一个突发事件。

                信号 是一种 异步通信方式。
                    进程不必等待信号的到达，进程也不知道信号什么时候到达。

                信号 可以 直接进行 用户空间进程 和 内核空间进程 的交互，内核进程 可以利用它来 通知 用户空间进程 发生了哪些系统事件。


                每个信号的名字 都以字符 SIG 开头。
                每个信号 和 一个数字编码相对应，在头文件signum.h中，这些信号都被定义为正整数。
                信号名定义路径:
                        /usr/include/i386-linux-gnwbits/signum.h   (ubuntu12.04版本)
                        /usr/include/x86_64-linux-gnu/bits/signum.h (我的路径下)

                在 Linux下，要想查看这些信号和编码的对应关系，可使用命令:kill -l
                    例：
                        qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$ kill -l
                         1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
                         6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
                        11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
                        16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
                        21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
                        26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
                        31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
                        38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
                        43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
                        48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
                        53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
                        58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
                        63) SIGRTMAX-1	64) SIGRTMAX
                        qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/3_process$
                    其打印的就是所有的信号。
                    信号是由当前系统已经定义好的一些标识，每一个标识都会在特定的场合下使用。并且都会对进程有一定的影响，当信号产生时，会使当前信号做出相应的操作。

                    这些信号都是已经定义好的，我们不能再自己创造，直接使用即可。

            4.2.1.2 产生信号的方式
                以下条件可以产生一个信号
                    1、当用户按某些终端键时，将产生信号。
                        例如:
                            终端上按“Ctrl+c”组合键通常产生中断信号 SIGINT、
                            终端上按"Ctrl+\"键通常产生中断信号 SIGQUIT、
                            终端上按"Ctrl+z"键通常产生中断信号 SIGSTOP。
                    2、硬件异常将产生信号。
                        除数为 0、无效的内存访问等。这些情况通常由硬件检测到，并通知内核,然后内核产生适当的信号发送给相应的进程。
                    3、软件异常将产生信号。
                        当检测到某种软件条件已发生，并将其通知有关进程时，产生信号。
                    4、调用 kill 函数将发送信号。(Kill 向指定的进程发送信号)
                        注意: 接收信号进程 和 发送信号进程 的所有者 必须相同， 或 发送信号进程的所有者 必须是 超级用户。
                    5、运行 kill 命令将发送信号。
                        此程序实际上是使用 kill函数来发送信号。也常用此命令终止一个失控的后台进程。


            4.2.1.3 信号的默认（缺省）处理方式
                当进程中产生了一个信号，就会让当前进程做出一定的反应，默认处理进程的方式如下：
                    1. 终止进程：当信号产生后，当前进程就会立即结束。（如：ctrl+c）
                    2. 缺省处理：当信号产生后，当前进程不做任何处理。（忽略信号）
                    3. 停止进程：当信号产生后，使得当前进程停止。
                    4. 让停止的进程回复运行：当信号产生后，停止的进程会回复执行（后台进程）

                    注意：每一个信号只有一个默认的处理方式。


            4.2.1.4 进程接收到信号后的处理方式：
                一个进程收到一个信号的时候，可以用如下方法进行处理:
                    1、执行系统默认动作
                        对大多数信号来说，系统默认动作是用来终止该进程。
                    2、忽略此信号
                        接收到此信号后没有任何动作。
                    3、执行自定义信号处理函数
                        用用户定义的信号处理函数处理该信号。
                    注意:
                    * SIGKILL 和 SIGSTOP 不能更改信号的处理方式，因为它们向用户提供了一种使进程终止的可靠方法。
                    （即: SIGKILL 和 SIGSTOP 这两个信号只能以默认的处理方式执行，不能忽略也不能自定义。）

            4.2.1.5 常见的信号
                信号      值       性质                                                                          默认处理方式
             SIGKILL    9     当产生这个信号后，当前进程会退出，不能被缺省和捕捉                                        退出进程
             SIGSTOP    19    当产生这个信号后，当前进程会停止，不能被缺省和捕捉                                        停止进程
             SIGINT     2     键盘输入 ctrl + c时产生信号                                                           退出进程
             SIGQUIT    3     键盘输入 ctrl + \时产生信号                                                           退出进程
             SIGTSTP    20    键盘输入 ctrl + z时产生信号                                                           停止进程
             SIGCONT    18    当产生当前信号后，当前停止的进程会恢复运行                                                停止的进程恢复运行
             SIGALRM    14    当调用alarm函数 设置的时间到达时会产生当前信号                                            退出进程
             SIGPIPE    13    当管道破裂时，会产生当前信号                                                            退出进程
             SIGABRT    6     当调用abort函数时会产生当前信号                                                         退出进程
             SIGCHLD    17    当使用fork创建一个子进程时，若子进程状态改变（退出），会产生当前信号                          缺省
             SIGUSR1    10    用户自定义信号，不会自动产生，只能使用kill函数或命令给指定的进程发送当前信号                   缺省
             SIGUSR2    12    用户自定义信号，不会自动产生，只能使用kill函数或命令给指定的进程发送当前信号                   缺省

        4.2.2 信号的基本操作

            4.2.2.1 kill函数

                #include <sys/types.h>
                #include <signal.h>

                int kill(pid_t pid, int signum);
              * 功能:
                    给指定进程发送信号
                参数:
                    pid:详见下页
                    signum:信号的编号
                返回值:
                    成功返回 0，失败返回 -1。

                pid的取值有4种情况:
                    pid>0:将信号传送给进程 ID为pid的进程
                    pid=0:将信号传送给当前进程所在进程组中的所有进程
                    pid=-1:将信号传送给系统内所有的进程。
                    pid<-1:将信号传给指定进程组的所有进程。这个进程组号等于 pid,的绝对值。

                例1：kill作为函数：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <sys/types.h>
                        #include <signal.h>

                        int main(int argc, char const *argv[])
                        {
                            pid_t pid;

                            pid = fork();
                            if(pid < 0)
                            {
                                perror("fail to fork");
                                exit(1);
                            }
                            else if(pid > 0)    //父进程的代码区
                            {
                                while(1)
                                {
                                    printf("This is parent process\n");

                                    sleep(1);
                                }
                            }
                            else            //子进程的代码区
                            {
                                printf("This is son process\n");

                                //子进程 在 3s之后让父进程退出。
                                sleep(3);

                                //使用kill给父进程发送信号，然后父进程接收到信号后直接退出即可。
                                //第一个参数传-1则所有进程停止。
                                kill(getppid(),SIGINT);    //第一个参数传父进程的进程号，第二个参数随便选一个默认处理为退出进程的常用信号即可
                            }
                            return 0;
                        }

                例2 kill作为命令：
                1.当运行此循环打印代码时
                2.要想关闭他，则另开一个终端，
                        输入 ps ajx 查询当前进程得进程号
                        使用man kill可以查看kill命令的使用方法：kill [options] <pid> [...]
                        使用kill -l 查询信号
                3.kill -9 11503     :-9表示 查询到的SIGKILL是第9个信号; 11503是查询到的 a.out的进程号。
                结果为：
//                    ...
//                    hello world
//                    hello world
//                    hello world
//                    hello world
//                    已杀死

                    #include <stdio.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        while(1)
                        {
                            printf("hello world\n");

                            sleep(1);
                        }

                        return 0;
                    }


            4.2.2.2 alarm函数
                #inelude <unistd.h>

                unsigned int alarm(unsigned int seconds);
                功能:
                    在 seconds 秒后,向调用进程发送一个 SIGALRM 信号,SIGALRM 信号的默认动作是终止调用 alarm 函数的进程
                返回值:
                    若以前没有设置过定时器，或设置的定时器已超时，返回0:否则返回定时器剩氽的秒数，并重新设定定时器。

            例：
                    #include <stdio.h>
                    #include <unistd.h>

                    // int main(int argc, char const *argv[])
                    // {
                    //     //当执行alarm之后，代码会接着往下执行，当设定的时间到后，会产生SIGALRM信号
                    //     alarm(5);
                    //     //如果这里用的是sleep(5),会先睡眠5s,再往下执行
                    //     //但，如果是alarm（一个闹钟）,则会继续运行，只是到达时间之后会发出信号。

                    //     while(1)
                    //     {
                    //         printf("hello world\n");

                    //         sleep(1);
                    //     }

                    //     //执行结果：
                    //     // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/4_signal$ ./a.out
                    //     // hello world
                    //     // hello world
                    //     // hello world
                    //     // hello world
                    //     // hello world
                    //     // 闹钟

                    //     return 0;
                    // }



                    int main(int argc, char const *argv[])
                    {
                        unsigned int sec;
                        sec = alarm(5);
                        printf("sec = %d\n",sec);

                        sleep(3);
                        sec = alarm(6);
                        printf("sec = %d\n",sec);

                        while(1)
                        {
                            printf("hello world\n");

                            sleep(1);
                        }

                        //执行结果：9秒才执行结束
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/4_signal$ ./a.out
                        // sec = 0
                        // sec = 2
                        // hello world
                        // hello world
                        // hello world
                        // hello world
                        // hello world
                        // hello world
                        // 闹钟

                        //总结：
                        //1.为什么alarm(5)不执行？(sleep(3) + alarm(6) = 9秒，因此程序共运行9秒)
                        //      如果一个程序中出现多个alarm闹钟，第二个（alarm(6))如果没有到达指定的时间 第一个(alarm(5))就已经到了，则第一个闹钟的时间清除，按照第二个alarm的时间继续向下运行。
                        //2.为什么总共是运行9秒？
                        //      因为第一个alarm会被忽略，紧接执行了sleep(3),然后才开始执行第二个alarm(6),6秒之后闹钟,因此： sleep的3秒 + alarm的6秒 = 9秒
                        //3.为什么返回值是2？
                        //      如果alarm之前没有设置其他闹钟，则返回0，如果之前设置了，则返回之前剩余的秒数，
                        //     如:由于第一个sleep(5)被忽略了,接着sleep(3)，这里本来应该在第5秒时候闹钟的，故第一个alarm的剩余时间为 5-3 = 2

                        return 0;
                    }


            4.2.2.3 raise函数
                #include <signal.h>
                int raise(int signum);
                功能:
                    给调用进程本身发送一个信号(自己给自己发信号)
                参数:
                    signum:信号的编号。
                返回值:
                    成功返回 0，失败返回 -1。

                raise(sig)  <==> kill(getpid(),sig)

            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <signal.h>
                    #include <unistd.h>
                    #include <sys/types.h>

                    int main(int argc, char const *argv[])
                    {
                        int num = 0;
                        while(1)
                        {
                            printf("hello world\n");

                            sleep(1);
                            num++;
                            //当循环执行5s后，进程结束
                            if(num == 5)
                            {
                                //使用raise给当前进程本身发送信号
                                // raise(SIGINT);
                                // raise(SIGALRM);

                                kill(getpid(),SIGINT);
                            }
                        }

                        return 0;
                    }

            4.2.2.4 abort函数
                #include <stdlib.h>
                void abort(void);
                功能:
                    向进程发送一个 SIGABRT 信号，默认情况下进程会退出。
              * 注意:
                    即使 SIGABRT 信号被加入阻塞集，一旦进程调用了 abort函数，进程也还是会被终止，且在终止前会刷新缓冲区，关文件描述符。

                例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <signal.h>
                    #include <unistd.h>
                    #include <sys/types.h>

                    int main(int argc, char const *argv[])
                    {
                        int num = 0;

                        while(1)
                        {
                            printf("hello world\n");
                            sleep(1);
                            num++;

                            //当循环执行5秒后，进程退出
                            if(num == 5)
                            {
                                abort();
                            }
                        }
                        //执行结果：
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/4_signal$ ./a.out
                        // hello world
                        // hello world
                        // hello world
                        // hello world
                        // hello world
                        // 已放弃 (核心已转储)
                        // qinmei@qinmei-virtual-mac

                        return 0;
                    }

            4.2.2.5 pause函数
                #include <unistd.h>
                int pause(void);
                功能:
                    将调用进程 挂起 直至捕捉到信号为止。这个函数通常用于判断信号是否己到。
                返回值：
                    直到捕获到信号，pause函数才返回-1，且errno被设置成EINTR

            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <signal.h>
                    #include <sys/types.h>

                    int main(int argc, char *argv[])
                    {
                        pid_t pid;

                        pid = fork();
                        if(pid < 0)
                        {
                            perror("fail to fork");
                            exit(1);
                        }
                        else if(pid > 0) //父进程的代码区
                        {
                            printf("This is parent peocess\n");

                            //使用pause阻塞等待捕捉信号
                            //3秒之前，父进程一直在这里阻塞等待，3秒之后，由于子进程给父进程发了SIGINT信号，此时父进程捕捉到该信号，就执行该信号的的默认处理方式。
                            pause();
                        }
                        else //子进程的代码区
                        {
                            printf("This is son process\n");

                            sleep(3);

                            //3秒之后，给父进程发送SIGINT
                            kill(getppid(), SIGINT);
                        }

                        return 0;
                    }


            4.2.2.6 signal函数(信号中最重要的函数)

                进程接收到信号后的处理方式:(除了第一种，剩下两种都需要signal改变信号的处理方式)
                    1、执行系统默认动作
                    2、忽略此信号
                    3、执行自定义信号处理函数

            程序中可用函数 signalO)改变信号的处理方式。

            头文件：
                #include <signal.h>

            typedef void (*sighandler_t)(int);  //对void 取别名，取成函数指针的形式
            sighandler_t signal(int signum, sighandler_t handler);  //返回值：表示其返回值也是函数指针，参数1：信号的编号，参数2：函数指针，指相应的处理方式。

            实际函数原型：
                    void (*signal(int sig, void (*func)(int) ))(int);

            功能:
                注册信号处理函数(不可用于 SIGKILL、SIGSTOP 信号（这两个信号只能以默认方式处理，既不能被忽略，也不能被捕捉，即自定义）)，即确定收到信号后处理函数的入口地址
            参数:
                signum:信号编号

                handler 的取值:
                    SIG_IGN:忽略该信号
                    SIG_DFL:执行系统默认动作
                    函数处理函数名：自定义信号处理函数
            返回值：
                成功:(返回函数指针)返回函数地址，该地址为此信号上一次注册的信号处理函数的地址。
                失败:返回 SIG_ERR


                4.2.2.6.1 signal函数的使用
                例：
                        #include <stdio.h>
                        #include <signal.h>
                        #include <unistd.h>
                        #include <stdlib.h>

                        void handler(int sig);

                        int main(int argc, char const *argv[])
                        {
                            //以默认的方式处理信号
                        #if 0
                            //使用过程：终端运行代码后，ctrl+c ,ctrl+\产生信号，执行结果都是退出
                            //这里signal主要起标识作用，只要产生了信号，则以参数2的方式处理。
                            if(signal(SIGINT, SIG_DFL) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                            if(signal(SIGQUIT, SIG_DFL) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                            if(signal(SIGTSTP, SIG_DFL) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                        #endif

                            //以忽略的方式来处理信号
                        #if 0
                            //将参数2换成SIG_IGN：忽略。
                            //即：当接收信号的时候，即使有默认处理方式，也执行忽略处理方式。
                            //执行结果：即使按ctrl +c 、ctrl + \ 都没有停止进程
                            //此时想要退出进程 可以另开终端，ps ajx查询进程号，再使用kill命令退出(kill -9 进程号)。
                            if(signal(SIGINT, SIG_IGN) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                            if(signal(SIGQUIT, SIG_IGN) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                            if(signal(SIGTSTP, SIG_IGN) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }

                            //注意：SIGKILL和SIGSTOP这两个信号只能以默认的方式处理，不能忽略或者捕捉
                            // if(signal(SIGKILL, SIG_IGN) == SIG_ERR)
                            // {
                            //     perror("fail to signal");
                            //     exit(1);
                            // }

                        #endif

                            //以用户自定义方式处理信号
                        #if 1
                            //执行结果：按一次strl + c、ctrl + \、strl + z执行一次handler里面对应的代码
                            if(signal(SIGINT, handler) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                            if(signal(SIGQUIT, handler) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                            if(signal(SIGTSTP, handler) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                        #endif

                            while(1)
                            {
                                printf("hello world\n");
                                sleep(1);
                            }

                            return 0;
                        }


                        void handler(int sig)
                        {
                            if(sig == SIGINT)
                            {
                                printf("SIGINT正在处理\n");
                            }

                            if(sig == SIGQUIT)
                            {
                                printf("SIGQUIT正在处理\n");
                            }

                            if(sig == SIGTSTP)
                            {
                                printf("SIGTSTP正在处理\n");
                            }
                        }


                4.2.2.6.2 signal函数的返回值
                    例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <signal.h>
                        #include <unistd.h>

                        void *ret_handler;

                        void handler(int sig)
                        {
                            printf("**********************\n");
                            printf("nihao beijing\n");
                            printf("welcome to 1000phone\n");
                            printf("**********************\n");

                            //4.当进到函数里面时，这里signal再次冲定义，而处理方式变成了ret_handler
                            //因此，自定义成了：以默认处理方式处理SIGINT信号。
                            if(signal(SIGINT, ret_handler) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }
                        }


                        int main(int argc, char const *argv[])
                        {
                            //1.首次调用signal,当识别到SIGINT(ctrl+c)会以自定义类型（自定义函数）的方式处理，即:调用handler函数
                            //2.并且将函数的返回值存在 ret_handler中。
                            //3.而返回值存的是:当前信号的上一次的执行方式。第一次自定义之前的方式 则是 默认处理方式，因此 ret_handler中 存放的是 默认处理方式
                            if((ret_handler = signal(SIGINT, handler)) == SIG_ERR)
                            {
                                perror("fail to signal");
                                exit(1);
                            }

                            while(1)
                            {
                                printf("hello world\n");
                                sleep(1);
                            }

                            //执行结果：
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/4_signal$ ./a.out
                            // hello world
                            // hello world
                            // ^C**********************
                            // nihao beijing
                            // welcome to 1000phone
                            // **********************
                            // hello world
                            // hello world
                            // ^C
                            // qinmei@qinmei
                            return 0;
                        }


            4.2.3 可重入函数
                可重入函数 是指 函数 可以由多个任务 并发使用，而不必担心数据错误。
                （可重入函数就是可以被中断的函数，当前函数可以在任何时刻中断他，并执行另一块代码，当执行完毕后，回到原本的代码还可以正常继续运行（当前函数正在执行，突然来了一个信号，要用自定义函数处理，那么当执行完自定义处理函数之后，还可以回到最初的函数继续执行））
                （不可重入函数 就是打断后就不能回到原来的函数执行了，例如:sleep()函数,睡眠10秒，第5秒中断，回来后不能接着第5秒继续睡眠）
                （为什么需要分重入和不可重入呢？主要指的是：这个函数所使用的资源 是否有如：全局变量或中断向量表，如果内部有这些那它基本上就不是可重入函数）

                编写可重入函数:（如果是可重入函数，其只能在栈区开辟空间并且使用，也就意味着他只能使用局部变量）
                    1、不使用(返回)静态的数据、全局变量(除非用信号量互斥)。
                    2、不调用动态内存分配、释放的函数。
                    3、不调用任何不可重入的函数(如标准 I/O 函数)。（一般标准IO都是不可重入的函数）
              * 注:
                    即使 信号处理函数使用的 都是 可重入函数(常见的可重入函数),也要注意进入处理函数时,首先要保存 errno 的值，结束时，再恢复原值。因为，信号处理过程中，errno 值随时可能被改变。

                常见的可重入函数列表:（太多了见WPS）
                案例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>
                    #include <signal.h>

                    //次函数可测试，如果处理函数执行没完时，alarm却已经到时间了 会发生什么
                    //结果：不论信号产生后执行的处理函数 处理完了没有，alarm到时间就会产生信号。
                    // void handler(int sig)
                    // {
                    //     printf("SIGINT\n");
                    //     while(1)
                    //     {
                    //         printf("hello world\n");

                    //     }
                    // }

                    void handler(int sig)
                    {
                        printf("SIGINT\n");
                    }

                    int main(int argc, char *argv[])
                    {
                        signal(SIGINT, handler);    //使用signal改变了SIGINT的处理方式

                        //案例1：
                    #if 0
                        //* sleep本身是一个可重入函数，但是当执行信号处理函数之后，不会回到原本的位置继续睡眠
                        // sleep(10);
                        //单使用sleep执行结果：本来应该睡眠10秒的，由于产生了信号，因此sleep被打断了，即使执行完了自定义处理方式，也不能再回到sleep函数中继续睡10秒，而是直接循环打印。

                        //alarm函数是一个可重入函数，当他执行时，如果有信号产生并执行信号处理函数，执行完毕后，会继续运行
                        alarm(3);
                        //执行结果：单使用alarm时，即使有信号产生，在执行完后依然可以回到alarm函数中。
                        while(1)
                        {
                            printf("hello world\n");
                            sleep(1);
                        }
                    #endif

                        //案例2：
                    #if 1
                        char buf[32] = "";

                        //read也是一个可重入函数，在等待终端输入时，如果产生信号并执行信号处理函数，信号处理
                        //函数执行完毕后，可以继续输入数据，read可以读取到 信号处理函数之后的 数据
                        if(read(0, buf, 20) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }

                        printf("buf = [%s]\n", buf);
                    #endif
                        return 0;
                    }


            4.2.4 信号集
            信号集概述
                一个用户进程 常常需要对 多个信号 做出处理。为了方便 对多个信号进行处理，在Linux 系统中引入了信号集。
                信号集 是用来表示 多个信号的 数据类型。

            信号集数据类型
                sigset_t
            定义路径:
                /usr/include/i386-1inux-gnu/bits/sigset.h
                /usr/include/x86_64-linux-gnu/bits/types/sigset.h   我的路径
                (sigset.h 是一个早期的 POSIX 标准定义的信号集操作的头文件，在较新的 Linux 系统中已经被更现代的 <signal.h> 所取代。)
            信号集相关的操作主要有如下几个函数:
                sigemptyset:初始化一个空的信号集
                sigfillset：初始化一个满的信号集
                sigismember：判断当前信号集里面是否哪一个有信号
                sigaddset：把某一个信号添加到信号集当中
                sigdelset：把某一个信号从信号集中删除。

                4.2.4.1 sigemptyset函数
                    初始化一个空的信号集
                头文件：
                    #include<signal.h>

                    int sigemptyset(sigset_t *set):
                    功能:
                        初始化由 set 指向的信号集，清除其中所有的信号 即初始化一个空信号集。
                    参数:
                        set:信号集标识的地址，以后操作此信号集，对 set 进行操作就可以了
                    返回值:
                        成功返回 0，
                        失败返回 -1.


                4.2.4.2 sigfillset 函数
                    初始化一个满的信号集
                头文件：
                    #include<signal.h>

                int sigfillset(sigset_t *set):
                功能:
                    初始化信号集合 set，将 信号集合 设置为 所有信号的集合。
                参数:
                    信号集标识的地址，以后操作此信号集，对 set进行操作就可以了。
                返回值:
                    成功返回 0，
                    失败返回-1.


                4.2.4.3 sigismember 函数
                判断某个集合中是否有某个信号
                头文件：
                    #include<signal.h>
                int sigismember(const sigset t *set,int signum)
                功能:
                    査询 sigmum,标识的信号是否在信号集合 set 之中,
                参数:
                    set:信号集标识符号的地址，
                    signum:信号的编号。
                返回值:
                    在信号集中返回 1，不在信号集中返回 0
                    错误，返回 -1


                4.2.4.4 sigaddset 函数
                向某个集合中添加一个信号
                头文件：
                    #include<signal. h>
                int sigaddset(sigset_t *set, int signum)
                功能:
                    将信号 signum 加入到信号集合 set 之中。
                参数:
                    set:信号集标识的地址。
                    signum:信号的编号。
                返回值:
                    成功返回 0，失败返回 -1。


                4.2.4.5 sigdelset 函数
                从某个信号集中删除一个信号
                头文件：
                    #include<signal.h>

                int sigdelset(sigset_t *set, int signum)
                功能:
                    将 signum 所标识的信号从信号集合 set 中删除
                参数:
                    set:信号集标识的地址，
                    signum:信号的编号、
                返回值:
                    成功:返回 0
                    失败:返回 -1I

            例：
                #include <signal.h>
                #include <stdio.h>

                int main(int argc, char *argv[])
                {
                    //创建一个信号集,信号集类型为sigset_t该类型在<bits/types/sigset_t.h>中定义，头文件被#include <signal.h>添加
                    sigset_t set;
                    int ret = 0;

                    //初始化一个空的信号集
                    sigemptyset(&set);

                    //判断SIGINT信号是否在信号集中
                    ret = sigismember(&set, SIGINT);
                    if(ret == 0)    //返回0 不在；1 在；-1 错误
                    {
                        printf("SIGINT is not a member of sigprocmask \nret = %d\n", ret);
                    }

                    //将指定的信号添加到信号集中
                    sigaddset(&set, SIGINT);
                    sigaddset(&set, SIGQUIT);

                    //再判断信号在不在
                    ret = sigismember(&set, SIGINT);
                    if(ret == 1)
                    {
                        printf("SIGINT is a member of sigprocmask \nret = %d\n", ret);
                    }

                    return 0;
                }


            4.2.5 信号阻塞集（屏蔽集、掩码）
                每个进程都有一个阻塞集，它用来描述哪些信号递送到该进程的时候被阻塞
                  (*在信号发生时 记住它，直到进程准备好时 再将信号通知进程*)。

                所谓阻塞 并不是 禁止传送信号，而是 暂缓信号的传送，若将 被阻塞的信号 从 信号阻塞集中 删除，且对应的信号 在被阻塞时发生了，进程将会收到相应的信号。

                4.2.5.1 sigprocmask 函数
                    创建一个阻塞集合
                头文件：
                    finclude <signal.h>

                int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);//一个是新的信号集，一个是旧的信号集
                功能:
                    检査或修改信号阻塞集，根据 how 指定的方法对进程的阻塞集合进行修改，新的信号阻塞集由 set 指定，而
                    原先的信号阻塞集合由 oldset 保存。
                参数:
                    how:信号阻塞集合的修改方法，
                    set:要操作的信号集地址。
                    oldset:保存原先信号集地址。
                how:
                    SIG_BLOCK:向信号阻塞集合中添加 set信号集  (注意:信号阻塞集 是 比信号集更大的概念。阻塞集中 添加的是 信号集；信号集中 添加的是 信号)
                    SIG_UNBLOCK:从信号阻塞集合中删除 set 集合
                    SIG_SETMASK:将信号阻塞集合设为set集合
                注:
                    若 set为NULL，则不改变信号阻塞集合，函数只把当前信号阻塞集合保存到oldset中，
                返回值:
                    成功:返回0
                    失败:返回 -1

*/

//第五章：另外两种进程间通信方式：管道(无名管道) 和 命名管道(有名管道)
/*
 （信号 、无名管道 、有名管道 称为 最原始的三种进程间通信方式）
    5.1无名管道
        5.1.1 管道概述
            管道(pipe)又称无名管道。
            无名管道 是一种 特殊类型的文件，在应用层 体现为 两个打开的 文件描述符

            任何一个进程在创建的时候，系统都会 给他分配4G的虚拟内存，分为3G的用户空间和1G的内核空间。
            内核空间是所有进程所公有的，*无名管道就是在内核空间创建的*，多个进程知道同一个无名管道的空间，就可以利用它来进行通信。

                      用户进程
                  fd[0]    fd[1]        fd[0]：负责读管道
                    ^       |           fd[1]：负责写管道
                    |       |
                    |       |
                    <--管道<--
                       内核

                无名管道虽然是在内核空间创建的，但是会给当前用户进程两个文件描述符，一个负责执行读操作,一个负责执行写操作

                管道是最古老的UNIXIPC方式，其特点是:
                  * 1、半双工，数据在同一时刻只能在一个方向上流动。
                  * 2、数据只能从管道的一端写入，从另一端读出。
                  * 3、写入管道中的数据遵循先入先出的规则。
                  * 4、管道所传送的数据是无格式的，这要求管道的读出方与写入方必须事先约定好数据的格式，如：多少字节算一个消息等。
                  * 5、管道不是普通的文件，不属于某个文件系统，其只存在于内存中（内存的内核空间创建）
                  * 6、管道在内存中对应一个缓冲区。不同的系统其大小不一定相同。
                  * 7、从管道读数据是一次性操作，数据一旦被读走，它就从管道中被抛弃，释放空间以便写更多的数据。
                  * 8、管道没有名字，只能在具有公共祖先的进程之间使用


        5.1.2 无名管道的创建pipe函数

            头文件：
                #include <unistd.h>
            int pipe (int filedes[2]);
            功能:
                (创建一个无名管道，返回两个文件描述符负责对管道进行读写操作)
                经由参数filedes,返回两个文件描述符
            参数:（参数是数组，且数组里面只有两个成员）
                filedes为 int 型数组的首地址。其存放了管道的文件描述符 fd[0]、fd[1]。
                fi1edes[0]为读而打开，fi1edes[1]为写而打开管道，filedes[0]的输出是 filedes[1]的输入。
            返回值:
                成功:返回 0
                失败:返回-1

            例：
                    //1. 创建一个无名管道：
                    // #include <stdio.h>
                    // #include <stdlib.h>
                    // #include <unistd.h>
                    // #include <string.h>

                    // int main(int argc, char const *argv[])
                    // {
                    //     //使用pipe创建一个无名管道
                    //     //创建有2个元素的数组
                    //     int fd_pipe[2];
                    //     //使用pipe创建无名管道，参数就是数组首地址，成功返回0
                    //     if(pipe(fd_pipe) == -1)
                    //     {
                    //         perror("fail to pipe");
                    //         exit(1);
                    //     }

                    //     printf("fd_pipe[0] = %d\n", fd_pipe[0]);
                    //     printf("fd_pipe[1] = %d\n", fd_pipe[1]);
                    //     //执行结果：3 4
                    //     //因为系统会自动开辟0 1 2 这三个文件描述符，那么再创建文件描述符，就是从3开始
                    //     return 0;
                    // }

                    // //2.1 对无名管道进行读写操作：
                    // #include <stdio.h>
                    // #include <stdlib.h>
                    // #include <unistd.h>
                    // #include <string.h>

                    // int main(int argc, char const *argv[])
                    // {
                    //     //使用pipe创建一个无名管道
                    //     //创建有2个元素的数组
                    //     int fd_pipe[2];
                    //     //使用pipe创建无名管道，参数就是数组首地址，成功返回0
                    //     if(pipe(fd_pipe) == -1)
                    //     {
                    //         perror("fail to pipe");
                    //         exit(1);
                    //     }

                    //     printf("fd_pipe[0] = %d\n", fd_pipe[0]);
                    //     printf("fd_pipe[1] = %d\n", fd_pipe[1]);
                    //     //执行结果：3 4
                    //     //因为系统会自动开辟0 1 2 这三个文件描述符，那么再创建文件描述符，就是从3开始

                    //     //对无名管道执行读写操作
                    //     //由于无名管道给当前用户进程两个文件描述符，所以只要操作这两个文件
                    //     //描述符就可以操作无名管道，所以通过文件IO中的read和write函数对无名管道进行操作

                    //     //通过write函数向无名管道中写入数据
                    //     //fd_pipe[1]负责执行写操作
                    //     //如果管道中有数据，再次写入的数据会放在之前数据的后面，不会把之前的数据替换
                    //     if(write(fd_pipe[1], "hello world", 12) == -1)
                    //     {
                    //         perror("fail to write");
                    //         exit(1);
                    //     }

                    //     //通过read函数从无名管道中读取数据
                    //     //fd_pipe[0]负责执行读操作
                    //     //读取数据时，直接从管道中读取指定个数的数据，如果管道中没有数据了，则read函数会阻塞等待
                    //     char buf[32] = "";
                    //     ssize_t bytes;  //获得 读操作 的返回值
                    //     if((bytes = read(fd_pipe[0], buf, sizeof(buf))) == -1)
                    //     {
                    //         perror("fail to read");
                    //         exit(1);
                    //     }

                    //     printf("buf = [%s]\n", buf);
                    //     printf("bytes = %ld\n", bytes); //管道内有12个字符，就读取了12个字符

                    //     return 0;
                    // }

                    // //2.2 对无名管道进行读写操作：
                    // #include <stdio.h>
                    // #include <stdlib.h>
                    // #include <unistd.h>
                    // #include <string.h>

                    // int main(int argc, char const *argv[])
                    // {
                    //     //使用pipe创建一个无名管道
                    //     //创建有2个元素的数组
                    //     int fd_pipe[2];
                    //     //使用pipe创建无名管道，参数就是数组首地址，成功返回0
                    //     if(pipe(fd_pipe) == -1)
                    //     {
                    //         perror("fail to pipe");
                    //         exit(1);
                    //     }

                    //     printf("fd_pipe[0] = %d\n", fd_pipe[0]);
                    //     printf("fd_pipe[1] = %d\n", fd_pipe[1]);
                    //     //执行结果：3 4
                    //     //因为系统会自动开辟0 1 2 这三个文件描述符，那么再创建文件描述符，就是从3开始

                    //     //对无名管道执行读写操作
                    //     //由于无名管道给当前用户进程两个文件描述符，所以只要操作这两个文件
                    //     //描述符就可以操作无名管道，所以通过文件IO中的read和write函数对无名管道进行操作

                    //     //通过write函数向无名管道中写入数据
                    //     //fd_pipe[1]负责执行写操作
                    //     //如果管道中有数据，再次写入的数据会放在之前数据的后面，不会把之前的数据替换
                    //     if(write(fd_pipe[1], "hello world", 11) == -1)
                    //     {
                    //         perror("fail to write");
                    //         exit(1);
                    //     }

                    //     write(fd_pipe[1], "nihao beijing", strlen("nihao beijing")+1);

                    //     //通过read函数从无名管道中读取数据
                    //     //fd_pipe[0]负责执行读操作
                    //     //读取数据时，直接从管道中读取指定个数的数据，如果管道中没有数据了，则read函数会阻塞等待
                    //     char buf[32] = "";
                    //     ssize_t bytes;  //获得 读操作 的返回值
                    //     if((bytes = read(fd_pipe[0], buf, sizeof(buf))) == -1)
                    //     {
                    //         perror("fail to read");
                    //         exit(1);
                    //     }

                    //     printf("buf = [%s]\n", buf);
                    //     printf("bytes = %ld\n", bytes); //管道内有12个字符，就读取了12个字符

                    //     //问题1：第二次所写的数据 会不会覆盖 第一次写的数据？
                    //     //问题2：read读取时，能不能把 nihao beijing 也读取到？
                    //     //执行结果：
                    //     // fd_pipe[0] = 3
                    //     // fd_pipe[1] = 4
                    //     // buf = [hello worldnihao beijing]
                    //     // bytes = 25
                    //     //1.把管道内所有内容都读取了，2.后写入数据会保存在先写入数据的后面。即：不会覆盖


                    //     // bytes = read(fd_pipe[0], buf, sizeof(buf));
                    //     // printf("buf = [%s]\n", buf);
                    //     // printf("bytes = %ld\n", bytes);

                    //     // bytes = read(fd_pipe[0], buf, sizeof(buf));
                    //     // printf("buf = [%s]\n", buf);
                    //     // printf("bytes = %ld\n", bytes);

                    //     return 0;
                    // }

                    //2.3 对无名管道读取之后再读
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <string.h>

                    int main(int argc, char const *argv[])
                    {
                        //使用pipe创建一个无名管道
                        //创建有2个元素的数组
                        int fd_pipe[2];
                        //使用pipe创建无名管道，参数就是数组首地址，成功返回0
                        if(pipe(fd_pipe) == -1)
                        {
                            perror("fail to pipe");
                            exit(1);
                        }

                        printf("fd_pipe[0] = %d\n", fd_pipe[0]);
                        printf("fd_pipe[1] = %d\n", fd_pipe[1]);
                        //执行结果：3 4
                        //因为系统会自动开辟0 1 2 这三个文件描述符，那么再创建文件描述符，就是从3开始

                        //对无名管道执行读写操作
                        //由于无名管道给当前用户进程两个文件描述符，所以只要操作这两个文件
                        //描述符就可以操作无名管道，所以通过文件IO中的read和write函数对无名管道进行操作

                        //通过write函数向无名管道中写入数据
                        //fd_pipe[1]负责执行写操作
                        //如果管道中有数据，再次写入的数据会放在之前数据的后面，不会把之前的数据替换
                        if(write(fd_pipe[1], "hello world", 11) == -1)
                        {
                            perror("fail to write");
                            exit(1);
                        }

                        write(fd_pipe[1], "nihao beijing", strlen("nihao beijing")+1);

                        //通过read函数从无名管道中读取数据
                        //fd_pipe[0]负责执行读操作
                        //读取数据时，直接从管道中读取指定个数的数据，如果管道中没有数据了，则read函数会阻塞等待
                        char buf[32] = "";
                        ssize_t bytes;  //获得 读操作 的返回值
                        if((bytes = read(fd_pipe[0], buf, 20)) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }

                        printf("buf = [%s]\n", buf);
                        printf("bytes = %ld\n", bytes); //管道内有12个字符，就读取了12个字符

                        //问题1：第二次所写的数据 会不会覆盖 第一次写的数据？
                        //问题2：read读取时，能不能把 nihao beijing 也读取到？
                        //执行结果：
                        // fd_pipe[0] = 3
                        // fd_pipe[1] = 4
                        // buf = [hello worldnihao beijing]
                        // bytes = 25
                        //1.把管道内所有内容都读取了，2.后写入数据会保存在先写入数据的后面。即：不会覆盖

                        //问题3：读取之后再读取会怎样?
                        bytes = read(fd_pipe[0], buf, sizeof(buf));
                        printf("buf = [%s]\n", buf);
                        printf("bytes = %ld\n", bytes);
                        //执行结果：
                        // fd_pipe[0] = 3
                        // fd_pipe[1] = 4
                        // buf = [hello worldnihao bei]
                        // bytes = 20
                        // buf = [jing]
                        // bytes = 5


                        //问题4：当管道内没有数据时再去读，会怎样？ =>会阻塞
                        bytes = read(fd_pipe[0], buf, sizeof(buf));
                        printf("buf = [%s]\n", buf);
                        printf("bytes = %ld\n", bytes);

                        return 0;
                    }



        5.1.3无名管道实现进程间通信：
                    由于不同进程在创建管道时，得到的文件描述符不相同，(因为是在两个程序中创建的,两个管道没有任何关系），
                    这就是为什么：无名管道只能在同一个祖先的进程间通信。因为不同进程之间的不到相同的文件描述符。

                          fork
                父进程      ——>      子进程
             fd[0]  fd[1]        fd[0]  fd[1]

                         ==管道==
              * 注意:
                    利用无名管道实现进程间的通信，都是父进程创建无名管道，然后再创建子进程，
                    子进程 继承 父进程的 无名管道的文件描述符 ，然后父子进程 通过读写无名管道 实现通信。
                    （最好是创建两个管道，一个管道父写子读 ，另一个管道父读子写）

                例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <string.h>

                        //使用无名管道实现 父子进程间 的通信
                        //由于无名管道创建之后给当前进程两个文件描述符，所以如果是完全不相关的进程
                        //无法获取同一个无名管道的文件描述符，所以无名管道只能在具有亲缘关系的进程间通信

                        int main(int argc, char const *argv[])
                        {
                            //父进程 创建一个无名管道
                            int pipefd[2];
                            if(pipe(pipefd) == -1)
                            {
                                perror("fail to pipe");
                                exit(1);
                            }

                            //使用fork函数创建子进程
                            //子进程创建时 会复制 父进程的fd
                            pid_t pid;
                            if((pid = fork()) < 0)
                            {
                                perror("fail to fork");
                                exit(1);
                            }

                            else if(pid > 0) // 父进程
                            {
                                //父进程负责给子进程发送数据
                                char buf[128] = {};
                                while(1)
                                {
                                    //1.首先，父进程会阻塞在这里
                                    fgets(buf, sizeof(buf), stdin); //父进程使用fgets从终端读取输入，保存在buf
                                    buf[strlen(buf) - 1] = '\0';    //把buf里面读取到的最后的\n换成\0

                                    //通过pipefd 把buf的内容 写入管道
                                    if(write(pipefd[1], buf, sizeof(buf)) == -1)
                                    {
                                        perror("fail to write");
                                        exit(1);
                                    }
                                }
                            }
                            else //子进程
                            {
                                //子进程接收父进程的数据
                                char buf[128] = "";
                                while(1)
                                {
                                    //读取父进程写入的数据，读取到子进程自己的buf里面
                                    //2.而子进程会阻塞在读取空管道
                                    if(read(pipefd[0], buf, sizeof(buf)) == -1)
                                    {
                                        perror("fail to read");
                                        exit(1);
                                    }

                                    printf("from parent: %s\n", buf);//打印从父进程读取到的数据
                                }
                            }

                            //执行结果：
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$ ./a.out
                            // hello
                            // from parent: hello
                            // world
                            // from parent: world
                            // ^C
                            // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$
                            return 0;
                        }


        5.1.4 无名管道的读写规律
                从管道中读数据的特点
                    1、默认用 read 函数从管道中读数据是阻塞的。
                    2、调用 write 函数向管道里写数据，当缓冲区已满时 write 也会阻塞。
                    3、通信过程中，读端口全部关闭后，写进程向管道内写数据时，写进程会(收到 SIGPIPE 信号)退出

            5.1.4.1 读写端都存在，只读不写
                如果管道中有数据，会正常读取数据
                如果管道中没有数据，则读操作会阻塞等待，直到有数据为止
                例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>

                        int main(int argc, char const *argv[])
                        {
                            int pipefd[2];
                            if(pipe(pipefd) == -1)  //创建无名管道
                            {
                                perror("fail to pipe");
                                exit(1);
                            }

                            //读写端都存在，只读不写
                            //如果管道中有数据，会正常读取数据
                            //如果管道中没有数据，则读操作会阻塞等待，直到有数据为止

                            write(pipefd[1], "hello world", 11);

                            char buf[128] = "";
                            if(read(pipefd[0], buf, sizeof(buf)) == -1)
                            {
                                perror("fail to read");
                                exit(1);
                            }

                            printf("buf = %s\n", buf);

                            if(read(pipefd[0], buf, sizeof(buf)) == -1)
                            {
                                perror("fail to read");
                                exit(1);
                            }

                            printf("buf = %s\n", buf);

                            return 0;
                        }

            5.1.4.2 读写端都存在，只写不读
                如果一直执行写操作，则无名管道对应的缓冲区会被写满，写满之后，write函数也会阻塞等待
                默认无名管道的缓冲区64K字节
                        由于一次写1024个字节，即1K字节，最终num的值就是64，故缓冲区是64k的。
                        if(write(pipefd[1], "6666", 1024) == -1)

            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        int pipefd[2];
                        if(pipe(pipefd) == -1)
                        {
                            perror("fail to pipe");
                            exit(1);
                        }

                        //读写端都存在，只写不读
                        //如果一直执行写操作，则无名管道对应的缓冲区会被写满，写满之后，write函数也会阻塞等待
                        //默认无名管道的缓冲区64K字节:

                        int num = 0;
                        while(1)
                        {
                            //由于一次写1024个字节，即1K字节，最终num的值就是64，故缓冲区是64k的。
                            if(write(pipefd[1], "6666", 1024) == -1)
                            {
                                perror("fail to write");
                                exit(1);
                            }
                            num++;
                            printf("num = %d\n", num);
                        }

                        return 0;
                    }


            5.1.4.3 只有读端
                关闭写端：close(pipefd[1]);
                如果原本管道中有数据，则读操作正常读取数据
                如果管道中没有数据，则read函数会返回0

                例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <string.h>

                    int main(int argc, char const *argv[])
                    {
                        int pipefd[2];
                        if(pipe(pipefd) == -1)
                        {
                            perror("fail to pipe");
                            exit(1);
                        }

                        write(pipefd[1], "hello world",11);

                        //关闭写文件描述符，只有读端
                        //如果原本管道中有数据，则读操作正常读取数据
                        //如果管道中没有数据，则read函数会返回0
                        close(pipefd[1]);

                        char buf[128] = "";
                        ssize_t bytes;
                        if((bytes = read(pipefd[0], buf, sizeof(buf))) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }

                        printf("bytes = %ld\n", bytes);
                        printf("buf = %s\n", buf);

                        //清除字符串中的内容
                        memset(buf, 0, sizeof(buf));

                        if((bytes = read(pipefd[0], buf, sizeof(buf))) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }


                        printf("bytes = %ld\n", bytes);
                        printf("buf = %s\n", buf);

                        return 0;
                    }
            5.1.4.4 只有写端

                如果关闭读端（close(pipefd[0])），一旦执行写操作，就会产生一个信号SIGPIPE（管道破裂），
                这个信号的默认处理方式是退出进程
            (读操作被关闭，只要一写，就会产生SIGPIPE信号。)
                例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <signal.h>

                        void handler(int sig)
                        {
                            printf("SIGPIPE信号产生了，管道破裂了\n");
                        }

                        int main(int argc, char const *argv[])
                        {
                            signal(SIGPIPE, handler);

                            int pipefd[2];
                            if(pipe(pipefd) == -1)
                            {
                                perror("fail to pipe");
                                exit(1);
                            }

                            //关闭写操作文件描述符，只有写端
                            //如果关闭读端，一旦执行写操作，就会产生一个信号SIGPIPE（管道破裂），
                            //这个信号的默认处理方式是退出进程
                            close(pipefd[0]);

                            int num = 0;
                            while(1)
                            {
                                if(write(pipefd[1], "hello world", 1024) == -1)
                                {
                                    perror("fail to write");
                                    exit(1);
                                }
                                num++;
                                printf("num = %d\n", num);
                            }

                            return 0;
                        }


        5.1.5 通过fcntl函数设置文件的阻塞特性
            编程时可通过 fcntl 函数设置文件的阻塞特性。

            设置为阻塞:
                fcntl(fd,F_SETFL,0);    //fd:文件描述符；F_SETFL:设置文件描述符的属性 ；0：表示阻塞
            设置为非阻塞:
                fcntl(fd,F_SETFL,O_NONBLOCK);   //O_NONBLOCK ：表示非阻塞

        非阻塞:如果是阻塞，管道中没有数据，read会一直等待，直到有数据才会继续运行，否则一直等待。
        非阻塞:read函数运行时，会先看一下管道中是否有数据，如果有数据，则正常运行读取数据，如果管道中没有数据，则read函数会立即返回，继续下面的代码运行。

            例：
                    // //不加fcntl 设置文件属性
                    // #include <stdio.h>
                    // #include <string.h>
                    // #include <unistd.h>
                    // #include <stdlib.h>
                    // #include <sys/types.h>
                    // #include <sys/wait.h>
                    // #include <fcntl.h>

                    // int main(int argc, char *argv[])
                    // {
                    // 	int fd_pipe[2];
                    // 	char buf[] = "hello world";
                    // 	pid_t pid;

                    //     //1.创建无名管道
                    // 	if (pipe(fd_pipe) < 0)
                    // 	{
                    // 		perror("fail to pipe");
                    // 		exit(1);
                    // 	}

                    //     //2.创建父子进程
                    // 	pid = fork();
                    // 	if (pid < 0)
                    // 	{
                    // 		perror("fail to fork");
                    // 		exit(0);
                    // 	}
                    // 	if (pid == 0)   //子进程负责写数据
                    // 	{
                    // 		while(1)
                    // 		{
                    //             //5s之后写
                    // 			sleep(5);
                    // 			write(fd_pipe[1], buf, strlen(buf));
                    // 		}
                    // 	}
                    // 	else    //父进程负责读数据
                    // 	{
                    // 		while(1)
                    // 		{
                    //             //3.读之前先把buf清空
                    // 			memset(buf, 0, sizeof(buf));
                    // 			read(fd_pipe[0], buf, sizeof(buf));
                    // 			printf("buf=[%s]\n", buf);
                    // 			sleep(1);
                    //             //睡1s就读
                    // 		}
                    // 	}
                    //     //执行结果就是：每5s打印一次：buf=[hello world]
                    // 	return 0;
                    // }



                    //使用fcntl 将 fd_pipe[0]设置为非阻塞
                    #include <stdio.h>
                    #include <string.h>
                    #include <unistd.h>
                    #include <stdlib.h>
                    #include <sys/types.h>
                    #include <sys/wait.h>
                    #include <fcntl.h>

                    int main(int argc, char *argv[])
                    {
                        int fd_pipe[2];
                        char buf[] = "hello world";
                        pid_t pid;

                        //1.创建无名管道
                        if (pipe(fd_pipe) < 0)
                        {
                            perror("fail to pipe");
                            exit(1);
                        }

                        //2.创建父子进程
                        pid = fork();
                        if (pid < 0)
                        {
                            perror("fail to fork");
                            exit(0);
                        }
                        if (pid == 0)   //子进程负责写数据
                        {
                            while(1)
                            {
                                //5s之后写
                                sleep(5);
                                write(fd_pipe[1], buf, strlen(buf));
                            }
                        }
                        else    //父进程负责读数据
                        {
                            //将fd_pipe[0]设置为阻塞
                            //fcntl(fd_pipe[0], F_SETFL, 0);
                            //将fd_pipe[0]设置为非阻塞：即使管道没有数据，即，读不到数据，依然往下执行。
                            fcntl(fd_pipe[0], F_SETFL, O_NONBLOCK);

                            while(1)
                            {
                                //3.读之前先把buf清空
                                memset(buf, 0, sizeof(buf));
                                read(fd_pipe[0], buf, sizeof(buf));
                                printf("buf=[%s]\n", buf);
                                sleep(1);
                                //睡1s就读
                            }
                        }
                        //执行结果：
                        // ...
                        // buf=[]
                        // buf=[hello world]
                        // buf=[]
                        // ...
                        //每5秒打印一次buf=[hello world]，其余秒数（读不到数据时），打印 buf=[]

                        return 0;
                    }

    5.2 文件描述符概述
            文件描述符是非负整数，是文件的标识。(并且要操作文件也是通过文件描述符进行操作的)
            用户使用文件描述符(file descriptor)来访问文件。
            利用 open 打开一个文件时，内核会返回一个文件描述符。

                每个进程都有一张文件描述符的表，进程刚被创建时，标准输入、标准输出、标准错误输出设备文件被打开，
            对应的文件描述符 0、1、2 记录在表中。（在进程控制块PCB里）
                在进程中打开其他文件时，系统会返回文件描述符表中最小可用的文件描述符，并将此文件描述符记录在表中。

            注意：
                Linux 中一个进程最多只能打开NR_OPEN_DEFAULT(即 1024)个文件，
               故，当文件不再使用时，应及时调用close 函数关闭文件。
        例：
                    // //测试1：文件描述符是把 文件描述符表 中 最小可用的文件描述符
                    // #include <stdio.h>
                    // //open的三个头文件：man查看
                    // #include <sys/types.h>
                    // #include <sys/stat.h>
                    // #include <fcntl.h>
                    // //关闭文件描述符close的头文件
                    // #include <unistd.h>
                    // #include <stdlib.h>

                    // int main(int argc, char const *argv[])
                    // {
                    //     //在进程中打开其他文件时，
                    //     //系统会返回文件描述符表中最小可用的文件描述符，
                    //     //并将此文件描述符记录在进程的文件描述符表中。
                    //     close(0);
                    //     int fd1, fd2, fd3;
                    //     fd1 = open("file.txt", O_RDONLY | O_CREAT, 0664);
                    //     fd2 = open("file.txt", O_RDONLY | O_CREAT, 0664);
                    //     fd3 = open("file.txt", O_RDONLY | O_CREAT, 0664);

                    //     printf("fd1 = %d\n", fd1);
                    //     printf("fd2 = %d\n", fd2);
                    //     printf("fd3 = %d\n", fd3);
                    //     return 0;
                    // }


                    //测试2：最多可创建多少个文件描述符
                    #include <stdio.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>
                    #include <unistd.h>
                    #include <stdlib.h>

                    int main(int argc, char const *argv[])
                    {
                        //Linux中一个进程最多只能打开NR_OPEN_DEFAULT（即1024）个文件，
                        //故当文件不再使用时应及时调用close函数关闭文件
                        int fd;
                        while(1)
                        {
                            if((fd = open("file.txt", O_RDONLY | O_CREAT, 0664)) < 0)
                            {
                                perror("fail to open");
                                exit(1);
                            }

                            printf("fd = %d\n", fd);
                        }

                        return 0;
                    }


    5.3 文件描述符的复制
        dup 和 dup2是两个非常有用的系统调用，都是用来复制一个文件的描述符，使新的文件描述符也标识旧的文件描述符 所标识的文件。
        int dup(int oldfd)；
        int dup2 (int oldfd, int newfd)；

        dup 和 dup2 经常用来重定向进程的 stdin、stdout 和 stderr。
        回顾:
            1s > test.txt:       //把ls 输出结果 输出到 文件里面
            echo "hello world" > test.txt   //把这句话输出到文件里面

        5.3.1 dup 函数
        #include <unistd.h>

        int dup(int oldfd):
        功能:
            复制 g1dfd 文件描述符，并分配一个新的文件描述符，新的文件描述符是调用进程文件描述符表中最小可用的文件描述符。
        参数:
            要复制的文件描述符 oldfd,
        返回值:
            成功：新文件描述符
            失败：返回-1 ，错误代码存于：errno中

        例1：复制文件描述符
                #include <stdio.h>
                #include <unistd.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <fcntl.h>
                #include <string.h>

                int main(void)
                {
                    //通过dup函数复制一个文件描述符
                    int fd;
                    //dup执行后给返回值文件描述符分配的值是文件描述符表中最小可用的文件描述符
                    fd = dup(1);    //1是标准输出描述符。
                    printf("fd = %d\n", fd);    //3
                    //由于通过dup函数将1这个文件描述符复制了一份为fd，所以fd现在就相当于1，所以写数据就是想终端写入数据
                    write(fd, "nihao beijing\n", strlen("nihao beijing\n"));

                    return 0;
                }


        例2：实现输出重定向的功能
            首先像printf函数是操作文件描述符1所对应的文件，
            默认是操作终端，只要能够把1对应标识的文件改变，就可以实现输出重定向
            所以实现创建好文件对应的文件描述符之后，将1文件描述符关闭，接着通过dup
            函数复制的新的文件描述符就是1，这样printf函数对1操作，就写到了文件中

                #include <stdio.h>
                #include <unistd.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <fcntl.h>

                int main(int argc, char *argv[])
                {
                    //如果需要实现输出重定向的功能
                    //首先像printf函数是操作文件描述符1所对应的文件，
                    //默认是操作终端，只要能够把1对应标识的文件改变，就可以实现输出重定向
                    //所以实现创建好文件对应的文件描述符之后，将1文件描述符关闭，接着通过dup
                    //函数复制的新的文件描述符就是1，这样printf函数对1操作，就写到了文件中
                    int fd_file;    //先保存文件描述符
                    fd_file = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0664);
                    if(fd_file == -1)
                    {
                        perror("fail to open");
                        exit(1);
                    }

                    //2.先关闭文件描述符 1
                    close(1);

                    //3.再复制一份文件描述符，此时由于1被关闭，复制出来的fd就指向1
                    int fd = dup(fd_file);
                    printf("hello world\n");
                    //1.由于printf操作的文件描述符是1，因此我们只能让1不再指向终端
                    //而是指向我的目标输出文件，即让fd的文件描述符变成1。
                    printf("fd = %d\n", fd);

                    return 0;
                }

        例3：实现输出重定向后，还想标准输出如何实现
                #include <stdio.h>
                #include <unistd.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <fcntl.h>

                int main(int argc, char *argv[])
                {
                    int fd1;
                    int fd2;
                    fd2 = dup(1);
                    printf("new:fd2 = %d\n",fd2);

                    fd1 = open("test.txt", O_RDWR | O_CREAT, 0664);

                    close(1);
                    int fd3 = dup(fd1);
                    printf("hello world\n");
                    printf("fd = %d\n", fd3);

                    close(1);
                    int fd4 = dup(fd2);
                    printf("nihao beijing\n");
                    printf("fd = %d\n", fd4);

                    return 0;
                }


        5.3.2 dup2 函数   重定向
            #include<unistd.h>
            int dup2(int oldfd, int newfd)

            功能:
                复制一份 打开的 文件描述符oldfd，并分配新的文件描述符 newfd,newfd,也标识oldfd 所标识的文件
            注意:
                newfd,是小于文件描述符最大允许值的非负整数。
              * 如果 newfd 是一个已经打开的文件描述符，则首先关闭该文件，然后再复制。
                (这解决了dup函数在重定向的时候需要close(1)的操作。)
            参数:
                要复制的文件描述符 oldfd
                分配的新的文件描述符 newfd
            返回值:
                成功:返回 newfd
                失败:返回-1，错误代码存于 erzno中

            例1：实现输出重定向
                #include <stdio.h>
                #include <unistd.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <fcntl.h>

                int main(void)
                {
                    int fd1;
                    int fd2;

                    fd1 = open("test.txt", O_CREAT | O_WRONLY, 0664);
                    if (fd1 < 0)
                    {
                        perror("fail to open");
                        exit(1);
                    }

                    //首先关闭1文件描述符，然后将fd1复制给1，意味着1和fd1都标识test.txt文件,返回值跟1是一样的
                    fd2 = dup2(fd1, 1);
                    printf("hello world\n");
                    printf("fd2 = %d\n", fd2);

                    return 0;
                }

            例2：实现输出重定向后，在恢复标准输出
            注意：
                如果使用dup2，则需要实现给第二个参数对应的变量赋一个初始值
                    #include <stdio.h>
                    #include <unistd.h>
                    #include <stdlib.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>

                    int main(int argc, char *argv[])
                    {
                        int fd1;
                        //如果使用dup2，则需要实现给第二个参数对应的变量赋一个初始值
                        int fd2 = 3;
                        // #如果不赋值3，由于dup2会复制为  现阶段没有使用 且 值最小的文件描述符，也就是：0，那么fd就会变成0，所以fd需要先赋初值

                        //将1复制一份为fd2，所以fd2标识的是标准输出
                        dup2(1, fd2);   //把1复制一份，使fd2也为标准输出
                        printf("fd2 = %d\n", fd2);

                        fd1 = open("test.txt", O_CREAT | O_RDWR, 0664);

                        //输出重定向：关闭文件描述符1，将fd1复制一份为1，所以1此时标识的是test.txt文件
                        dup2(fd1, 1);
                        printf("hello world\n");

                        //再次实现标准输出：关闭文件描述符1，将fd2复制一份为1，所以1此时标识的是标准输出
                        dup2(fd2, 1);
                        printf("你好北京\n");
                        return 0;
                    }


    5.4 有名管道（FIFO）
        5.4.1
            命名管道(FIF0)和管道(pipe)甚本相同，但也有一些显著的不同,

        其特点是:
            1、半双工，数据在同一时刻只能在一个方向上流动,
            2、写入FIFO 中的数据遵循先入先出的规则。
            3、FIFO 所传送的数据是无格式的，这要求 FIFO的读出方与写入方必须事先约定好数据的格式，如多少字节算一个消息等。
          * 4、FIFO 在文件系统中作为一个特殊的文件而存在 #并且在文件系统中可见# ，但FIFO 中的内容却存放在内存中
            5、管道在内存中对应一个缓冲区。不同的系统其大小不一定相同。
            6、从FIFO读数据是一次性操作，数据一旦被读，它就从FIFO 中被抛弃，释放空间以便写更多的数据。
          * 7、当使用 FIFO 的进程退出后，FIFO 文件将继续保存在文件系统中以便以后使用。
          * 8、FIFO 有名字，不相关的进程 可以通过 打开命名管道 进行通信。

          对于4:我们知道对于无名管道（pipe），它只提供了两个文件描述符来进行操作
                但对于有名管道：他会在本地直接给你创建一个文件，而这个文件的类型就是管道的类型。（bcd-lsp）其创建的有名管道文件就是p文件。


        5.4.2 有名管道的创建
            方法1：通过shell 命令：mkfifo 创建 有名管道
                使用：mkfifo 文件名
            例：
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$ mkfifo myfifo
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$ ls
                    10_dup_2.c   15_fifo_read_write.c  5_pipe_read_only.c   a.out
                    11_dup_3.c   1_pipe.c              6_pipe_write_only.c  file.txt
                    12_dup2_1.c  2_pipe_process.c      7_pipe_fcntl.c       myfifo
                    13_dup2_2.c  3_pipe_read.c         8_fd.c               test.txt
                    14_fifo.c    4_pipe_write.c        9_dup_1.c
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$ ls -l myfifo
                    prw-rw-r-- 1 qinmei qinmei 0 1月   5 17:33 myfifo
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$

            方法2：使用函数 mkfifo
            头文件：
                #include <sys/types.h>
                #include <sys/stat.h>

            int mkfifo(const char *pathname, mode_t mode);
            功能：
                创建一个有名管道，产生一个本地文件系统可见的文件pathname
            参数:
                pathname：有名管道创建后生成的文件，可以带路径
                mode:管道文件的权限，一般通过8进制数设置即可，例：0664等
            返回值：
                成功： 0
                失败： -1，错误后返回错误码，错误码对应的错误原因可以在/usr/include/asm-generic/errno-base.h 路径下的errno.h文件中查询

        例：
                #include <stdio.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <fcntl.h>
                #include <unistd.h>
                #include <errno.h>

                int main(int argc, char const *argv[])
                {
                    //通过mkfifo函数创建有名管道
                    if(mkfifo("fifo_file", 0664) == -1)
                    {
                        // printf("errno = %d\n", errno);
                        //如果管道文件已经存在，不需要报错退出，直接使用即可，所以需要在错误输出之前把
                        //因为文件存在的错误排除
                        if(errno != EEXIST)
                        {
                            perror("fail to mkfifo");
                            exit(1);
                        }
                    }

                    return 0;
                }



        5.4.3 有名管道的基本读写操作

        操作FIFO 文件时的特点
            系统调用的IO函数都可以作用于FIFO，如open、close、read、write 等。
            打开 FIFO 时，非阻塞标志(ONONBLOCK)产生下列影响:


      * 由于有名管道在本地创建了一个文件，所以系统调用的IO函数基本都可以对有名管道进行操作，但是不能使用 lseek 修改管道文件的偏移量（无名管道也不能修改）

      * 注意：
            有名管道 创建的 本地的文件 只是起到 标识作用，真正 有名管道 实现 进程间通信 还是在 内核空间开辟内存，
            所以,本地产生的文件 只是一个标识，没有其他作用，对本地管道文件的操作 实质就是对 内核空间的操作。
            （有名管道 不是一个文件，文件只是一个标识，实质还是在内核空间开辟内存，对 有名管道文件 的操作，实质还是对 内核空间进行操作）

            例：
                    // //最基本的对又名管道的操作
                    // #include <stdio.h>
                    // #include <stdlib.h>
                    // #include <sys/types.h>
                    // #include <sys/stat.h>
                    // #include <fcntl.h>
                    // #include <unistd.h>
                    // #include <errno.h>
                    // #include <string.h>

                    // #define FIFONAME "fifo_file"

                    // int main(int argc, char const *argv[])
                    // {
                    //     //通过mkfifo函数创建有名管道
                    //     if(mkfifo(FIFONAME, 0664) == -1)
                    //     {
                    //         if(errno != EEXIST)
                    //         {
                    //             perror("fail to mkfifo");
                    //             exit(1);
                    //         }
                    //     }

                    //     //对有名管道进行操作
                    //     int fd;     //fd得到文件描述符
                    //     fd = open(FIFONAME, O_RDWR);    //对文件既要读又要写故为：O_RDWR权限
                    //     if(fd == -1)
                    //     {
                    //         perror("fail to open");
                    //         exit(1);
                    //     }

                    //     //通过write函数向管道中写入数据
                    //     if(write(fd, "hello world", strlen("hello world")) == -1)
                    //     {
                    //         perror("fail to write");
                    //         exit(1);
                    //     }
                    //     //通过read函数读取管道中的数据
                    //     char buf[32] = "";
                    //     if(read(fd, buf, sizeof(buf)) == -1)
                    //     {
                    //         perror("fail to read");
                    //         exit(1);
                    //     }
                    //     printf("buf = [%s]\n", buf);

                    //     //使用close函数关闭文件描述符
                    //     close(fd);

                    //     return 0;
                    // }




                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>
                    #include <unistd.h>
                    #include <errno.h>
                    #include <string.h>

                    #define FIFONAME "fifo_file"

                    int main(int argc, char const *argv[])
                    {
                        //通过mkfifo函数创建有名管道
                        if(mkfifo(FIFONAME, 0664) == -1)
                        {
                            if(errno != EEXIST)
                            {
                                perror("fail to mkfifo");
                                exit(1);
                            }
                        }

                        //对有名管道进行操作
                        //管道后写入的数据会保存在之前写入数据的后面，不会替换
                        //如果管道中没有数据了，读操作会阻塞

                        //通过open函数打开管道文件并得到文件描述符
                        int fd;
                        fd = open(FIFONAME, O_RDWR);    //对文件既要读又要写故为：O_RDWR权限
                        if(fd == -1)
                        {
                            perror("fail to open");
                            exit(1);
                        }

                        //通过write函数向管道中写入数据
                        if(write(fd, "hello world", strlen("hello world")) == -1)
                        {
                            perror("fail to write");
                            exit(1);
                        }

                        write(fd, "nihao beijing", strlen("nihao beijing"));

                        //通过read函数读取管道中的数据
                        char buf[32] = "";
                        if(read(fd, buf, sizeof(buf)) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }
                        printf("buf = [%s]\n", buf);

                        if(read(fd, buf, sizeof(buf)) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }
                        printf("buf = [%s]\n", buf);

                        //使用close函数关闭文件描述符
                        close(fd);

                        return 0;
                    }



        5.4.4 有名管道实现进程间通信
            由于有名管道在本地创建了一个管道文件，所以不相关的进程间也可以实现通信


            5.4.4.1 send

                #include <stdio.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <errno.h>
                #include <fcntl.h>
                #include <unistd.h>
                #include <string.h>

                int main(int argc, char const *argv[])
                {
                    //如果没有创建有名管道，则创建有名管道
                    //为了实现两个进程都可以收发数据，所以需要创建两个有名管道
                    if(mkfifo("myfifo1", 0664) == -1)
                    {
                        if(errno != EEXIST)
                        {
                            perror("fail to mkfifo");
                            exit(1);
                        }
                    }

                    if(mkfifo("myfifo2", 0664) == -1)
                    {
                        if(errno != EEXIST)
                        {
                            perror("fail to mkfifo");
                            exit(1);
                        }
                    }

                    //打开两个有名管道并得到文件描述符
                    int fd_w, fd_r;
                    if((fd_w = open("myfifo1", O_WRONLY)) == -1)
                    {
                        perror("fail to open");
                        exit(1);
                    }

                    if((fd_r = open("myfifo2", O_RDONLY)) == -1)
                    {
                        perror("fail to open");
                        exit(1);
                    }

                    char buf[128] = "";
                    ssize_t bytes;
                    while(1)
                    {
                        fgets(buf, sizeof(buf), stdin);
                        buf[strlen(buf) - 1] = '\0';

                        //send进程负责将数据写入myfifo1，接着从myfifo2中读取数据
                        if((bytes = write(fd_w, buf, sizeof(buf))) == -1)
                        {
                            perror("fail to write");
                            exit(1);
                        }

                        if((bytes = read(fd_r, buf, sizeof(buf))) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }

                        printf("from recv: %s\n", buf);
                    }

                    return 0;
                }


            5.4.4.2 receive

                #include <stdio.h>
                #include <stdlib.h>
                #include <sys/types.h>
                #include <sys/stat.h>
                #include <errno.h>
                #include <fcntl.h>
                #include <unistd.h>
                #include <string.h>

                int main(int argc, char const *argv[])
                {
                    if(mkfifo("myfifo1", 0664) == -1)
                    {
                        if(errno != EEXIST)
                        {
                            perror("fail to mkfifo");
                            exit(1);
                        }
                    }

                    if(mkfifo("myfifo2", 0664) == -1)
                    {
                        if(errno != EEXIST)
                        {
                            perror("fail to mkfifo");
                            exit(1);
                        }
                    }

                    int fd_w, fd_r;

                    if((fd_r = open("myfifo1", O_RDONLY)) == -1)
                    {
                        perror("fail to open");
                        exit(1);
                    }

                    if((fd_w = open("myfifo2", O_WRONLY)) == -1)
                    {
                        perror("fail to open");
                        exit(1);
                    }

                    char buf[128] = "";
                    ssize_t bytes;
                    while(1)
                    {
                        if((bytes = read(fd_r, buf, sizeof(buf))) == -1)
                        {
                            perror("fail to read");
                            exit(1);
                        }

                        printf("from send: %s\n", buf);

                        fgets(buf, sizeof(buf), stdin);
                        buf[strlen(buf) - 1] = '\0';

                        write(fd_w, buf, sizeof(buf));
                    }

                    return 0;
                }


            对于上面这个两个代码，同时运行后还存在一个问题：由于代码相对而言还是比较简单的：对于send代码 必须写了才能读，对于receive代码 必须读了才能写，读和写之间有一定的牵制作用。
            如果想要读和写之间不再有任何关系，是他们不会相互干扰，可以使用多线程方式，如：创建父子进程，父进程用来读，子进程用来写。这样什么时候都能读和写。


        5.4.5 有名管道的读写规律（默认是阻塞的）
            特点一:
                不指定 O_NONBLOCK(即 open 没有位或 O_NONBLOCK)
                1、open 以只读方式打开 FIFO时，要阻塞到某个进程为写而打开此 FIFO
                2、open 以只写方式打开 FIFO时，要阻塞到某个进程为读而打开此 FIFO。

            5.4.5.1 读写端都存在，只读不写
                如果原本管道中有数据，则正常读取
                如果管道中没有数据，则read函数会阻塞等待
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <errno.h>
                    #include <fcntl.h>
                    #include <unistd.h>

                    int main(int argc, char const *argv[])
                    {
                        if(mkfifo("myfifo", 0664) == -1)
                        {
                            if(errno != EEXIST)
                            {
                                perror("fail to mkfifo");
                                exit(1);
                            }
                        }

                        //读写端都存在，只读不写
                        //如果原本管道中有数据，则正常读取
                        //如果管道中没有数据，则read函数会阻塞等待

                        int fd;
                        //读写打开管道
                        if((fd = open("myfifo", O_RDWR)) == -1)
                        {
                            perror("fail to open");
                            exit(1);
                        }

                        //先写一段话，
                        write(fd, "hello world", 11);

                        //读完
                        char buf[128] = "";
                        read(fd, buf, sizeof(buf));
                        printf("buf = %s\n", buf);
                        //读完再读
                        read(fd, buf, sizeof(buf));
                        printf("buf = %s\n", buf);

                        return 0;
                    }
            5.4.5.2 读写端都存在，只写不读
                    当有名管道的缓冲区写满后，write函数会发生阻塞
                    默认有名管道的缓冲区为64K字节
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <sys/types.h>
                        #include <sys/stat.h>
                        #include <errno.h>
                        #include <fcntl.h>
                        #include <unistd.h>

                        int main(int argc, char const *argv[])
                        {
                            if(mkfifo("myfifo", 0664) == -1)
                            {
                                if(errno != EEXIST)
                                {
                                    perror("fail to mkfifo");
                                    exit(1);
                                }
                            }

                            //读写端都存在，只写不读
                            //当有名管道的缓冲区写满后，write函数会发生阻塞
                            //默认有名管道的缓冲区为64K字节

                            int fd;
                            //读写打开
                            if((fd = open("myfifo", O_RDWR)) == -1)
                            {
                                perror("fail to open");
                                exit(1);
                            }

                            int num = 0;
                            while(1)
                            {
                                //一直写，每次写1024个字节，1k字节，写到64次，即64k之后程序阻塞。
                                write(fd, "", 1024);
                                num++;
                                printf("num = %d\n", num);
                            }

                            return 0;
                        }

            5.4.5.3 在一个进程中，只有读端，没有写端
                无名管道只读 (close(fd[1])) 返回0
                以只读方式打开 有名管道 会发生阻塞。

              * 在一个进程中，只有读端，没有写端,会在open函数的位置阻塞
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <sys/types.h>
                        #include <sys/stat.h>
                        #include <errno.h>
                        #include <fcntl.h>
                        #include <unistd.h>

                        int main(int argc, char const *argv[])
                        {
                            if(mkfifo("myfifo", 0664) == -1)
                            {
                                if(errno != EEXIST)
                                {
                                    perror("fail to mkfifo");
                                    exit(1);
                                }
                            }

                            //在一个进程中，只有读端，没有写端
                            //会在open函数的位置阻塞

                            printf("***********************\n");

                            int fd;
                            //只读打开
                            if((fd = open("myfifo", O_RDONLY)) == -1)
                            {
                                perror("fail to open");
                                exit(1);
                            }

                            printf("------------------------\n");

                            char buf[128] = "";
                            ssize_t bytes;

                            //在5.4.5.5中测试2.时打开
//                            while(1)
//                            {
                                if((bytes = read(fd, buf, sizeof(buf))) == -1)
                                {
                                    perror("fail to read");
                                    exit(1);
                                }

                                printf("bytes = %ld\n", bytes);
                                printf("buf = %s\n", buf);
//                            }

                            return 0;
                        }
            5.4.5.4 在一个进程中，只有写端，没有读端
                    在一个进程中，只有写端，没有读端 会在open函数的位置阻塞
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <sys/types.h>
                        #include <sys/stat.h>
                        #include <errno.h>
                        #include <fcntl.h>
                        #include <unistd.h>

                        int main(int argc, char const *argv[])
                        {
                            if(mkfifo("myfifo", 0664) == -1)
                            {
                                if(errno != EEXIST)
                                {
                                    perror("fail to mkfifo");
                                    exit(1);
                                }
                            }

                            //在一个进程中，只有写端，没有读端
                            //会在open函数的位置阻塞

                            printf("*****************************\n");

                            int fd;
                            if((fd = open("myfifo", O_WRONLY)) == -1)
                            {
                                perror("fail to open");
                                exit(1);
                            }

                            printf("-----------------------------\n");

                            //在5.4.5.5中测试2.时打开
//                            while(1)
//                            {
                                write(fd, "hello world", 11);
                                printf("666\n");

                                sleep(1);
//                            }

                            return 0;
                        }
            5.4.5.5 一个进程只读，一个进程只写
            1.
                将只读4.5.3和只写4.5.4同时运行,保证有名管道读写端都存在,两个进程都不会再阻塞。都能够正常运行。
                规律：
                    只要保证有名管道读写端都存在,不论是几个进程,open函数都不会再阻塞了。
            2.当运行增加了while循环的代码时，在正常运行时把写端关闭，读端会陷入死循环，并且bytes变为0，
                如果一个进程只读，一个进程只写，都运行后，如果关闭写端，读端read会返回0
                如果一个进程只读，一个进程只写，都运行后，如果关闭读端，写端会立即产生SIGPIPE信号，默认处理方式是退出进程。


        5.4.6 有名管道的读写规律（非阻塞）
            特点二:
            指定O_NONBLOCK(即 open 位或 O_NONBLOCK)
            1、先以只读方式打开:如果没有进程已经为写而打开一个FIFO，只读open 成功，并且open 不阻塞。
            2、先以只写方式打开:如果没有进程已经为读而打开一个FIFO，只写 open将出错返回-1。
            3、read、write 读写命名管道中读数据时不阻塞。
            4、通信过程中，读进程退出后，写进程向命名管道内写数据时，写进程也会(收到SIGPIPE 信号)退出。

            例：
                    #include <stdio.h>
                    #include <string.h>
                    #include <unistd.h>
                    #include <sys/types.h>
                    #include <sys/stat.h>
                    #include <fcntl.h>
                    #include <errno.h>
                    #include <stdlib.h>

                    int main(int argc, char *argv[])
                    {
                        int fd;

                        if(mkfifo("myfifo", 0664) == -1)
                        {
                            if(errno != EEXIST)
                            {
                                perror("fail to mkfifo");
                                exit(1);
                            }
                        }
                    #if 0
                        //如果open标志位设置为非阻塞，并且以只读的方式打开管道文件
                        //open函数和read函数都不会阻塞
                        fd = open("myfifo", O_RDONLY | O_NONBLOCK);
                        if(fd < 0)
                        {
                            perror("open fifo");
                            exit(1);
                        }

                        while(1)
                        {
                            char recv[100];

                            bzero(recv, sizeof(recv));
                            read(fd, recv, sizeof(recv));
                            printf("read from my_fifo buf=[%s]\n",recv);
                            sleep(1);
                        }
                    #endif

                    #if 1
                        //如果open标志位设置为非阻塞，并且以只写的方式打开管道文件
                        //open函数会直接报错:open fifo: No such device or address

                        //如果open设置为可读可写，那么跟阻塞是一样的效果
                        char send[100] = "Hello I love you";

                        fd = open("myfifo", O_WRONLY | O_NONBLOCK);
                        // fd = open("myfifo", O_RDWR | O_NONBLOCK);
                        if(fd < 0)
                        {
                            perror("open fifo");
                            exit(1);
                        }
                        write(fd, send, strlen(send));
                        // printf("write from my_fifo buf=[%s]\n",send);

                        char recv[100];
                        read(fd, recv, sizeof(recv));
                        printf("read from my_fifo buf=[%s]\n",recv);
                    #endif

                        return 0;
                    }


*/

//第六章：消息队列：
/*
    6.1
        一、IPC对象
            除了最原始的进程间通信方式信号、无名管道和有名管道外，还有三种进程间通信方式，这三种方式 称之为IPC对象。

            IPC对象的分类： 消息队列、共享内存、信号量（信号等级）

            IPC对象也是在内核空间开辟区域，每一种IPC对象创建好之后都会将其设置为全局，并且会给其分配一个编号，只要找到唯一的这个编号。就可以进行通信，所以不相关的进程可以通过IPC对象 通信。

            IPC对象创建好之后，会在当前系统中可见，只要不删除或者不关闭系统就会一直存在。

        查看已经创建的IPC对象：
            命令：
                ipcs      查看当前系统中所有创建的IPC对象。
                ipcs -q   查看创建的消息队列
                ipcs -m   查看创建的共享内存
                ipcs -s   查看信号量

                ipcrm     删除IPC对象
                    例如：ipcrm -q msqid  删除标号为msqid的消息队列7ul

            例：
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/5_pipe_fifo$ ipcs

                    --------- 消息队列 -----------
                    键        msqid      拥有者  权限     已用字节数 消息

                    ------------ 共享内存段 --------------
                    键        shmid      拥有者  权限     字节     连接数  状态
                    0x00000000 6          qinmei     600        524288     2          目标
                    0x00000000 32779      qinmei     600        524288     2          目标
                    0x00000000 131087     qinmei     606        1456920    2          目标
                    0x00000000 131088     qinmei     606        1456920    2          目标
                    0x00000000 20         qinmei     600        524288     2          目标
                    0x00000000 131103     qinmei     600        524288     2          目标
                    0x00000000 32         qinmei     600        524288     2          目标
                    0x00000000 40         qinmei     600        8388608    2          目标
                    0x00000000 32816      qinmei     600        4194304    2          目标

                    --------- 信号量数组 -----------
                    键        semid      拥有者  权限     nsems

    6 消息队列
        消息队列是消息的链表，存放在内存中，由内核维护

        6.1 消息队列概述

        消息队列的特点
            1、消息队列中的消息是 有类型的。
            2、消息队列中的消息是 有格式的。
            3、消息队列可以实现消息的随机査询。消息 不一定以 先进先出的次序 读取，编程时可以按消息的类型读取。
            4、消息队列允许 一个 或 多个进程 向它写入 或者 读取消息。
            5、与无名管道、命名管道一样，从消息队列中读出消息，消息队列中对应的数据都会被删除。
            6、每个消息队列 都有 消息队列标识符，消息队列的标识符 在整个系统中 是唯一的。       （找到同一个消息队列即可通信)
            7、只有 内核重启 或 人工删除消息队列 时，该 消息队列 才会被制除。若 不人工删除消息队列，消息队列会一直存在于系统中。

            在 ubuntu 12.04中消息队列限制值如下:
                每个消息内容最多为8K字节
                每个消息队列容量最多为16K字节
                系统中消息队列个数最多为1609个
                系统中消息个数最多为16384个

            System V 提供的IPC 通信机制 需要一个key 值，通过key 值就可在系统内获得一个唯一的消息队列标识符
            key 值可以是人为指定的，也可以通过 ftok 函数获得。
            如果多个进程想通过IPC对象通信，则必须找到唯一的标识，而唯一的标识是由key值决定的，所以只要key已知，就可以实现多个进程通信
            (这句话告诉我们如何获得唯一的IPC对象-----通过key值。也就意味着多个进程想要操作同一个IPC对象，则应该至少保证key值是一样的，只要key值一样，就能够找到相同的IPC对象)

        6.1.1 ftok函数
            #include <sys/types.h>
            #include <sysipc h>

            key_t ftok(const char *pathname, int proj_id);
            功能:
                获得项目相关的唯一的 IPC 键值  （获取项目唯一的键值）
            参数:
                pathname: 路径名
                proj_id：  项目 ID，非0整数(只有低8 位有效)（0~127）
            返回值:
                成功返回 key 值，
                失败返回 -1

            如果使用ftok函数获取键值，得到的键值 是由 ftok的第一个参数对应文件的信息 和 第二个参数 一起决定的。

            例：
                只要保证ftok的第一个参数对应的文件 和 第二个参数值 相同，则不管程序运行多少遍 或者 多少个进程 获得的键值一定都是唯一的
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <sys/types.h>
                    #include <sys/ipc.h>

                    int main(int argc, char const *argv[])
                    {
                        //使用ftok函数获取键值
                        //只要保证ftok的第一个参数对应的文件和第二个参数值相同，则不管程序运行多少遍或者多少个进程或者键值
                        //键值一定都是唯一的
                        key_t mykey;
                        if((mykey = ftok(".", 100)) == -1)  //第一个参数传当前目录（当前目录也是文件），第二个参数随便传，但他值获取低八位。
                        {
                            perror("fail to ftok");
                            exit(1);
                        }

                        //由于使用ipcs命令在终端查看时，键值打印的是16进制的，所以我们也使用十六进制进行打印。
                        printf("key = %#x\n", mykey);
                        //key = 0x640548ee

                        return 0;
                    }

        6.2 消息队列的操作
            6.2.1 创建消息队列

                #include <sys/msg.h>
                int msgget(key_t key, int msgflg):
                功能:
                    创建一个新的 或 打开一个己经存在的 消息队列。不同的进程调用此函数，只要用相同的key值就能得到同一个消息队列的标识符。
                参数:
                    key:    IPC 键值。
                            (键值，唯一的键值确定唯一的消息队列)
                            获取key值的方法：
                                1. 任意指定一个属
                                2.使用ftok函数获取键值。
                    msgflg: 标识函数的 行为 及 消息队列的 权限
                            (消息队列的访问权限，一般设置为IPC_CREAT | IPC_EXCL | 0777 或者 IPC_CREAT | 0777)

                        msgflg的取值:

                            IPC CREAT:创建消息队列。
                            IPC_EXCL:检测消息队列是否存在
                        位或权限位:消息队列位或权限位后可以设置消息队列的访问权限，格式和open 函数的 mode_t一样，但可执行权限未使用。
                返回值:
                    成功:消息队列的标识符，
                    失败:返回-1，

                使用 she11命令操作消息队列:
                    查看消息队列
                        ipcs -q
                    删除消息队列：
                        ipcrm -q msqid

            消息队列的消息的格式。
            typedef struct _msg
            {
                long mtype;     //消息类型
                char mtext[100];//消息正文
                ... //消息的正文可以有多个成员
            }MSG;

            消息类型必须是长整型的，而且必须是结构体类型的第一个成员，类型下面是消息正文，正文可以有多个成员(正文成员可以是任意数据类型的)

             案例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <sys/types.h>
                        #include <sys/ipc.h>
                        #include <sys/msg.h>

                        int main(int argc, char const *argv[])
                        {
                            //通过ftok函数获取ipc键值
                            key_t mykey;
                            if((mykey = ftok(".", 100)) == -1)
                            {
                                perror("fail to ftok");
                                exit(1);
                            }

                            //打印键值
                            printf("mykey = %#x\n", mykey);

                            //通过msgget函数创建一个消息队列
                            int msqid;
                            if((msqid = msgget(mykey, IPC_CREAT | 0666)) == -1)
                            {
                                perror("fail to msgget");
                                exit(1);
                            }

                            printf("msqid = %d\n", msqid);

                            //system 可以直接执行一个命令。
                            system("ipcs -q");

                            return 0;
                        }



                6.2.2 发送消息
                #include<sys/msg.h)

                int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg):
                功能:
                    将新消息添加到消息队列。
                参数:
                    msqid:消息队列的标识符,(消息队列的id)
                    msgp:待发送消息结构体的地址。(要写入的数据，需要自己定义结构体)
                            struct struct_name{
                                long mtype; //消息的编号，必须大于0
                                char mtext[128]; //消息正文，可以定义多个成员
                            }

                    msgsz:消息正文的字节数。（消息正文的大小，不包括消息的编号长度）
                    msgflg:函数的控制属性  （标志位：0 阻塞 IPC_NOWAIT 非阻塞）
                        0:msgsnd.调用阻塞直到条件满足为止。
                        IPC_NOWAIT:若消息没有立即发送则调用该函数的进程会立即返回
                返回值:
                    成功:0;
                    失败:返回-1。

                例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <sys/types.h>
                        #include <sys/ipc.h>
                        #include <sys/msg.h>

                        #define N 128

                        typedef struct{
                            long msg_type; //消息类型，必须在结构体的第一个位置并且类型必须是long
                            char msg_text[N]; //消息正文，也可以有多个成员并且类型也可以是任意
                        }MSG;

                        #define MSGTEXT_SIZE (sizeof(MSG) - sizeof(long))

                        int main(int argc, char const *argv[])
                        {
                            //使用ftok函数获取键值
                            key_t key;
                            if((key = ftok(".", 100)) == -1)
                            {
                                perror("fail to ftok");
                                exit(1);
                            }

                            //使用msgget函数创建一个消息队列
                            int msgid;
                            if((msgid = msgget(key, IPC_CREAT | 0777)) == -1)
                            {
                                perror("fail to msgget");
                                exit(1);
                            }

                            system("ipcs -q");

                            //使用msgsnd函数向消息队列中发送数据（写操作）
                            MSG msg1 = {1, "hello world"};
                            MSG msg2 = {4, "nihao beijing"};
                            MSG msg3 = {2, "hello kitty"};
                            MSG msg4 = {3, "welcome to 1000phone"};

                            if(msgsnd(msgid, &msg1, MSGTEXT_SIZE, 0) == -1)
                            {
                                perror("fail to msgsnd");
                                exit(1);
                            }

                            if(msgsnd(msgid, &msg2, MSGTEXT_SIZE, 0) == -1)
                            {
                                perror("fail to msgsnd");
                                exit(1);
                            }

                            if(msgsnd(msgid, &msg3, MSGTEXT_SIZE, 0) == -1)
                            {
                                perror("fail to msgsnd");
                                exit(1);
                            }

                            if(msgsnd(msgid, &msg4, MSGTEXT_SIZE, 0) == -1)
                            {
                                perror("fail to msgsnd");
                                exit(1);
                            }

                            system("ipcs -q");


                            return 0;
                        }


                6.2.3 接收消息

                    #include<sys/msg. h>
                    ssize_t msgrcv(int msqid, void *msgp size_t msgsz, long msgtyp, int msgflg):
                    功能:
                        从标识符为msqid 的消息队列中接收一个消息。一旦接收消息成功，则消息在消息队列中被删除。
                    参数:
                        msqid:消息队列的标识符，代表要从哪个消息列中获取消息，
                        msgp:存放消息结构体的地址。
                        msgsz:消息正文的字节数。
                        msgtyp:消息的类型、可以有以下几种类型
                                msgtyp =0:返回队列中的第一个消息
                                msgtyp >0:返回队列中消息类型为msgtyp, 的消息
                                msgtyp<0:返回队列中消息类型值小于或等于 msgtxp,绝对值的消息，如果这种消息有若千个，则取类型值最小的消息。
                    注意:
                        若消息队列中有多种类型的消息，msgrcv,获取消息的时候按消息类型获取，不是先进先出的。
                        在获取某类型消息的时候，若队列中有多条此类型的消息，则获取最先添加的消息，即先进先出原则。


                6.2.4 消息队列的控制
                    #include<sys/msg h
                int msgctl(int msqid, int cmd, struct msqid ds *buf);
                功能:
                    对消息队列进行各种控制，如修改消息队列的属性，或除消息消息队列
                参数:
                    msqid:消息队列的标识符
                    cmd:函数功能的控制。
                    buf:msgid ds数据类型的地址，用来存放或更改消息队列的属性

                    cmd:函数功能的控制
                        IPC_RMID:删除由 msqid指示的消息队列，将它从系统中删除 并 破坏相关数据结构。
                        IPC_STAT:将 msqid 相关的数据结构中 各个元素的当前值 存入到由 buf指向的结构中。
                        IPC_SET:将msqid,相关的数据结构中的元素设置为由 buf 指向的结构中的对应值。
                返回值：
                    成功:0;
                    失败:返回-1。


            例：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <unistd.h>
                        #include <sys/types.h>
                        #include <sys/ipc.h>
                        #include <sys/msg.h>

                        int main(int argc, char const *argv[])
                        {
                            //使用ftok函数获取键值
                            key_t key;
                            if((key = ftok(".", 100)) == -1)
                            {
                                perror("fail to ftok");
                                exit(1);
                            }

                            //使用msgget函数创建一个消息队列
                            int msgid;
                            if((msgid = msgget(key, IPC_CREAT | 0777)) == -1)
                            {
                                perror("fail to msgget");
                                exit(1);
                            }

                            printf("msgid = %d\n", msgid);
                            system("ipcs -q");

                            //通过msgctl函数删除消息队列
                            if(msgctl(msgid, IPC_RMID, NULL) == -1)
                            {
                                perror("fail to msgctl");
                                exit(1);
                            }

                            system("ipcs -q");

                            return 0;
                        }


*/

//第七章：共享内存
//共享内存是效率最高的进程间通信方式
/*
    7.1 共享内存概述：
        共享内存允许两个 或者 多个进程 共享 给定的存储区域。
    共享内存的特点
        1、 共享内存是进程间共享数据的一种最快的方法。
            一个进程 向共享的内存区域写入了数据，共享这个内存区域的所有进程
   就可以立刻看到其中的内容。
        2、使用共享内存要注意的是多个进程之间对一个给定存储区访问的互斥。（同一时间
   只能 读或者写）
            若一个进程正在向共享内存区写数据，则在它做完这一步操作前，别的进程不应当去读、写这些数据。


        共享内存示意图
                                    物理内存
        进程A的逻辑地址空间                                  进程B的逻辑地址空间

            4G虚拟内存           ———>                      4G虚拟内存
            前3G的用户空间是不能            <------         前3G的用户空间是不能
            相互沟通的                                     相互沟通的

            1G的内核空间       -->   共享内存   <--          1G的内核空间
            是可以沟通的                                    是可以沟通的

        (左右两边是每一个进程在创建的时候分配的4G的虚拟内存(3G的用户空间 和
   1G的内核空间)，中间的
   是物理内存，这两个进程的前3个G的用户空间是私有的，因此这3G的进程空间最终对应的物理内存的位置是不同的。
        所以 进程A 与 进程B 的用户空间是不能进行沟通的，而两个进程1G的内核空间
   对应的物理空间（共享内存） 是相同的。) （共享内存通信 之所以快，是因为
   共享内存对应的 多个进程
   能够直接操作物理内存的，也就是说，共享内存可以把物理地址交给我们的用户，由我们的
   用户进行 对其地址 进行的操作，就是直接对物理内存的操作）

      * 总结:
             共享内存
   是进程间通信方式中效率最高的，原因在于进程是直接在物理内存上进行操作，将物理地址映射到用户进程这儿，所以只要对其地址进行操作，就是直接对物理地址操作。

        注意：
            在 ubuntu 12.04中 共享内存限制值 如下
            1、共享存储区的最小字节数:1
            2、共享存储区的最大字节数:32M
            3、共享存储区的最大个数:4096
            4、每个进程最多能映射的共享存储区的个数:4096


    7.2 共享内存操作
        7.2.1 获得一个共享存储标识
            #include <sys/ipc.h>
            #include <sys/shm.h>

            int shmget(key _tkey, size_t size,int shmflg):
            功能:
                创建或打开一块共享内存区
            参数:
                key: IPC 键值
                size:该共享存储段的长度(字节)
                shmflg:标识函数的行为及共享内存的权限
                    IPC_CREAT:如果不存在就创建
                    IPC_EXCL:如果已经存在则返回失败
                    位或权限位:共享内存位或权限位后可以设置共享内存的访问权限，格式和open函数的
   mode_t一样，但可执行权限未使用。 返回值: 成功:返回共享内存标识符
                失败:返回一1。

                使用 shell命令操作共享内存:
                查看共享内存
                    ipcs -m
                删除共享内存
                    ipcrm -m shmic

        例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <sys/ipc.h>
                    #include <sys/shm.h>

                    int main(int argc, char const *argv[])
                    {
                        //使用ftok函数获取键值
                        key_t mykey;
                        if((mykey = ftok(".", 100)) == -1)
                        {
                            perror("fail to ftok");
                            exit(1);
                        }

                        //通过shmget函数创建或者打开一个共享内存，返回一个共享内存的标识符id
                        int shmid;
                        //参数1:键值    参数2:共享内存存储段大小
   参数3:表示函数的行为或 共享内存权限. if((shmid = shmget(mykey, 500, IPC_CREAT
   | 0666)) == -1)
                        {
                            perror("fail to shmget");
                            exit(1);
                        }
                        //执行结果:
                    //
   qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/7_share_memory$
   ./a.out
                    // shmid = 131132

                    // ------------ 共享内存段 --------------
                    // 键         shmid      拥有者      权限        字节 连接数
   状态
                    // 0x00000000 32816      qinmei     600        4194304    2
   目标
                    // 0x00000000 131128     qinmei     606        1456920    2
   目标
                    // 0x00000000 131129     qinmei     606        1456920    2
   目标
                    // 0x6405490f 131132     qinmei     666        500        0

                        printf("shmid = %d\n", shmid);

                        system("ipcs -m");

                        return 0;
                    }


        7.2.2 共享内存映射（attach）

            #include <sys/types.h>
            #include<sys/shm. h>

            void *shmat(int shmid, const void *shmaddr,int shmflg)
            功能:
                将一个共享内存段映射到调用进程的数据段中
            参数:
                shmid:共享内存标识符。
                shmaddr:共享内存映射地址(若为NULL 则由系统自动指定)，推荐使用
   NULL。 shmflg:共享内存段的访问权限和映射条件 0:共享内存具有可读可写权限。
                        SHM_RDONLY: 只读。
                        SHM_RND:(shmaddr,非空时才有效)
                            没有指定 SHM_RND 则此段连接到
   shmaddr,所指定的地址上(shmaddr 必需页对齐) 指定了 SHM_RND 则此段连接到
   （shmaddr - shmaddr%SHMLBA ）所表示的地址上。 返回值:
              * 成功:返回共享内存段映射地址
                失败:返回-1

            注意:
                shmat 函数使用的时候第二个 和 第三个参敗 一般设为NULL 和
   0，即系统自动指定共享内存地址，并且共享内 存可读可写。


        7.2.3 解除共享内存映射
            #include <sys/types.h>
            #include <sys/shm.h>

            int shmdt(const void *shmaddr);
            功能:
                将 共享内存 和 当前进程 分离(仅仅是断开联系并不删除共享内存)
            参数:
                shmaddr:共享内存映射地址.
            返回值:
                成功返回 0，
                失败返回 -1。

        案例2.4 ：使用共享内存实现读写操作：
    02_shmat_shmdt_write.c:
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <sys/ipc.h>
                    #include <sys/shm.h>
                    #include <string.h>

                    typedef struct{
                        int a;
                        char b;
                    }MSG;

                    //往共享内存写数据
                    int main(int argc, char const *argv[])
                    {
                        //使用ftok函数获取键值
                        key_t mykey;
                        if((mykey = ftok(".", 100)) == -1)
                        {
                            perror("fail to ftok");
                            exit(1);
                        }

                        //通过shmget函数创建或者打开一个共享内存，返回一个共享内存的标识符
                        int shmid;
                        if((shmid = shmget(mykey, 500, IPC_CREAT | 0666)) == -1)
                        {
                            perror("fail to shmget");
                            exit(1);
                        }

                        system("ipcs -m");

                        //使用shmat函数映射共享内存的地址
                        //char *text;
                        MSG *text;
                        //由于返回值是void *
   且失败返回-1,所以为了避免未知出错,将-1强转为void*类型 if((text = shmat(shmid,
   NULL, 0)) == (void *)-1)
                        {
                            perror("fail to shmat");
                            exit(1);
                        }

                        //通过shmat的返回值对共享内存操作
                        //strcpy(text, "hello world");
                        text->a = 100;
                        text->b = 'w';

                        //操作完毕后要接触共享内存的映射
                        if(shmdt(text) == -1)
                        {
                            perror("fail to shmdt");
                            exit(1);
                        }

                        system("ipcs -m");

                        return 0;
                    }


        03_shmat_shmdt_read.c:
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <sys/ipc.h>
                    #include <sys/shm.h>

                    typedef struct{
                        int a;
                        char b;
                    }MSG;
                    //从共享内存读数据
                    int main(int argc, char const *argv[])
                    {
                        //使用ftok函数获取键值
                        key_t mykey;
                        if((mykey = ftok(".", 100)) == -1)
                        {
                            perror("fail to ftok");
                            exit(1);
                        }

                        //通过shmget函数创建或者打开一个共享内存，返回一个共享内存的标识符
                        int shmid;
                        if((shmid = shmget(mykey, 500, IPC_CREAT | 0666)) == -1)
                        {
                            perror("fail to shmget");
                            exit(1);
                        }

                        system("ipcs -m");

                        //映射共享内存的地址
                        //char *text;
                        MSG *text;
                        if((text = shmat(shmid, NULL, 0)) == (void *)-1)
                        {
                            perror("fail to shmat");
                            exit(1);
                        }

                        //获取共享内存中的数据
                        //printf("text = %s\n", text);
                        printf("a = %d, b = %c\n", text->a, text->b);

                        //解除共享内存映射
                        if(shmdt(text) == -1)
                        {
                            perror("fail to shmdt");
                            exit(1);
                        }

                        system("ipcs -m");

                        return 0;
                    }



        7.2.4 共享内存控制
            #include<sys/ipc.h>
            #include<sys/shm.h>

            int shmctl(int shmid, int cmd,struct shmid_ds *buf);
            功能:
                共享内存空间的控制，
            参数:
                shmid:共享内存标识符
                cmd:函数功能的控制。
                buf:shmid_ds 数据类型的地址，用来存放或修改共享内存的属性
                    不需要则可传NULL
            cmd:函数功能的控制
                    IPC_RWID:删除。
                    IPC_SET:设置 shmid_ds 参数。
                    IPC_STAT:保存 shmid_ds.参数
                    SHM_LOCK:锁定共享内存段(超级用户)。
                    SHM_UNLOCK:解锁共享内存段。
            返回值:
                成功返回 0，
                失败返回 -1。

        例：
                #include <stdio.h>
                #include <stdlib.h>
                #include <unistd.h>
                #include <sys/ipc.h>
                #include <sys/shm.h>

                int main(int argc, char const *argv[])
                {
                    //使用ftok函数获取键值
                    key_t mykey;
                    if((mykey = ftok(".", 100)) == -1)
                    {
                        perror("fail to ftok");
                        exit(1);
                    }

                    //通过shmget函数创建或者打开一个共享内存，返回一个共享内存的标识符
                    int shmid;
                    if((shmid = shmget(mykey, 500, IPC_CREAT | 0666)) == -1)
                    {
                        perror("fail to shmget");
                        exit(1);
                    }

                    printf("shmid = %d\n", shmid);

                    system("ipcs -m");

                    //通过shmctl函数删除共享内存
                    if(shmctl(shmid, IPC_RMID, NULL) == -1)
                    {
                        perror("fail to shmctl");
                        exit(1);
                    }

                    system("ipcs -m");

                    return 0;
                }





























*/

//第八章 线程
/*

    8.1线程概述
        8.1.1 线程的概念：线程是为了减小进程的开销创建出来的东西，并且存在于进程当中的。

            每个进程都拥有自己的数据段、代码段和堆 栈段（数据段、代码段和堆 栈段 就是其 私有的 用户空间）。(4G虚拟内存)
            这就造成进程在进行创建、切换、撤销操作时，需要较大的系统开销（多个进程之间是 时间片轮转，上下文切换的，会将 第一个进程的用户空间 切换到 第二个进程的用户空间 ，因此比较浪费时间；创建进程又极耗费空间）。

            为了减少系统开销，从进程中演化出了线程。（线程是在进程中创建的）
            线程存在于进程中，共享进程的资源。     （线程存在于进程的用户空间的，共享进程的（用户空间）资源）
            线程是进程中的独立控制流，由环境(包括寄存器组和程序计数器)和一系列的执行指令组成。

        每个进程有一个地址空间和一个控制线程。
        （由于线程是存在于进程当中的，那么创建一个进程的时候，也会去创建它的线程。只是当没有其它子线程的时候，我们不会过多关注这个线程，
          但如果有多个线程的时候，我们就需要去研究它。我们有时候称这个线程为 主控线程 或 控制线程）

          图解：
                   |—————————————————|
                   |     进程         |
                   |    ——————————    |
                   |    | 线程A栈  |   |
                   |    | 线程B栈  |   |
                   |    | 堆区    |   |
                   |    | BSS区   |    |
                   |    | 数据区   |   |
                   |    | 代码区   |   |
                   |    ———————————   |
                   |——————————————————|

            相当于：每一个线程的 栈区 是私有的，而其他区是 共有 还是 私有，要看你是在哪里开辟的空间，如果说你是在线程A里面在堆区开辟的空间，那么该空间与线程B没有什么关系（除非线程A要给B）。



        8.1.2 线程 和 进程 的比较
            调度:
              * 线程是 CPU 调度 和 分派的基本单位。
            拥有资源:
              * 进程 是 系统中 程序执行 和 资源分配 的基本单位。

                线程自己一般不拥有资源(除了必不可少的程序计数器，一组寄存器 和 栈)，但它 可以去访问 其所属进程 的资源，
                  如进程代码段，数据段以及系统资源(已打开的文件（如：获得的文件描述符）、I/O设备(如键盘)等)。

            系统开销:
                同一个进程中的 多个线程 可共享 同一地址空间(即：多个线程共享一个进程)，因此它们之间的同步和通信的实现也变得比较容易，
                在进程切换时候，涉及到整个当前进程 CPU环境的保存以及新被调度运行的进程的CPU环境的设置:而线程
                切换只需要保存和设置少量寄存器的内容，并不涉及存储器管理方面的操作，从而能更有效地使用系统资源和提
                高系统的吞吐量。
            并发性:
                不仅 进程间 可以 并发执行 ，而且 在一个进程中的 多个线程之间 也可以 并发执行。

            总结：
                1.一般把线程称之为 轻量级的进程
                2.一个进程可以创建多个进程；多个线程 共享 一个进程 的资源。
                3.每一个进程创建的时候，系统会给其 4G虚拟内存。3G的用户空间是私有的，所以进程间切换时，用户空间也会切换，所以会增加系统开销。
                  而一个进程中的 多个线程 共享 一个进程的资源，所以 线程间切换时，不用切换这些资源，效率会更高。
                4.线程的调度机制 与 进程是一样的，多个线程来回切换运行（时间片轮转，上下文切换）


        8.1.3 多线程的用处
            使用多线程的目的主要有以下几点:
                1.多任务程序的设计
                    一个程序可能要处理不同应用，要处理多种任务，如果开发不同的进程来处理，系统开销很大，数据共享，
                    程序结构都不方便，这时可使用多线程编程方法。

                2.并发程序设计(线程的同步 与 互斥)
                    一个任务可能分成不同的步骤去完成，这些不同的步骤之间可能是松散耦合，可能通过线程的互斥，同步并发完成。这样可以为不同的任务步骤建立线程。

                3.网络程序设计（网络编程中，在同一时间，所登录的qq有很多，但服务器只有一些，服务器就是通过多线程的方式分清到底处理的是谁的用户登录。）
                    为提高网络的利用效率，我们可能使用多线程，对每个连接用一个线程去处理。

                4.数据共享
                    同一个进程中的不同线程共享进程的数据空问，方便不同线程间的数据共享。

                5.在多 CPU系统中，实现真正的并行
                        例如：网盘下载（软件不能改变你的网速它是通过线程的个数来优化的）：vip用户有10个线程去下载，普通用户只有一个线程下载。在同一时间vip用户对于cpu资源的抢占要比普通用户多。所以其下载速度快。


    8.2 线程的基本操作：
        就像每个进程都有一个进程号一样，每个线程也有一个线程号。

        进程号 在整个系统中是唯一的，但 线程号不同，线程号只在它所属的进程环境中有效。

        进程号 用 pid_t 数据类型表示，是一个非负整数。线程号则用 pthread_t 数据类型来表示。(类整型的数据类型)

        有的系统在实现 pthread_t的时候，用一个结构体来表示，所以在 可移植的操作系统实现 不能把它做为 整数处理。(大多数的pthread_t是类整型的数据类型，少数是结构体)

        8.2.1 线程的创建
            头文件:
                #include<pthread.h>

            int pthread_create(pthread_t *thread, const pthread attr_t *attr, void *(*start routine)(void *) , void *arg);
            功能:
                创建一个线程。
            参数:
                thread:         线程标识符地址。（线程号，只不过传的是一个地址）
                attr:           线程属性结构体地址 （可以设置线程的属性，使用默认属性，则传NULL）
                                    （对于进程：我们使用fork创建父子进程后，通过判断返回值区分父子进程（>0 父进程 ；=0 子进程 ）
                                    而线程的区分，是通过一个函数去指定的，所以一个函数 就相当于 当前线程的执行体，函数结束也就意味着当前线程结束了)
                start_routine:  线程函数的入口地址（线程函数的入口地址）
                arg:            传给线程函数的参数。
            返回值：
                成功：返回0
                失败：返回非0

    注意事项：
        与 fork 不同的是 pthread_create 创建的线程 不与 父线程 在同一点 开始运行，而是从指定的函数开始运行，该函数运行完后，该线程也就退出了，
        线程依赖进程存在的，如果创建线程的进程结束了，线程也就结束了。
        线程函数的程序在 pthread 库中，故链接时要加上参数 -1pthread.
         （即：由于线程库原本不是系统本身的，所以在链接时需要手动链接库文件 gcc *.c -lpthread 例：gcc 01_pthread_create_1.c -lpthread）


    案例1：
                #include <stdio.h>
                #include <stdlib.h>
                #include <pthread.h>

                //由于线程库原本不是系统本身的，所以在链接时需要手动链接库文件 gcc *.c -lpthread

                void *thread_fun(void *arg)
                {
                    printf("子线程正在运行\n");
                }

                int main(int argc, char const *argv[])
                {
                    printf("主控线程正在执行\n");

                    pthread_t thread;

                    //通过pthread_create函数创建子线程
                    if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                    {
                        perror("fail to pthread_create");
                        exit(1);
                    }

                    //由于进程结束后，进程中所有的线程都会强制退出，所以现阶段不要让进程退出
                    while(1);

                    return 0;
                }
//          执行结果：
//                主控线程正在执行
//                子线程正在运行



    案例2.1.2： 线程调度机制的验证：
            一个进程中的 *多个线程执行顺序是不确定的*，没有先后顺序可言
            多线程执行时跟进程一样，*是来回切换运行的*，跟进程的调度机制一样

                #include <stdio.h>
                #include <stdlib.h>
                #include <pthread.h>
                #include <unistd.h>

                //一个进程中的多个线程执行顺序是不确定的，没有先后顺序可言
                //多线程执行时跟进程一样，是来回切换运行的，跟进程的调度机制一样

                void *pthread_fun1(void *arg)
                {
                    printf("子线程1正在运行\n");
                    sleep(1);
                    printf("**********************\n");
                }

                void *pthread_fun2(void *arg)
                {
                    printf("子线程2正在运行\n");
                    sleep(1);
                    printf("-----------------------\n");
                }

                int main(int argc, char const *argv[])
                {
                    pthread_t thread1, thread2;

                    if(pthread_create(&thread1, NULL, pthread_fun1, NULL) != 0)
                    {
                        perror("fail to pthread_create");
                    }

                    if(pthread_create(&thread2, NULL, pthread_fun2, NULL) != 0)
                    {
                        perror("fail to pthread_create");
                    }

                    while(1);

                    return 0;
                }
//        执行结果：
//            子线程1正在运行
//            子线程2正在运行
//            **********************
//            -----------------------




    案例2.1.3： 线程处理函数的传参：

            // //1.不传参,测试 子线程 能否调用 全局变量,以及子线程对全局变量影响
            // #include <stdio.h>
            // #include <stdlib.h>
            // #include <pthread.h>
            // #include <unistd.h>

            // int num = 100;

            // //线程处理函数可以认为就是一个普通的全局函数，只不过与普通函数最大的区别
            // //在于，线程处理函数是并行执行，来回交替执行，但是普通函数一定是按照顺序一个一个执行
            // void *pthread_fun1(void *arg)
            // {
            //     printf("子线程1：num = %d\n", num);
            //     num++;
            // }

            // void *pthread_fun2(void *arg)
            // {
            //     sleep(1);
            //     printf("子线程2：num = %d\n", num);
            // }

            // int main(int argc, char const *argv[])
            // {
            //     pthread_t thread1, thread2;

            //     int a = 666;

            //     if(pthread_create(&thread1, NULL, pthread_fun1, NULL) != 0)
            //     {
            //         perror("fail to pthread_create");
            //     }

            //     if(pthread_create(&thread2, NULL, pthread_fun2, NULL) != 0)
            //     {
            //         perror("fail to pthread_create");
            //     }

            //     while(1);
            //     // 执行结果:
            //     //     子线程1：num = 100
            //     //     子线程2：num = 101


            //     return 0;
            // }


            //2.测试传参
            #include <stdio.h>
            #include <stdlib.h>
            #include <pthread.h>
            #include <unistd.h>

            int num = 100;

            //线程处理函数可以认为就是一个普通的全局函数，只不过与普通函数最大的区别
            //在于，线程处理函数是并行执行，来回交替执行，但是普通函数一定是按照顺序一个一个执行
            void *pthread_fun1(void *arg)
            {
                printf("子线程1：num = %d\n", num);
                num++;

                int n = *(int *)arg;
                printf("1 n = %d\n", n);
                *(int *)arg = 111;
            }

            void *pthread_fun2(void *arg)
            {
                sleep(1);
                printf("子线程2：num = %d\n", num);

                int n = *(int *)arg;
                printf("2 n = %d\n", n);
            }

            int main(int argc, char const *argv[])
            {
                pthread_t thread1, thread2;

                int a = 666;

                if(pthread_create(&thread1, NULL, pthread_fun1, (void *)&a) != 0)
                {
                    perror("fail to pthread_create");
                }

                if(pthread_create(&thread2, NULL, pthread_fun2, (void *)&a) != 0)
                {
                    perror("fail to pthread_create");
                }

                while(1);

                return 0;
            }

        8.2.2 线程的等待
            #include <pthread.h>

            int pthread_join(pthread_t thread, void **retval)
            功能:
                父线程 等待 子线程 结束，并 *回收子线程资源* 。
                (但是这个函数是一个阻塞函数，如果子线程不退出，就会导致当前进程（主控线程）无法继续执行)
            参数:
                tread:被等待的线程号。（指定线程的id）
                retval:用来存储线程退出状态的指针的地址(保存子线程的退出状态值，如果不接受,则设置为NULL)
            返回值:
                成功返回 0，
                失败返回非0。

        案例2.2.1：通过pthread_join函数等待子线程退出

                // #include <stdio.h>
                // #include <stdlib.h>
                // #include <pthread.h>
                // #include <unistd.h>

                // void *thread_fun(void *arg)
                // {
                //     printf("子线程正在运行\n");

                //     sleep(3);

                //     printf("子线程要退出了\n");
                // }

                // int main(int argc, char const *argv[])
                // {
                //     printf("主控线程正在执行\n");

                //     pthread_t thread;

                //     if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                //     {
                //         perror("fail to pthread_create");
                //         exit(1);
                //     }

                //     printf("进程要退出了\n");
                // //  执行结果：
                // //         主控线程正在执行
                // //         进程要退出了

                //     return 0;
                // }


                #include <stdio.h>
                #include <stdlib.h>
                #include <pthread.h>
                #include <unistd.h>

                void *thread_fun(void *arg)
                {
                    printf("子线程正在运行\n");

                    sleep(3);

                    printf("子线程要退出了\n");
                }

                int main(int argc, char const *argv[])
                {
                    printf("主控线程正在执行\n");

                    pthread_t thread;

                    if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                    {
                        perror("fail to pthread_create");
                        exit(1);
                    }

                    //通过调用pthread_join函数阻塞等待子线程退出
                    if(pthread_join(thread, NULL) != 0)
                    {
                        perror("fail to pthread_join");
                        exit(1);
                    }

                    printf("进程要退出了\n");
                // 执行结果：
                //     主控线程正在执行
                //     子线程正在运行
                //     子线程要退出了
                //     进程要退出了
                    return 0;
                }


        案例2.2.2：通过pthread_join获取子线程的退出状态值。

                #include <stdio.h>
                #include <stdlib.h>
                #include <pthread.h>
                #include <unistd.h>

                void *thread_fun(void *arg)
                {
                    static int num = 666;
                    printf("子线程正在运行\n");

                    sleep(3);

                    printf("子线程要退出了\n");

                    //子线程如果要返回退出状态，可以通过返回值或者通过pthread_exit函数
                    return (void *)&num;
                }

                int main(int argc, char const *argv[])
                {
                    printf("主控线程正在执行\n");

                    pthread_t thread;

                    if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                    {
                        perror("fail to pthread_create");
                        exit(1);
                    }

                    int *num;
                    if(pthread_join(thread, (void **)&num) != 0)
                    {
                        perror("fail to pthread_join");
                        exit(1);
                    }

                    printf("ret_val = %d\n", *num);
                    printf("进程要退出了\n");

                // 执行结果：
                //     主控线程正在执行
                //     子线程正在运行
                //     子线程要退出了
                //     ret_val = 666
                //     进程要退出了

                    return 0;
                }

    8.2.3 线程分离（线程有两种状态：分离态 和 结合态）
        线程的结合态 和 分离态
            linux 线程执行 和 windows 不同。pthread 有两种状态:
                可结合的(joinable) 或者是 分离的(detached)。
                线程 默认创建为 可结合态，如果线程是 joinable 状态，
                当线程函数自己返回退出时 或 pthread_exit 时都不会释放 线程所占用堆栈 和 线程描述符(总计8K多)，
                只有当你调用了pthread_join之后，资源才会被释放回收。

                若是 detached 状态的线程，这些资源在线程函数退出时或 pthread_exit 时自动会被释放，
                使用 pthead_detach 函数将线程设置为分离态。

                创建一个线程后 应当 回收其资源，
                但使用pihread_join函数会使调用者阻塞，故Linux 提供了线程分离函数:pthread_detach。

        头文件:
            #include <pthread.h>

        int pthread_detach(pthread t thread);
        功能:
            使 调用线程 与 当前进程 分离，使其成为一个独立的线程，该线程终止时，系统将自动回收它的资源。
        参数:
            thread:线程号
        返回值:
            成功:返回 0，
            失败:返回非0。

    例：
                #include <stdio.h>
                #include <stdlib.h>
                #include <pthread.h>
                #include <unistd.h>

                void *thread_fun(void *arg)
                {
                    printf("子线程正在运行\n");

                    sleep(3);

                    printf("子线程要退出了\n");
                }

                int main(int argc, char const *argv[])
                {
                    printf("主控线程正在执行\n");

                    pthread_t thread;

                    if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                    {
                        perror("fail to pthread_create");
                        exit(1);
                    }

                #if 1
                    //通过pthread_detach函数将子线程设置为分离态，既不用阻塞，也可以自动回收子线程退出的资源
                    if(pthread_detach(thread) != 0)
                    {
                        perror("fail to pthread_detach");
                        exit(1);
                    }
                    //执行结果：
                    // 主控线程正在执行
                    // hello world
                    // 子线程正在运行
                    // hello world
                    // hello world
                    // 子线程要退出了
                    // hello world
                    // hello world

                #endif

                    //如果原本子线程是结合态，需要通过pthrad_join函数回收子线程退出的资源，
                    //但是这个函数是一个阻塞函数，如果子线程不退出，就会导致当前进程（主控线程）
                    //无法继续执行，大大的限制了代码的运行效率
                    //如果子线程已经设置为分离态，就不需要再使用pthread_join了
                    #if 0
                    if(pthread_join(thread, NULL) != 0)
                    {
                        perror("fail to pthread_join");
                        exit(1);
                    }
                    //执行结果：
                    // 主控线程正在执行
                    // 子线程正在运行
                    // 子线程要退出了
                    // hello world
                    // hello world

                    #endif

                    while(1)
                    {
                        printf("hello world\n");
                        sleep(1);
                    }

                    return 0;
                }



        8.2.4 线程的退出
            在进程中我们可以调用 exit 函数 或 _exit 函数 来结束进程。
            在一个线程中我们可以通过以下三种在不终止整个进程的情况下 停止它的控制流。
                1、线程从执行函数中返回。(return)
                2、线程调用 pthread_exit 退出线程。
                3、线程可以被同一进程中的其它线程取消。

            8.2.4.1 线程退出函数
                #include <pthread h>
                void pthread_exit(void *retval);
                功能:
                    退出调用线程，
                参数:
                    retval:存储线程退出状态的指针,
                注：
                    一个进程中的多个线程是共享该进程的数据段，因此，通常线程退出后所占用的资源并不会释放。
                    如果要释放资源，结合态需要通过pthread_join函数，分离态则自动释放。

        例：
                    // //正常退出：
                    // #include <stdio.h>
                    // #include <stdlib.h>
                    // #include <pthread.h>
                    // #include <unistd.h>

                    // void *thread_fun(void *arg)
                    // {
                    //     printf("子线程正在运行\n");
                    //     int i;
                    //     for(int i = 0; i < 10; i++)
                    //     {
                    //         printf("*******************\n");
                    //         sleep(1);
                    //     }
                    // }

                    // int main(int argc, char const *argv[])
                    // {
                    //     printf("主控线程正在执行\n");

                    //     pthread_t thread;

                    //     if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                    //     {
                    //         perror("fail to pthread_create");
                    //         exit(1);
                    //     }

                    //     pthread_join(thread, NULL);

                    //     printf("进程要退出了\n");

                    //     return 0;
                    // }


                    // //使用pthread_exit退出，且不接收退出状态
                    // #include <stdio.h>
                    // #include <stdlib.h>
                    // #include <pthread.h>
                    // #include <unistd.h>

                    // void *thread_fun(void *arg)
                    // {
                    //     printf("子线程正在运行\n");
                    //     int i;
                    //     for(int i = 0; i < 10; i++)
                    //     {
                    //         if(i == 5)
                    //         {
                    //             //通过pthread_exit函数退出当前线程
                    //             //pthread_exit(NULL);
                    //             pthread_exit(NULL);//参数是 返回退出时的状态
                    //         }
                    //         printf("*******************\n");
                    //         sleep(1);
                    //     }
                    // }

                    // int main(int argc, char const *argv[])
                    // {
                    //     printf("主控线程正在执行\n");

                    //     pthread_t thread;

                    //     if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                    //     {
                    //         perror("fail to pthread_create");
                    //         exit(1);
                    //     }

                    //     pthread_join(thread, NULL);

                    //     printf("进程要退出了\n");

                    //     return 0;
                    // }


                    //使用pthread_exit退出，接收退出状态
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <pthread.h>
                    #include <unistd.h>

                    void *thread_fun(void *arg)
                    {
                        printf("子线程正在运行\n");

                        static char buf[] = "This thread has quited";

                        int i;
                        for(int i = 0; i < 10; i++)
                        {
                            if(i == 5)
                            {
                                //通过pthread_exit函数退出当前线程
                                //pthread_exit(NULL);
                                pthread_exit(buf);  //退出时返回buf里面的内容（退出状态）
                            }
                            printf("*******************\n");
                            sleep(1);
                        }
                    }

                    int main(int argc, char const *argv[])
                    {
                        printf("主控线程正在执行\n");

                        pthread_t thread;

                        if(pthread_create(&thread, NULL, thread_fun, NULL) != 0)
                        {
                            perror("fail to pthread_create");
                            exit(1);
                        }

                        //pthread_join(thread, NULL);
                        char *str;
                        pthread_join(thread, (void **)&str); //接收buf的退出状态
                        printf("str = %s\n", str);

                        printf("进程要退出了\n");

                        return 0;
                    }


            8.2.4.2 线程的取消
                取消线程是指取消一个正在执行线程的操作。
                头文件：
                    finelude <pthread.h>
                int pthread caneel(pthread t thread);
                功能:
                    取消线程。
                参数:
                    thread:目标线程 ID
                返回值:
                    成功返回 0，
                    失败返回 出错编号

                    pthread_cancel函数的 实质是 发信号给 目标线程thread，使目标线程退出。
                    此函数 只是发送 终止信号 给 目标线程，不会等待 取消目标线程执行完 才返回。
                    然而 发送成功 并不意味着 目标线程一定就会终止 ，线程被取消时 ，线程的取消属性 会决定 线程能否被取消 以及 何时被取消。

                线程的取消状态
                    即线程能不能被取消
                线程取消点
                    即线程被取消的地方
                线程的取消类型
                    在线程能被取消的状态下，是立马被取消结束 还是执行到 取消点的时候 被取消结束。


                8.2.4.2.1 不修改取消的状态，线程默认可退出的状态，使用pthread_cancel简单退出子线程
                例1：
                        #include <stdio.h>
                        #include <stdlib.h>
                        #include <pthread.h>
                        #include <unistd.h>

                        void *pthread_fun(void *arg)
                        {
                            while(1)
                            {
                                printf("子线程正在运行\n");

                                sleep(1);
                            }
                        }

                        int main(int argc, char const *argv[])
                        {
                            pthread_t thread;

                            if(pthread_create(&thread, NULL, pthread_fun, NULL) != 0)
                            {
                                perror("fail to pthread_create");
                            }

                            //通过调用pthread_cancel函数取消另一个线程
                            //3秒后取消子线程，pthread_cancel在任意地方都可用，包括另一个子线程。只要知道线程ID即可。
                            //另外需注意：此函数只是发送了退出的一个信号，至于线程到底退不退出，决定权在于 子线程的取消属性
                            sleep(3);
                            pthread_cancel(thread);

                            pthread_join(thread, NULL);

                            return 0;
                        }

                    执行结果：发送退出信号后，子线程可以正常退出
                        qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$ ./a.out
                        子线程正在运行
                        子线程正在运行
                        子线程正在运行
                        qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$


                8.2.4.2.2 使用pthread_setcancelstate修改取消的状态：pthread_setcancelstate 或 PTHREAD_CANCEL_ENABLE
                    在Linux 系统下，线程默认 可以被取消。
                    编程时可以通过 pthread_setcancelstate函数 设置线程是否可以被取消。
                    头文件：
                        #include <pthread.h>

                    int pthread_setcancelstate(int state,int *old_state);
                    功能：
                        设置线程是否被取消
                    参数：
                        state:
                            PTHREAD_CANCEL_DISABLE:不可以被取消
                            PTHREAD_CANCEL_ENABLE: 可以被取消
                        old state:
                            保存 调用线程原来的 可取消状态的 内存地址。
                    返回值：
                        成功：0
                        失败：非0.

                    案例2：
                                #include <stdio.h>
                                #include <stdlib.h>
                                #include <pthread.h>
                                #include <unistd.h>

                                void *pthread_fun(void *arg)
                                {
                                    //通过pthread_setcancelstate设置取消的状态
                                    //设置为可以取消
                                    //pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
                                    //设置为不可取消
                                    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

                                    while(1)
                                    {
                                        printf("子线程正在运行\n");

                                        sleep(1);
                                    }
                                }

                                int main(int argc, char const *argv[])
                                {
                                    pthread_t thread;

                                    if(pthread_create(&thread, NULL, pthread_fun, NULL) != 0)
                                    {
                                        perror("fail to pthread_create");
                                    }

                                    sleep(3);
                                    pthread_cancel(thread);

                                    pthread_join(thread, NULL);

                                    return 0;
                                }

                执行结果：发送退出信号后，子线程不能退出
                    子线程正在运行
                    子线程正在运行
                    子线程正在运行
                    子线程正在运行
                    ^C



                8.2.4.2.3 设置线程的取消点
                    线程被取消后，该线程并不是马上终止，默认情况下线程执行到消点时才能被终止。
                    编程时可以通过
                         pthread_testcancel函数设置线程的取消点。

                    void pthread_testcancel(void);
                    当别的线程  取消  调用了此函数的线程时，被取消的线程 执行到此函数时 结束。
                    POSIX. 1保证线程在调用表1、表2中的任何函数时，取消点都会出现。（即表中的函数基本都内置的有取消点，如sleep函数、wait函数等）
                    （见WPS表1、2）
                    例：
                            #include <stdio.h>
                            #include <stdlib.h>
                            #include <pthread.h>
                            #include <unistd.h>

                            void *pthread_fun(void *arg)
                            {
                                while(1)
                                {
                                    printf("子线程正在运行\n");

                                    sleep(1);

                                    pthread_testcancel();
                                }
                            }

                            int main(int argc, char const *argv[])
                            {
                                pthread_t thread;

                                if(pthread_create(&thread, NULL, pthread_fun, NULL) != 0)
                                {
                                    perror("fail to pthread_create");
                                }

                                sleep(3);
                                pthread_cancel(thread);

                                pthread_join(thread, NULL);

                                return 0;
                            }


                8.2.4.2.4 线程的取消类型
                    线程被取消后，该线程并不是马上终止，默认情况下线程执行到消点时才能被终止。编程时可以通过
                        pthread_setcanceltype 函数设置线程是否可以立即被取消，

                    pthread_setcanceltype(int type, int *oldtype):
                        type:
                            PTHREAD_CANCEL_ASYNCHRONOUS:立即取消
                            PTHREAD_CANCEL_DEFERRED:不立即被取消
                        oldtype:
                            保存调用线程原来的可取消类型的内存地址。

                    例：

                            #include <stdio.h>
                            #include <stdlib.h>
                            #include <pthread.h>
                            #include <unistd.h>

                            void *pthread_fun(void *arg)
                            {
                                pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

                                //设置线程取消的类型
                                //设置为立即取消
                                //pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
                                //设置为不立即取消
                                pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
                                while(1)
                                {
                                    printf("子线程正在运行\n");

                                    sleep(1);
                                }
                            }

                            int main(int argc, char const *argv[])
                            {
                                pthread_t thread;

                                if(pthread_create(&thread, NULL, pthread_fun, NULL) != 0)
                                {
                                    perror("fail to pthread_create");
                                }

                                sleep(3);
                                pthread_cancel(thread);

                                pthread_join(thread, NULL);

                                return 0;
                            }

                执行结果1：
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$ ./a.out
                    子线程正在运行
                    子线程正在运行
                    子线程正在运行
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$
                执行结果2：
                    同上，但最后会有一个1s的停顿



        8.2.5 线程退出清理函数
            和进程的退出清理一样，线程也可以注册它退出时 要调用的函数，这样的函数 称为 线程清理处理程序(thread cleanup handler).
        注意:
            线程 可以建立 多个 清理处理程序。
            处理程序在 栈中，故它们的 执行顺序 与 它们注册时的顺序 相反.

       * 注册清理函数
            #include <pthread.h>

            void pthread_cleanup_push (void (*routine)(void *), void *arg):
            功能:
                将清除函数压栈。即注册清理函数。
            参数:
                routine:线程清理函数的指针
                arg:传给线程清理函数的参数

       * 弹出清理函数
            #include<pthread h>

            void pthread_cleanup_pop(int execute);
            功能:
                将清除函数弹栈，即删除清理函数。
            参数:
                execute:线程清理函数执行标志位。
                    非0，弹出清理数，执行清理函数
                    0，弹出清理函数，不执行清理函数。

        当线程执行以下动作时会调用清理函数:
            1、调用 pthread_exit 退出线程,
            2、响应其它线程的取消请求。
            3、用非零execute 调用 pthread_cleanup_pop.
            无论哪种情况 pthread_cleanup_pop 都将删除上一次pthread_cleanup_push 调用注册的清理处理函数。


        8.2.5.1 pthread_clearnup_push()
        例：
                #include <stdio.h>
                #include <stdlib.h>
                #include <unistd.h>
                #include <pthread.h>
                #include <string.h>

                void mycleanup(void *arg)
                {
                    printf("clean up ptr = %s\n", (char *)arg);
                    free((char *)arg);
                }

                void *thread(void *arg)
                {
                    //建立线程清理程序
                    printf("this is new thread\n");

                    char *ptr = NULL;
                    ptr = (char*)malloc(100);//在堆区开辟空间存放字符串
                    //清理函数，将清除函数压栈。即注册清理函数。
                    pthread_cleanup_push(mycleanup, (void*)(ptr));

                    bzero(ptr, 100);	//将字符串清零
                    strcpy(ptr, "memory from malloc");//将字符串拷贝到ptr中

                    sleep(3);
                    printf("before exit\n");

                    pthread_exit(NULL);	//3s后调用该函数，

                    //注意push与pop必须配对使用，即使pop执行不到
                    printf("before pop\n");
                    // 将清除函数弹栈，即 删除 清理函数。
                    pthread_cleanup_pop(1);
                }

                int main(int argc, char *argv[])
                {
                    pthread_t tid;
                    pthread_create(&tid, NULL, thread, NULL);  // 创建一个线程
                    pthread_join(tid,NULL);
                    printf("process is dying\n");
                    return 0;
                }

                执行结果：
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$ ./a.out
                    this is new thread
                    before exit
                    clean up ptr = memory from malloc
                    process is dying
                    qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$


        8.2.5.2 pthread_clearnup_pop()
        例：
                #include <stdio.h>
                #include <stdlib.h>
                #include <unistd.h>
                #include <pthread.h>
                #include <string.h>

                void cleanup(void *arg)
                {
                    printf("clean up ptr = %s\n", (char *)arg);
                    free((char *)arg);
                }

                void *thread(void *arg)
                {
                    char *ptr = NULL;

                    //建立线程清理程序
                    printf("this is new thread\n");
                    ptr = (char*)malloc(100);
                    pthread_cleanup_push(cleanup, (void*)(ptr));
                    bzero(ptr, 100);
                    strcpy(ptr, "memory from malloc");

                    sleep(10);

                    //注意push与pop必须配对使用，即使pop执行不到
                    printf("before pop\n");
                    pthread_cleanup_pop(1);
                    return NULL;
                }

                int main(int argc, char *argv[])
                {
                    pthread_t tid;
                    pthread_create(&tid, NULL, thread, NULL);  // 创建一个线程
                    sleep(5);
                    printf("before cancel\n");
                    //子线程响应pthread_cancel后，会执行线程处理函数
                    pthread_cancel(tid);
                    pthread_join(tid,NULL);
                    printf("process is dying\n");
                    return 0;
                }


            执行结果：
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$ ./a.out
                this is new thread
                before cancel
                clean up ptr = memory from malloc
                process is dying
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$


        8.2.5.3 案例：验证线程调用pthread_exit函数时，系统自动调用线程清理函数
            例：
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <pthread.h>
                    #include <string.h>

                    void mycleanup(void *arg)
                    {
                        printf("clean up ptr = %s\n", (char *)arg);
                        free((char *)arg);
                    }

                    void *thread(void *arg)
                    {
                        建立线程清理程序
                        printf("this is new thread\n");

                        char *ptr = NULL;
                        ptr = (char*)malloc(100);//在堆区开辟空间存放字符串
                        //清理函数，将清除函数压栈。即注册清理函数。
                        pthread_cleanup_push(mycleanup, (void*)(ptr));

                        bzero(ptr, 100);	//将字符串清零
                        strcpy(ptr, "memory from malloc");//将字符串拷贝到ptr中

                        sleep(3);
                        printf("before exit\n");

                        pthread_exit(NULL);	//3s后调用该函数，

                        //注意push与pop必须配对使用，即使pop执行不到
                        printf("before pop\n");
                        // 将清除函数弹栈，即 删除 清理函数。
                        pthread_cleanup_pop(1);
                    }

                    int main(int argc, char *argv[])
                    {
                        pthread_t tid;
                        pthread_create(&tid, NULL, thread, NULL);  // 创建一个线程
                        pthread_join(tid,NULL);
                        printf("process is dying\n");
                        return 0;
                    }


        8.2.5.4 案例：验证线程被取消时，系统自动调用线程清理函数
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <pthread.h>
                    #include <string.h>

                    void cleanup(void *arg)
                    {
                        printf("clean up ptr = %s\n", (char *)arg);
                        free((char *)arg);
                    }

                    void *thread(void *arg)
                    {
                        char *ptr = NULL;

                        //建立线程清理程序
                        printf("this is new thread\n");
                        ptr = (char*)malloc(100);
                        pthread_cleanup_push(cleanup, (void*)(ptr));
                        bzero(ptr, 100);
                        strcpy(ptr, "memory from malloc");

                        sleep(10);

                        //注意push与pop必须配对使用，即使pop执行不到
                        printf("before pop\n");
                        pthread_cleanup_pop(1);
                        return NULL;
                    }

                    int main(int argc, char *argv[])
                    {
                        pthread_t tid;
                        pthread_create(&tid, NULL, thread, NULL);  // 创建一个线程
                        sleep(5);
                        printf("before cancel\n");
                        //子线程响应pthread_cancel后，会执行线程处理函数
                        pthread_cancel(tid);
                        pthread_join(tid,NULL);
                        printf("process is dying\n");
                        return 0;
                    }


        8.2.5.5 案例：验证调用pthread_cleanup_pop函数时，系统自动调用线程清理函数
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <pthread.h>
                    #include <string.h>

                    void cleanup_func1(void *arg)
                    {
                        printf("in cleanup func1\n");
                        printf("clean up ptr = %s\n", (char *)arg);
                        free((char *)arg);
                    }

                    void cleanup_func2(void *arg)
                    {
                        printf("in cleanup func2\n");
                    }

                    void *thread(void *arg)
                    {
                        char *ptr = NULL;

                        //建立线程清理程序
                        printf("this is new thread\n");
                        ptr = (char*)malloc(100);
                        pthread_cleanup_push(cleanup_func1, (void*)(ptr));
                        pthread_cleanup_push(cleanup_func2, NULL);
                        bzero(ptr, 100);
                        strcpy(ptr, "memory from malloc");
                        //注意push与pop必须配对使用，即使pop执行不到
                        sleep(3);
                        printf("before pop\n");
                        pthread_cleanup_pop(1);
                        printf("before pop\n");
                        pthread_cleanup_pop(1);
                        return NULL;
                    }

                    int main(int argc, char *argv[])
                    {
                        pthread_t tid;
                        pthread_create(&tid, NULL, thread, NULL);  // 创建一个线程
                        pthread_join(tid,NULL);
                        printf("process is dying\n");
                        return 0;
                    }
            执行结果：
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$ ./a.out
                this is new thread
                before pop
                in cleanup func2
                before pop
                in cleanup func1
                clean up ptr = memory from malloc
                process is dying
                qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/8_thread$

*/

//第九章 信号量 信号的互斥（多任务互斥和同步）
/*
    9.1 互斥 和 同步概述
            在多任务操作系统中，同时运行的多个任务 可能都需要访问/使用同一种资源。
            多个任务之间有依赖关系，某个任务的运行依赖于另一个任务
            同步和互斥就是用于解决这两个问题的。

        互斥:
            一个公共资源 同一时刻 只能被一个进程 或 线程使用，多个进程 或 线程 不能同时使用 公共资源，
            POSIX标准中 进程 和 线程 的 同步和互斥的方法,主要有 信号量 和 互斥锁 两种方式。
        同步:
            两个或两个以上的进程 或 线程 在运行过程中协同步调，按预定的先后次序运行
            （同步 是 在互斥的基础上 增加了 先后次序）

       （异步：
            当运行的过程当中，突然把当前的运行打断，执行另一个程序，当另外一个程序执行完毕后，回到当前程序继续执行。）

    9.2 互斥锁（解决互斥问题）
        9.2.1 互斥锁的概念：（我们控制的是 对共享资源的操作，而不是共享资源本身）

            mutex 是一种 简单的 加锁的方法 来控制 对共享资源的 访问。
            mutex 只有两种状态,即上锁(lock)和解锁(unlock)。
            在访问资源前，首先应申请mutex，如果 mutex处于unlock状态，则会申请到 mutex 并立即lock:
            如果 mutex 处于 lock状态，则默认阻塞申请者。
            unlock 操作应该由 lock 者进行。

        9.2.2 互斥锁的操作
            9.2.1.1 初始化互斥锁
                mutex 用 pthread_mutex_t 数据类型表示，在使用互斥锁前,必须先对它进行初始化。
                静态分配的互斥锁:
                    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER:
                动态分配互斥锁:
                    pthread_mutex_t mutex;
                    pthread_mutex_init (&mutex，ULL); 在 所有使用过此互斥锁的线程 都不再需要使用时候，应调用 销毁互斥锁。
                销毁互斥锁
                    pthread_mutex_destroy 销毁互斥锁。


        初始化互斥锁：
            #include <pthread.h>

            int pthread_mutex_init (pthread_mutex_t *mutex,const pthread_mutexattr_t *attr);
            功能:
                初始化一个互斥锁。
            参数:
                mutex:互斥锁地址
                attr:互斥锁的属性，NULL为默认属性。
            返回值：
                成功：返回0
                失败：返回非0.


        9.2.3 互斥锁上锁
            #include <pthread.h>

            int pthread_mutex_lock (pthread_mutex_t *mutex);
            功能：
                对互斥锁上锁，若已经上锁，则调用者一直阻塞到互斥锁解锁（阻塞，常用）
            参数：
                mutex:互斥锁地址
            返回值：
                成功：返回0
                失败：返回非0

        9.2.4 互斥锁上锁2
            #include <pthread.h>

            int pthread_mutex_trylock (pthread_mutex_t *mutex);
            功能：对互斥锁上锁，若已经上锁，则上锁失败，函数立即返回。（非阻塞，不常用）
            参数：
                mutex：互斥锁地址
            返回值：
                成功：0
                失败：非0。

        9.2.5 互斥锁解锁
            #include <pthread.h>
            int pthread_mutex_unlock (pthread_mutex_t *muteX)
            功能:
                对指定的互斥锁解锁，
            参数:
                mutex:互斥锁地址，
            返回值:
                成功：返回 0,
                失败：返回非 0。

        9.2.6 销毁互斥锁
            #include <pthread.h>
            int pthread_mutex_destroy (pthread_mutex_t *mutex)
            功能:
                销毁指定的一个互斥锁。
            参数:
                mutex:互斥镇地址。
            返回值:
                成功返回0，
                夫败返回非0。


    2.3 互斥锁案例
        9.2.3.1 不使用互斥锁的结果
            例：银行卡取钱案例：主副卡(张三李四)对同一卡号取钱。
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <pthread.h>

                    int money = 10000;
                    //银行卡取钱案例：主副卡对同一卡号取钱。
                    void *pthread_fun1(void *arg)
                    {
                        int get, yu, shiji;
                        get = 10000;

                        printf("张三正在查询余额...\n");
                        sleep(1);
                        yu = money;

                        printf("张三正在取钱...\n");
                        sleep(1);
                        if(get > yu)
                        {
                            shiji = 0;
                        }
                        else
                        {
                            shiji = get;
                            yu = yu - get;
                            money = yu;
                        }

                        printf("张三想取%d元，实际取了%d元，余额为%d元\n", get, shiji, yu);

                        pthread_exit(NULL);
                    }

                    void *pthread_fun2(void *arg)
                    {
                        int get, yu, shiji;
                        get = 10000;

                        printf("李四正在查询余额...\n");
                        sleep(1);
                        yu = money;

                        printf("李四正在取钱...\n");
                        sleep(1);
                        if(get > yu)
                        {
                            shiji = 0;
                        }
                        else
                        {
                            shiji = get;
                            yu = yu - get;
                            money = yu;
                        }

                        printf("李四想取%d元，实际取了%d元，余额为%d元\n", get, shiji, yu);

                        pthread_exit(NULL);
                    }

                    int main(int argc, char const *argv[])
                    {
                        pthread_t thread1, thread2;

                        //创建两个子线程，分别处理线程处理函数：pthread_fun1、pthread_fun2
                        if(pthread_create(&thread1, NULL, pthread_fun1, NULL) != 0)
                        {
                            perror("fail to pthread_create");
                            exit(1);
                        }

                        if(pthread_create(&thread2, NULL, pthread_fun2, NULL) != 0)
                        {
                            perror("fail to pthread_create");
                            exit(1);
                        }

                        //阻塞等待两个子线程的退出。
                        pthread_join(thread1, NULL);
                        pthread_join(thread2, NULL);

                        //执行结果：
                        // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/9_mutex_sem$ ./a.out
                        // 张三正在查询余额...
                        // 李四正在查询余额...
                        // 张三正在取钱...
                        // 李四正在取钱...
                        // 张三想取10000元，实际取了10000元，余额为0元
                        // 李四想取10000元，实际取了10000元，余额为0元

                        return 0;
                    }
        9.2.3.2 使用互斥锁的结果
            例：见步骤。
                    #include <stdio.h>
                    #include <stdlib.h>
                    #include <unistd.h>
                    #include <pthread.h>

                    //通过互斥锁解决线程间互斥问题

                    int money = 10000;

                    //第一步：创建互斥锁(由于两个线程操作同一个互斥锁，所以定义在全局更加方便一点)
                    pthread_mutex_t mymutex;

                    void *pthread_fun1(void *arg)
                    {
                        int get, yu, shiji;
                        get = 10000;

                        //第三步：对共享资源的操作进行上锁,
                        //由于在这里开始就是对资源 进行操作了，因此，在这里上锁。
                        pthread_mutex_lock(&mymutex);

                        printf("张三正在查询余额...\n");
                        sleep(1);
                        yu = money;

                        printf("张三正在取钱...\n");
                        sleep(1);
                        if(get > yu)
                        {
                            shiji = 0;
                        }
                        else
                        {
                            shiji = get;
                            yu = yu - get;
                            money = yu;
                        }

                        printf("张三想取%d元，实际取了%d元，余额为%d元\n", get, shiji, yu);

                        //第四步：当共享资源的操作执行完毕后，对互斥锁执行解锁操作
                        pthread_mutex_unlock(&mymutex);

                        pthread_exit(NULL);
                    }

                    void *pthread_fun2(void *arg)
                    {
                        int get, yu, shiji;
                        get = 10000;

                        //第三步：对共享资源的操作进行上锁
                        pthread_mutex_lock(&mymutex);

                        printf("李四正在查询余额...\n");
                        sleep(1);
                        yu = money;

                        printf("李四正在取钱...\n");
                        sleep(1);
                        if(get > yu)
                        {
                            shiji = 0;
                        }
                        else
                        {
                            shiji = get;
                            yu = yu - get;
                            money = yu;
                        }

                        printf("李四想取%d元，实际取了%d元，余额为%d元\n", get, shiji, yu);

                        //第四步：当共享资源的操作执行完毕后，对互斥锁执行解锁操作
                        pthread_mutex_unlock(&mymutex);

                        pthread_exit(NULL);
                    }

                    int main(int argc, char const *argv[])
                    {
                        //第二步：初始化互斥锁
                        pthread_mutex_init(&mymutex, NULL);

                        pthread_t thread1, thread2;

                        if(pthread_create(&thread1, NULL, pthread_fun1, NULL) != 0)
                        {
                            perror("fail to pthread_create");
                            exit(1);
                        }

                        if(pthread_create(&thread2, NULL, pthread_fun2, NULL) != 0)
                        {
                            perror("fail to pthread_create");
                            exit(1);
                        }

                        pthread_join(thread1, NULL);
                        pthread_join(thread2, NULL);

                        //第五步：当互斥锁使用完毕后，要销毁
                        pthread_mutex_destroy(&mymutex);

                        return 0;
                    }


    9.3 信号量（解决同步）
        9.3.1 信号量的概述
            信号量广泛用于进程或线程间的同步和互斥，信号量本质上是一个非负的整数计数器，它被用来控制 对公共资源的访问。
            编程时可根据 操作信号量值的结果 判断是否对公共资源具有访问的权限，当信号量值大于0时，则可以访问。否则将阻塞。

            信号量 又称之为 PV操作，P V原语是对信号量的操作，一次P操作使信号量sem减1；一次 V 操作 使信号量sem加1。
                对于P操作，若信号量的sem值 小于等于 0，则P操作就会阻塞。若信号量的值大于0，才可以执行P操作 进行减1。

            信号量主要用于进程或线程间的同步和互斥这两种型情况，
                1、若用于 互斥，几个进程(或线程)往往只设置一个信号量。
                2、若用于 同步操作，往往会设置多个信号量，并且安排不同的初始值，来实现它们之间的执行顺序

            9.3.1.1 信号量用于互斥：
                见图1
            9.3.1.2 信号量用于同步：
                见图2

        9.3.2 信号量的操作：
            9.3.2.1 信号量的初始化
            信号量的数据类型：sem_t
                #include <semaphore.h>

                int sem_init(sem_t *sem,int pshared,unsigned int value);
                功能：
                    创建一个信号量并初始化它的值。
                参数：
                    sem:信号量的地址。
                    pshared:等于0，信号量在线程间共享；
                            不等于0，信号量在进程间共享。
                    value:信号量的初始值
                返回值：
                    成功：返回0
                    失败：返回-1.

            9.3.2.2 信号量P操作：
                #include <semaphore.h>
                int sem_wait(sem_t *sem);  （阻塞函数）
                功能:
                    将信号量的值减 1，若信号量的值小于等于0，此函数会引起调用者阻塞
                参数:
                    sem:信号量地址
                返回值:
                    成功返回0
                    失败返回-1

                #include <semaphore.h>
                int sem_trywait(sem_t *sem);    (非阻塞函数，少用)
                功能：
                    信号量的值减1，若信号量的值小于0，则对信号量的操作失败，函数立即返回。
                参数：
                    sem:信号量的地址
                返回值：
                    成功返回0
                    失败返回-1

            9.3.2.3 信号量的 V操作
                #include <semaphore.h>
                int sem_post(sem_t *sem)        注意：虽然名字含有post（p），但实际是V操作
                功能:
                    将信号量的值加 1 并发出信号 唤醒 等待线程
                参数:
                    sem:信号量地址，
                返回值:
                    成功返回 0，
                    失败返回-1。


            9.3.2.4 获取信号量的计数值
                #include<semaphore. h>

                int sem_getvalue(sem_t sem, int *sval);
                功能:
                    获取 sem,标识的信号量的值，保存在 sva1中
                参数:
                    sem:信号量地址。
                    sval:保存信号量值的地址。
                返回值:
                    成功返回 0，失败返回-1。

            9.3.2.5 信号量的销毁
                #include <semaphore.h>
                int sem_destroy(sem_t *sem);
                功能:
                    删除 sem 标识的信号量。
                参数:
                    sem : 信号量地址。
                返回值:
                    成功返回0，失败返回-1。

        9.3.3 信号量的使用
            9.3.3.1 信号量实现互斥功能
            例：
                    // #include <stdio.h>
                    // #include <pthread.h>
                    // #include <unistd.h>
                    // #include <semaphore.h>

                    // //通过信号量实现互斥操作

                    // void printer(char *str)
                    // {
                    // 	while(*str)
                    // 	{
                    // 		putchar(*str);
                    // 		fflush(stdout);
                    // 		str++;
                    // 		sleep(1);
                    // 	}
                    // }

                    // void *thread_fun1(void *arg)
                    // {
                    // 	char *str1 = "hello";
                    // 	printer(str1);
                    // }

                    // void *thread_fun2(void *arg)
                    // {
                    // 	char *str2 = "world";
                    // 	printer(str2);
                    // }

                    // int main(void)
                    // {
                    //     //创建两个子线程，分别调用线程处理函数。
                    // 	pthread_t tid1, tid2;

                    // 	pthread_create(&tid1, NULL, thread_fun1, NULL);
                    // 	pthread_create(&tid2, NULL, thread_fun2, NULL);

                    // 	//阻塞主进程。
                    // 	pthread_join(tid1, NULL);
                    // 	pthread_join(tid2, NULL);

                    //     printf("\n");

                    // 	//执行结果：
                    // // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/9_mutex_sem$ ./a.out
                    // // hwoerlllod
                    // // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/9_mutex_sem$ ./a.out
                    // // hweorllldo
                    // // qinmei@qinmei-virtual-machine:~/Linux_learn/src/1_system/9_mutex_sem$

                    // 	return 0;
                    // }





                    #include <stdio.h>
                    #include <pthread.h>
                    #include <unistd.h>
                    #include <semaphore.h>

                    //通过信号量实现互斥操作

                    //第一步：创建一个信号量
                    sem_t sem;

                    void printer(char *str)
                    {
                        //第三步：执行P操作
                        //由于使用信号量实现互斥，信号量的初始值设置为1，则两个线程执行P操作，
                        //先执行P操作的线程继续执行，后执行P操作的先阻塞等待
                        sem_wait(&sem);
                        while(*str)
                        {
                            putchar(*str);
                            fflush(stdout);
                            str++;
                            sleep(1);
                        }
                        //第四步：执行V操作
                        sem_post(&sem);
                    }

                    void *thread_fun1(void *arg)
                    {
                        char *str1 = "hello";
                        printer(str1);
                    }

                    void *thread_fun2(void *arg)
                    {
                        char *str2 = "world";
                        printer(str2);
                    }

                    int main(void)
                    {
                        //第二步：初始化信号量
                        sem_init(&sem, 0, 1);	//参数2 表示线程间共享。

                        pthread_t tid1, tid2;

                        pthread_create(&tid1, NULL, thread_fun1, NULL);
                        pthread_create(&tid2, NULL, thread_fun2, NULL);

                        pthread_join(tid1, NULL);
                        pthread_join(tid2, NULL);

                        printf("\n");

                        //第五步：使用完毕后销毁信号量
                        sem_destroy(&sem);

                        return 0;
                    }




            9.3.3.2 信号量实现同步功能
                        // #include <stdio.h>
                        // #include <unistd.h>
                        // #include <pthread.h>
                        // #include <semaphore.h>

                        // //使用信号量实现同步功能，如果两个线程实现同步，需要通过两个信号量

                        // char ch = 'a';

                        // void * pthread_g(void *arg)
                        // {
                        // 	while(1)
                        // 	{
                        // 		ch++;
                        // 		sleep(1);
                        // 	}
                        // }
                        // void * pthread_p(void *arg)  //此线程打印ch的值
                        // {
                        // 	while(1)
                        // 	{
                        // 		printf("%c",ch);	//每获取一次
                        // 		fflush(stdout);		//刷新一下缓冲区。
                        // 	}
                        // }

                        // int main(int argc, char *argv[])
                        // {

                        // 	pthread_t tid1,tid2;

                        // 	pthread_create(&tid1,NULL,pthread_g,NULL);
                        // 	pthread_create(&tid2,NULL,pthread_p,NULL);

                        // 	pthread_join(tid1,NULL);
                        // 	pthread_join(tid2,NULL);

                        //     printf("\n");
                        // // 执行结果：
                        // // 我们希望只打印一次，但实际是线程1睡眠的时间内，线程2一直在打印。
                        // //
                        // 	return 0;
                        // }



                        #include <stdio.h>
                        #include <unistd.h>
                        #include <pthread.h>
                        #include <semaphore.h>

                        //使用信号量实现同步功能，如果两个线程实现同步，需要通过两个信号量

                        char ch = 'a';

                        //第一步：创建两个信号量
                        sem_t sem_g, sem_p;

                        void * pthread_g(void *arg)
                        {
                            while(1)
                            {
                                //第四步：后执行的线程中，信号量的初始值设置为0的信号量执行P操作
                                sem_wait(&sem_g);

                                ch++;
                                sleep(1);

                                //第六步：后执行的线程执行完毕后，信号量初始值为1的信号量执行V操作
                                sem_post(&sem_p);
                            }
                        }
                        void * pthread_p(void *arg)  //此线程打印ch的值
                        {
                            while(1)
                            {
                                //第三步：先执行的线程中，信号量初始值设置为1的信号量执行P操作
                                sem_wait(&sem_p);

                                printf("%c",ch);	//每获取一次
                                fflush(stdout);		//刷新一下缓冲区。

                                //第五步：当先执行的线程执行完毕后，信号量初始值为0的信号量执行V操作
                                sem_post(&sem_g);
                            }
                        }

                        int main(int argc, char *argv[])
                        {
                            //初始化信号量
                            sem_init(&sem_g, 0, 0);//0：后执行
                            sem_init(&sem_p, 0, 1);//1：先执行。

                            pthread_t tid1,tid2;

                            pthread_create(&tid1,NULL,pthread_g,NULL);
                            pthread_create(&tid2,NULL,pthread_p,NULL);

                            pthread_join(tid1,NULL);
                            pthread_join(tid2,NULL);

                            printf("\n");

                            //第七步：使用完毕后销毁信号量
                            sem_destroy(&sem_g);
                            sem_destroy(&sem_p);

                            return 0;
                        }
*/




//笔记区
//##########################################################################
//代码区


#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
