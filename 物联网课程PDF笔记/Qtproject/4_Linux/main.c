#include <stdio.h>

/*
11.1Linux系统简介：

    Linux 是最受欢迎的自由电脑操作系统内核，是一个用C语言写成，符合POSIX 标准的类 Unix 操作系统
诞生于 1991年 10月5日，由芬兰黑客 Linus Torvalds 为尝试在英特尔x86 架构上提供自由免费的类 Unix 操作系
统而开发的
Linux 操作系统的诞生、发展、和成长过程依赖于五个重要支柱:
unix 操作系统、minix 操作系统、GNU 计划、POSIX 标准和互联网


11.1.1 unix 操作系统、minix 操作系统:
    unix是linux 操作系统的前身
    minix是 linux一直模仿和要超越的对象

    苹果手机就是基于Unix开发的
    而安卓手机是基于Linux（开源的）开发的

11.1.2GNU 计划和自由软件基金会(FSF)
    Richard M.Stallman 于 1984年创办,旨在开发一个免费、类 unix 的操作系统-GNU 系统及其开发工具
    Emacs 编辑系统、BASH shell 程序、GCC、GDB 等开发工具都是 GNU 组织的产品
    后来与 linux,内核结合成为了现在的 GNU/linux
    FSF:于1985年10月建立:监督保证执行GNU计划

11.1.3 POSIX(Portable Operating System Interface)
    可移植操作系统接口,由电气和电子工程师协会(IEEE)开发用来统- unix、Limux,各分支编程接口，以提高其通用
    型和可移植性
    使得 !imnux的发展结束了初期的混乱发展阶段，进入了一个新的时期

11.1.4 互联网
来自世界各地的黑客、自由软件推崇者通过网络联合在一起，完成了 1inux的开发工作

C语言和linux发展史上最重要的四个人:
    肯.汤姆森：      原本是一个AT&T公司的员工，发明了B语言，发明了UNIX系统，发明了C语言
    丹尼斯.里奇：    C语言之父，UNIX之父
    理查德.斯托曼：  创办了自由软件基金会，这个基金会就是为了写一个开源的类unix的系统，所以
                   他被尊称为自由软件之父
    林纳斯.托瓦兹：  linux之父
*/

/*
11.2.1
系统安装方式
物理机安装:
    可使用光驱、U 盘(将镜像固化在U盘中)安装
        优点:对操作系统的体会更加真切方便
        缺点:刚刚接触 Linux 的人无从下手，使用不太习惯,(将Windos系统重装为Linux系统)
虚拟机安装
    在电脑上安装虚拟机，在虚拟机中安装操作系统
        优点:由虚拟机软件虚拟出一台或多台电脑，同时运行二个 或更多的操作系统，并进行数据交换，
             方便快捷。可同时操作 windows 的软件辅助学习
        缺点:性能相比物理机较差，它对物理机的性能，如内存、CPU、磁盘等要求较高。

11.2.2虚拟机的介绍及安装：
    虚拟机介绍：
        虚拟机可以说是一种软件，也可以说是一种技术，它允许你在一台主机上虚拟出多台计算机，每台虚拟的计算机
        都可以有自己的硬件及软件配置。
虚拟机技术的作用
    1、帮助网络架构工程师在一台电脑上模拟、检测整个网络运行情况。
    2、极大的降低企业的运营成本与风险。
    3、帮助操作系统设计者测试、解决问题。
    4、帮助开发者在多个平台上进行自由切换。
应用较为广泛的虚拟机
    1、Virtual PC 是 Microsot 公司开发的一个免费“虚拟机”软件,它使用户可以在一台机器上同时运行多个操作系统
    2、VMware 是目前市场占有率最高的虚拟机，是虚拟界巨头 VMware,公司的产品，其功能非常强大且稳定
    3、VirtualBox 是一款开源虚拟机软件。VirtualBox 是由德国 Innotek 公司开发，由 Sum Microsystems 公司出品的
        软件，使用 Qt编写，在 Sun 被 Oracle 收购后正式更名成 Oracle VM VirtualBox

    vmware Player 是 Vmware Workstation 的精简版本，具有体积小，使用灵活，免费等特点
    非常适合我们嵌入式领域的开发过程

    安装虚拟机
    双击 VMware-player-15.5.0.exe，一路next 即可(电脑可能会重启几次)
    注意:安装完毕后选择使用免费版即可
*/

/*
11.2.3 Ubuntu 在虚拟机中打开
        Ubun 是一个以桌面应用为主的 Linux 操作系统，其名称来自非洲南部祖鲁语或豪萨语的“ubunu"一词，意
    思是“人性”“我的存在是因为大家的存在"，是非洲传统的一种价值观。Ubuntu基于 linux 的Debian 发行版和
    Gnome 桌面环境

    ubuntu16.04.zi压缩缩包解压
    使用虚拟机找到ubuntu的位置并打开
    第一步:点击虚拟机中的“打开虚拟机”，然后找到解压缩之后的文件中的Ubuntu 64位.vmx
    第二步:点击播放虚拟机
    第三步：输入密码进入
*/

/*
Ubuntu 泉面介绍
ubuntu 桌面
    1、从 2010.10 版本后，Unity 成为 ubuntu,默认桌面。
    2、Unity 桌面环境打破了传统的 GNOME 面板配置。
    3、桌面左边包括一个启动器停靠栏和任务管理面板。

dash 的使用
    Unity 桌面在左面的第一个位置上，设置了一个 dash home 搜索栏，ubunu,下所有的应用程序可通过搜索栏找到。
    如果我们要打开终端，直接在 dash 中输入"temmina"或“终端”即可找到对应的软件，单击即可启动。
    或者在桌面下鼠标右键选择打开终端
    注意:中英文输入法切换是 ctl+空格
*/

/*
Linux基础之命令：
    1.目录结构及文件
    2.Linux命令
        平常通过图像界面能够实现的功能，通过命令基本上都可实现

1.1打开终端的方式：
    1.鼠标右键选择“打开终端”
    2.ctrl + alt + t
    3.锁定到启动器

1.2终端提示符：
    stu@qfedu:~$
        stu:用户名
        @:起连接作用，无实用
        qfedu:主机名；
        ~：表示路径，
                ~：家目录
                /：根目录
        $:表示权限，
                $:普通用户权限
                #:管理员权限

12.1命令的格式:
注意：命令、选项和参数 需要 用空格隔开
    命令      选项      参数
    ls    -a -l -h      /
    rm    -r -f         a.txt  b.txt

12.2命令帮助信息
    命令   --help
    注意：不是所有的命令都有帮助信息 如： pwd就没有
    用法： ls --help

12.3 man命令：是linux提供的帮助手册，可以查询命令、函数或者特殊的文件
    man 是 Linux提供的一个手册，这个手册有很多个章节
    第一章中放的是 命令 的帮助信息
    第二章中放的是系统调用(操作系统提供的函数open)
    第三章中放的是库函数(c库提供的函数 printf)的帮助信息
    用法:
        man     章节      查找信息
        man     1        ls
        man     2       open
        man     3       printf
    注意：若有命令和系统调用及库函数同名，则在各个章节找就行

    注意：命令中间的章节可以没有，如果没有的话，就从第1章开始往后找，直到找到或者找完。
    man  1  ls      或者 man ls

12.4命令常用的技巧
    12.4.1 自动补全:tab
        输入命令的一部分，然后按tab键，就自动补全命令，如果有多个相同开头的命令
        多按一次 tab 键，他会将所有的以你输入开头的命令提示出来

        例:ifconfig
            输入if 按两下 tab 键
            输入 ifc 按 tab 键
        注意:目录或文件的名字也可以自动补全

        在当前目录下有个文件夹叫 zhaoxiutao
        我要删除文件夹得话
           rm  zhao
        然后按tab键就可以补全目录

    12.4.2 历史命令
        可以按 上下键 将以前输入的命令调出来，敲回车执行或者修改之后敲回车执行
    12.4.3 重定向
        命令 > 目的文件   :先清空原文本内容，然后将命令的输出结果写入到文件
        命令 >>目的文件   :以追加的方式将命令的输出结果写入文件
    （cat file.txt   ，cat查看文件内容）
        本来输出到屏幕上的数据，重定向输出 到了目的文件中
    12.4.4 管道: |
        一个程序的输出 作为另外一个程序的输入
        例：
        ls --help | more        以每页的方式查看ls的帮助信息
        ls /etc | wc -w         统计根目录下的 etc目录中的文件数目

12.5 ls    tree     clear
    5.1 ls
        ls                      查看当前目录下的文件名
        ls 目录名                查看指定目录下的文件名
        ls /                    查看根目录下的文件名
        ls -a                   查看当前目录下的所有文件名，包括隐藏文件
        ls -l                   查看当前目录下文件的详细信息
            drwxrwxr-x 2 stu stu 4096 12月 19 09:30 share
            d：文件类型，linux里面不以后缀名作为文件类型的区分（如：.txt .doc等）

                linux里面一个有7种文件类型：bcd-lsp
                    b：块设备文件
                    c：字符设备文件
                    d：目录文件
                    -：普通文件
                    l：软连接文件
                    s：套接字文件
                    p：管道文件

            rwxrwxr -x：文件权限，以3个为一组，分别表示 用户主（文件的创作者） 、 用户组（用户主所在的用户组 其他用户 的操作权限） 以及 其他用户(除当前组的 其他组 用户 的操作权限) 对文件的操作权限
                    r：读权限
                    w：写权限
                    -：没有该权限
            2：链接文件的个数
            stu：用户名
            stu：用户组名
            4096：文件大小，默认以字节为单位
            12月 19 09：30 ： 时间戳
            share ：文件名

        ls -al                  查看当前目录下所有文件的详细信息
        ls -hl                  详细信息中的字节数可以带单位的形式

*/


/*

12.5.2 tree 以树状结构显示目录信息
系统默认没有这个命令，需要安装sudo apt-get install tree
如果报错显示无法获得锁，请使用一下命令删除一些文件即可

sudo rm /var/lib/dpkg/lock
sudo rm /var/lib/dpkg/lock-frontend
sudo rm /var/cache/apt/archives/lock

    用法:tree -L 层数

12.5.3 clear 清屏
       ctrl + l也可以清屏
12.6 cd pwd
    12.6.1 cd：change directory 改变目录的意思

        cd 当前目录下的目录名        进入指定目录
        cd /                      进入根目录
        cd ~  或 cd                进入家目录
        cd .                      当前目录
        cd ..                     当前目录的进入上一级目录
        cd -                      返回上一次所在的路径



        绝对路径：
            从根目录（最顶层目录开始的路径）
                /home/teacher/xiutao/test
                /home/teacher/test.txt
            相对路径：
                相对于当前路径下的那个路径
                ./xiutao/test
                ./xiutao/test.c

            当前目录：.
            上一级目录：..
            cd /home/teacher/xiutao

    12.6.2 pwd
         pwd        显示当前路径的绝对路径
*/

/*
12.7 cat rm cp mv
    12.7.1  cat：显示文本文件内容
        使用方法:cat 文件路径或名称
            cat test.txt
            cat /home/teacher/test.txt
    12.7.2  rm 是remove 的意思，移除 即删除的意思
            rm  选项  文件夹 或 文件的路径 或 名称
                rm  test.c
                rm  -rf  xiutao
                rm  -rf  /home/teacher/xiutao
            注意: 选项 -rf 可以没有，但是删除文件夹的时候必须带 -r
                 -f 的意思是强制删除，即使要删除的文件或文件夹不存在也不报错
    12.7.3 cp是copy 复制的意思
            cp    选项         源文件或文件夹路径或者名称    目的路径
            cp  -r -v       test.txt    /home/teacher/xiutao
            将当前目录下的test.txt文件拷贝到/home/teacher/xiutao目录下

            注意：cp后面可以加选项

        cp      文件名     目录名     将文件复制到目录中
        cp      目录1     目录2  -a  将目录1复制到目录2中
        cp      文件名1    文件名2    如果文件2不是目录，则文件1复制一份为文件2
                                    如果文件2存在且不是一个目录，则直接将内容替换成文件1的
*/

/*
    12.7.4 mv是move 是移动的意思，即剪切的意思
    mv 文件名  目录名 将文件移动到指定的目录中
    mv 目录1   目录2 将目录1移动到目录2中
    mv 文件1   文件2  若文件2不存在，则功能为重命名

        使用方法:
            mv  选项   要剪切的文件或目录目的路径
            mv  -v     test.txt   /home/teacher/xiutao
        注意:
            如果源文件和目的路径在同一个路径下，相当于重命名
            mv test.txt test2 txt
            相当于给 test.txt 重命名为 test2.txt

12.8 mkdir  touch
    12.8.1 mkdir 创建文件夹
         例:mkdir xiutao
        注意：若用递归创建的话，需要加-p

    mkdir       目录名                 创建一个目录文件
    mkdir       目录1 目录2 ...        创建多个目录文件
    mkdir   -p  目录1/目录2/目录3/...  嵌套地创建多个目录文件

    12.8.2 touch 创建文件
        touch test.txt

    touch  文件名          创建一个文件

    注意：若文件已经存在，用mkdir再创建，会报错
                     而用touch则会更新当前文件的时间戳,
*/

/*
find是找文件，而grep是找文件指定内容

12.9 find:在指定路径下查找指定文件
    用法:find 路径-name 文件名             在指定路径下查找指定文件,会从指定路径下包括所有的子目录中寻找
        find /home/teacher -name xuegang.txt
        在 /home/teacher 下及其子目录下找 xuegang.txt

12.10 grep:在指定文件中查找指定内容
    -n  ：显示行号
    -R  ：递归查找子目录
    用法:
        在指定的文件中查找指定内容，将查找到的内容整行输出，并高亮显示查找的内容
        grep    查找信息    文件名                 参数-n        显示行号
        grep    hello   /home/teacher/test.txt    -n
        意思是在 /home/teacher/test.txt文件中找 hello字符串，显示出来并带行号

    例:在某个路径及其子目录下的所有文件中查找字符串
        grep  hello     /home/teacher/ *     -R      -n
        在/home/teacher/ 下的文件及其子目录下文件中查找hello 字符串

    注意:必须加-R 递归查找子目录，-n是用来控制显示行号


    grep 查找信息 文件名 在指定的文件中查找指定的内容，
                        将查找到的那日容政纲输出 并 高亮显示查找的内容
    grep 查找信息 文件名 -n 在指定的文件中查找指定的内容
                        将查找到的内容整行且代行号输出并高亮显示查找的内容
    grep 查找信息 * -R -n   从当前目录以及子目录中的文件中查找指定信息（递归显示）
        如： grep dir * -R -n
*/

/*
12.11 ln ：创建链接文件（创建快捷方式）
    ln 源文件名字 链接文件（快捷方式）的名字  -s          创建一个链接文件（类似于windows的快捷方式）
        ln test.txt test2.txt -s
    注：test2.txt就是test。txt连接文件（快捷方式）
    注意：
        不管对源文件还是链接文件进行修改，双方的内容都会改变
        若删除链接文件，对源文件没有任何影响
        若删除源文件，则链接文件失效

12.12 tar:压缩与解压缩命令
    12.12.1 gzip格式： 压缩：zcvf     解压：zxvf
        1.压包（打包）
            压缩用法：zcvf
                tar zcvf    bk.tar.gz  a.c b.txt xiutao test.txt
                将a.c b.txt xiutao test.txt  文件或文件夹压缩到bk.tar.gz中

                tar zcvf  压缩包包名.tar.gz   文件1  文件2  文件3...

        2.解压
            解压方法1：解压到当前目录
                tar zxvf    压缩包的名称
            如：tar zxvf  bk.tar.gz

            解压方法2：解压到指定路径下
                tar zxvf    压缩包的名称  -C   目的路径
            如：tar zxvf   bk.tar.gz    -C    /home/teacher/share
                将压缩包的文件或文件夹 解压到 /home/teacher/share


    12.12.2 bz2格式   压缩：jcvf   解压：jxvf//        1、压包
            压缩用法：
                tar jcvf 压缩包包名  文件1  文件2 ...
                tar jcvf bk.tar.bz2  a.c  b.txt  xiutao  test.txt
                将a.c  b.txt  xiutao  test.txt  文件或文件夹压缩到 bk.tar.gz 中
        2.解压
            解压方法1：解压到当前目录
                tar jxvf    压缩包的名称
            如：tar jxvf  bk.tar.gz

            解压方法2：解压到指定路径下
                tar jxvf    压缩包的名称  -C   目的路径
            如：tar jxvf   bk.tar.gz    -C    /home/teacher/share
                将压缩包的文件或文件夹 解压到 /home/teacher/share


*/

/*
12.13   编辑器之神   ---vi

    12.13.1 安装 vim (是vi升级版）
        1.安装 vim
            sudo apt-get install vim
        2.安装 ctags  （索引工具，用于搜索）
            sudo apt-get install ctags
        3.配置 vim
            1.将vim_configure 拷入当前用户的目录下
                使用samba或共享文件夹完成
            2.打开终端，执行以下命令：
                cd vim_configure
                ./copy_con.sh

    12.13.2 vi的使用
        使用 vi 打开文件
            vi filename:
                打开或创建文件，并将光标置于第 1 行行首
                vi test.txt

            vi +n filename:
                打开存在文件，并将光标置于第 n 行行首
                vi +8 test.txt

        vi的使用：
            vi 文件名  在 vi编辑器中打开或者创建一个文件，并将光标置于行首。

    12.13.3 vi的3种模式
        1.插入模式(敲代码)
            这种模式可以直接编辑文档....

            注意： vi创建一个不存在文件时（.c 文件可以，txt文件不可以），默认进入插入模式

        2、编辑模式（写命令）
            在编辑模式下可以敲一些命令，执行例如：复制n行、剪切n行、粘贴等功能
            注意:vi在打开一个已经存在的文件的时候，默认进入的是编辑模式

        3、命令模式(最后一行模式)
            在此模式下可以保存文件，退出 vi 等功能

        4、三种模式之间的切换:
            1)由 编辑模式 进插入模式 按a i o 这几个字母
              区别是 插入的位置不一样:
                    a：起始位置为下一个位置
                    i：起始位置为当前位置
                    o：起始位置为新换行的位置
            2)由插入模式进编辑模式
              按 ESC 键

            3)只能由编辑模式才能进最后一行模式
              在编辑模式下按 shift: 进入 最后一行模式

              在最后一行的模式下的命令：
                :w  ：保存文件
                :wq ：保存文件并退出vi
                :x  ：保存文件并退出vi
                :q! ：不保存文件，强制退出vi
                :w filename：另存为 filename
            4)由命令模式（最后一行模式）也可以进编辑模式
                按 ESC
            总结：
                a)由 插入模式 或者 命令模式(最后一行模式)  进 编辑模式，方法是按 ESC 键
                b)由 编辑模式 进 命令模式(最后一行模式) 按 shift + :
                c)由 编辑模式 进 插入模式 按 a i o
                d)插入模式 和 命令模式(最后一行模式) 不能直接切换

        5、编辑模式下的操作:
            1) u        ：撤销前面多次修改
               ctrl + r ：反撤销
            2）[n]x     ：删除光标后 n 个字符
                3x
            3) [n]X     :删除光标前 n 个字符
                6X
            4) [n]dd    ：剪切（删除）从当前行开始的 n 行
                4dd
            5) [n]yy    ：复制从当前行开始的 n 行
                4yy
            6) p        ：把粘贴板上的内容插入到当前行。
            7) .        ：执行上一次操作
            8) shift + zz (按住shift 按 2 次 z 键)：保存退出当前文件

        6、编辑模式下移动光标
            [n]G：将光标定位到第 n 行开始处
                  如 5G ：将光标移动第 5 行开始处
            G   ：将光标定位到文件结束处
            gg  ：将光标定位到文件开始处

        7、编辑模式下的查找
        /字符串：从光标开始处向文件尾查找字符串
                    n     : 同一方向重复上一次查找命令。（向后找）
                    N     : 反方向重复上一次查找命令。  （向前找）


    12.14 编辑器 gcc
        在 windows 操作系统下，编译工具用集成开发环境 vc6.0
        在 Linux 操作系统下没有很好的集成环境让我们用，用的编译器是 gcc

        程序的 编译 分为四个阶段:由 .c 到 可执行程序
            1、 预编译
            2、 编译
            3、 汇编
            4、 链接
        编译程序:
        1、一步到位
            gcc hello.c             默认会生成一个名为 a.out 的可执行文件
            gcc hello.c -o hello

            运行程序:  ./a.out     ./hello
        2、分步骤完成
            分步进行
            gcc -E hello.c -o hello.i  1、预处理
            gcc -S hello.i -o hello.s  2、编译
            gcc -c hello.s -o hello.o  3、汇编
            gcc hello.o -o hello       4、链接



13章 Makefile
    1:什么是 make
        make 是个命令，是个可执行程序，用来解析 Makefile,文件的命令
        这个命令存放在 /usr/bin/

    2:什么是 makefile?
        makefle 是个 文件，这个文件中描述了咱们程序的编译规则

        咱们执行 make 命令的时候，make 命令会在 当前目录下 找makefle 文件，
        根据 makefle,文件里的规则，编译咱们的程序

        注意:Makefle,规则文件是咱们程序员根据自己的程序，编写的编译规则
            （Makefile 是用来编译程序的, Makefile规则文件是根据自己的程序编写的编译规则，
            所以程序不一样，文件个数不一样，则编写的Makefile肯定不一样。）

    3:采用 Makefile 的好处
        1、简化编译程序的时候输入得命令，编译的时候 只需要敲 make 命令就可以了
        2、可以节省编译时间，提高编译效率。
        （相对而言，只要通过 Make 编译了一次之后，当下次再编译的时候，只会编译修改过时间戳的文件，
           也许程序非常大，只要有Make 编译了一次之后，即使修改了一些文件，下次再用Make 编译的时候，也只会编译修改过的文件，没修改的不会再重新编译）

    13.1    make 概述

        1、GNU make 是一种代码维护工具
        2、make 工具会根据 makefile,文件定义的规则和步骤，完成整个软件项目的代码维护工作。
        3、一般用来简化编译工作，可以极大地提高软件开发的效率。
        4、wvindows下一般由集成开发环境自动生成(例如QT会自动生成一个makefile)
        5、1imux下需要由我们按照其语法自己编写

        make 主要解决两个问题:
            一、大量代码的关系维护
                大项目中源代码比较多，手工维护、编译时间长而且编译命令复杂，难以记忆及维护
                把代码维护命令及编译命令写在 makefile,文件中，然后再用 make 工具解析此文件自动执行相应命令，可实现
                代码的合理编译
            二、减少重复编译时间
                在改动其中一个文件的时候，能判断哪些文件被修改过，可以只对该文件进行重新编译，然后重新链接所有
                的目标文件，节省编译时间

    13.2.1  makefile语法规则
        目标：依赖文件列表
        <Tab>命令列表

        1、目标：（一般是 要生成的文件，例如：先要将.c文件生成 .o文件，则.o文件就是目标文件）
            通常是要产生的文件名称，目标可以是可执行文件 或 其它 .obj 文件，也可以是一个动作的名称
        2、依赖文件：
            是用来输入从而产生目标的文件
            一个目标通常有几个依赖文件（可以没有）
        3、命令：
            make 执行的动作，一个规则可以含几个命令（可以没有）
            有多个命令时，每个命令占一行
        例如：
        main.h

            #define PI 3.1415926



        main.c

            #include <stdio.h>
            #include "main.h"
            int main(void)
            {
                printf("hello make world\n");
                printf("PI = %lf\n",PI);
                return 0;
            }


        makefile:  将依赖文件 生成 目标文件
            main : main.c  main.h       依赖文件是-o 之前的， 目标文件是之后的
                gcc main.c -o main
            clean:
                rm main

    13.2.2 make 命令格式
            make [-f file] [targets]
        1. [-f file]:(若不是那三个默认文件来作为输入文件，则需要使用-f 来指定输入文件)
                make 默认在工作目录中寻找名为GNUmakefile、makefile、Makefile 的文件作为 makefle 输入文件 ***
                -f可以指定以上名字以外的文件  作为 makefile 输入文件

        2.[ targets ]:（makefile 里面可能写了有很多个目标，则可指定只行哪一个目标，或最终只生成哪一个目标）（若不写目标则所有的都会执行）
                若使用make 命令时 没有指定目标，则 make 工具默认会实现 makefle 文件内的第一个目标，然后退出
                指定了 make 工具要实现的目标，目标可以是一个或多个(多个目标间用空格隔开)。

        例 2:稍复杂的 Makefle 实例
        main.c 调用 printfl.c 中的 printf1 函数，同时需要使用 main.h 的中 P,printflh需要使用 main.h 中的PI

        **一般使用的时候 直接 make 就可**

        gcc *.c编译虽然可以，但他是编译整个工程，若一个项目工程内容非常多，则每次都需要gcc这样编译的话，极浪费时间
        而makefile只需要编译一次，就会记录每一个文件的时间戳，若修改了某个文件的时间戳，
         则最终他第二次再进行makefile编译的时候，只会编译修改过时间戳的文件


{
        main:main.o sub.o sum.o             3.再将.o文件作为依赖文件，生成可执行文件main
                gcc main.o sub.o sum.o -o main

}
{                                           1.中间这三部分，都是将 .c文件生成 .o文件，虽然代码在后面，但却是先执行的（makefile的书写规范）
        main.o:main.c
                gcc -c main.c -o main.o     2.所用命令都是gcc命令，将 .c 文件生成 .o 文件

        sub.o:sub.c
                gcc -c sub.c -o sub.o

        sum.o:sum.c
                gcc -c sum.c -o sum.o
  }
        clean:                              4.clean:当执行完一遍之后，可能中间要生成各种中间文件，则可通过该命令将其删除，
                rm *.c main a.out -rf


        make用法：
            make -f makefile1
            make

执行：
            ./main
清除中间文件:
            make clean




案例1：
main.c
        #include "head.h"

        int main(int argc,const char *argv[])
        {
                int x = 1000;
                int y = 900;

                printf("%d + %d = %d\n",x,y,sum(x,y));
                printf("%d - %d = %d\n",x,y,sub(x,y));

                return 0;
        }
head.h
        #ifndef _HEAD_H_
        #define _HEAD_H_

        #include <stdio.h>

        int sum(int a,int b);
        int sub(int a,int b);

        #endif

sum.c
        #include "head.h"

        int sum(int a,int b)
        {
                return a + b;
        }
sub.c
        #include "head.h"

        int sub(int a,int b)
        {
                return a - b;
        }
makefile1：（makefile版本）
        main:main.o sub.o sum.o
                gcc main.o sub.o sum.o -o main

        main.o:main.c
                gcc -c main.c -o main.o

        sub.o:sub.c
                gcc -c sub.c -o sub.o

        sum.o:sum.c
                gcc -c sum.c -o sum.o

        clean:
                rm *.c main a.out -rf


*/

/*
13.2.3 假想目标:
    在前面的代码里，makefle 中出现的文件，称之为 假想目标。
    假想目标并不是一个真正的文件名，通常是一个目标集合或者动作

    可以没有 依赖 或者 命令
    一般需要显示的使用 make+ 名字 显示调用：例如：make clean就会执行clean 后面的命令
        all:exec1 exec2
        clean:
        <Tab>rm *.o exec

*/

/*
13.3 makefile 变量
    13.3.1 makefle 变量概述

        makefile,变量类似于 C语言中的宏，当 makefile 被 make 工具解析时，其中的变量会被展开。
        变量的作用:
            保存文件名列表
            保存文件目录列表
            保存编译器名
            保存编译参数
            保存编译的输出
            ...

    13.3.2 makefle 的变量分类:
        1、自定义变量
            在 makefile,文件中定义的变量。
            make 工具传给 makefile 的变量。
        2、系统环境变量
            make 工具解析 makefle,前，读取系统环境变量并设置为 makefile,的变量
        3、预定义变量(自动变量)

    13.3.3 自定义变量语法
        定义变量:
            变量名=变量值
        引用变量:$ + 小括号 或 大括号
            $(变量名) 或 ${变量名}
        makefle 的变量名:
            makefile 变量名可以以数字开头
        注意:
            1、变量是大小写敏感的
            2、变量一般都在 makefile,的头部定义
            3、变量几乎可在 makefile 的任何地方使用
        例 2_2:
            修改例 2 中的makefile,使用自定义变量 使其更加通用


由于开发板的内存空间是有限的，因此，可能不会传代码，在开发板去直接进行编译，
而是在我们的Linux或Ubuntu当中先编译，编译完之后，再把可执行文件传到开发板直接运行即可。
问题在于，开发板跟Ubuntu的编译器是不兼容的，故，可能在编译一些程序的时候，要指定开发板的编译器
在这里，我们称之为交叉工具编译工具，因此，编译的时候需要指定：这里面的指定就是ARM-Linux-gcc:#cc=arm-linux-gcc
为了操作方便，有可能程序非常多的文件，则有可能要把所有的gcc都改成 arm-Linux-gcc就太麻烦了，
则可以把他定义成一个自定义变量，就直接先把他变成cc即：cc=gcc，之后要修改就直接改CC就可以了。

makefile2:(自定义变量语法版本)
        cc=gcc
        #cc=arm-linux-gcc makefile的注释可以用#
        obj=main
        obj1=sub
        obj2=sum
        OBJ=main.o sub.o sum.o

        $(obj):$(OBJ)
                $(cc) $(OBJ) -o $(obj)

        $(obj).o:$(obj).c
                $(cc) -c $(obj).c -o $(obj).o

        $(obj1).o:$(obj1).c
                $(cc) -c $(obj1).c -o $(obj1).o

        $(obj2).o:$(obj2).c
                $(cc) -c $(obj2).c -o $(obj2).o

        clean:
                rm *.o $(obj) a.out -rf

gedit :编辑器打开
*/

/*
13.3.4系统环境变量
    make 工具会拷贝系统的环境变量 并将其设置为 makefile的变量，在 makefile中,可直接读取或修改拷贝后的变量。

    #export test=10
    #make clean
    #echo $test

    main:main.c main.h
        gcc main.c -o main
    clean:
        rm main -rf
        echo $(PWD)
        echo "test=$(test)"
*/

/*
13.3.5预定义变量(makefile 中已经定义好的变量)
    makefle中,有许多预定义变量，这些变量具有特殊的含义，可在 makefle 中直接使用
*       $@          目标名
*       $<          依赖文件列表中的第一个文件
*       $^          依赖文件列表中除去重复文件的部分(几乎所有的依赖文件)

        AR          归档维护程序的程序名，默认值为 a
        ARFLAGS     归档维护程序的选项

        AS          汇编程序的名称，默认值为 as
        ASFLAGS     汇编程序的选项

*       CC          C编译器的名称，默认值为 cc
*       CFLAGS      C编译器的选项
        CPP         C 预编译器的名称，默认值为$(CC)-E
        CPPFLAGS    C预编译的选项
        CXX         C++编译器的名称，默认值为g++
        CXXFLAGS    C++编译器的选项
    例2 3:
        修改例 2中的 makefile，使用预定义变量,使其更加通用

makefile3:（预定义变量版本）
        CC=gcc
        obj=main
        obj1=sub
        obj2=sum
        OBJ=main.o sub.o sum.o
        CFLAGS=-Wall -g

        $(obj):$(OBJ)
                $(CC) $^ -o $@

        $(obj).o:$(obj).c
                $(CC) $(CFLAGS) -c $< -o $@

        $(obj1).o:$(obj1).c
                $(CC) $(CFLAGS) -c $< -o $@

        $(obj2).o:$(obj2).c
                $(CC) $(CFLAGS) -c $< -o $@

        clean:
                rm *.o $(obj) a.out -rf

makefile4:(最精炼版本，最无敌版本)，中间3部分都是把 .c 生成 .o 文件，故
        CC=gcc
        obj=main
        OBJ=main.o sub.o sum.O
        CFLAGS=-Wall -g

        $(obj):$(OBJ)                   将所有的 .c 都生成 .o
                $(CC) $^ -o $@

        %*.o:%*.c
                $(cc) $(CFLAGS) -c $< -o $@

        clean:
                rm *.o $(obj) a.out -rf



*/
int main()
{
    printf("Hello World!\n");
    return 0;
}



































