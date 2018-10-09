# Gao_Fen_Bi_Ji
更新命名方式：
算法描述文件以*.des结尾而对应的C语言实现为*.c。

此项目用于实现考研数据结构参考书籍高分笔记里面的算法题目。每章都有一个目录，每个目录下有
exercise_algorithms与example_algorithms两个目录，在每个目录下，举例来说, "1_3"代表题目，而
"1_3.c"代表对应的C程序实现。每个章节目录下的exercise_algorithms目录放置算法题目，而该章的例
子程序在example_algorithms目录下，example_algirithms下算法的命名如：p26_1.c意为第二十六页
第一个算法，p26_2.c意为第二十六页第二个算法，如：p32.c代表该页只有一个算法，另外，p26_1意
为第二十六页算法的文字描述，我如此清楚的讲明每个算法是希望你没有高分笔记这本书也能看懂我的
算法以及我在干什么，从中你能学到些什么， 不至于浪费你的时间。 每个程序开头的测试结果的最后
一行是我的Debian系统的状态栏，我也把它放在我的测试结果里， 记录我在什么时间， 什么状态下完
成了该程序的测试。目录名的形式为“数字_英文名”， 其中数字代表章节， 英文单词代表该章中主要
关于的主题。

修改算法描述文件的命名方式。 由于某个类型的数据结构具有一组的算法操作，这些算法操作会
集中出现在讲解该数据结构的几页附近，新的算法描述文件的范例如p65-66，p是英文单词page的
简记，65-66表示该数据结构具有的一组操作出现在65-66页，至于该数据结构是什么，由该文件所在的
最近一级目录名指明。

修改算法实现（操作）文件名的命名惯例。算法操作实现的C程序文件名修改如queue_basic_op.c文件
名形式，queue位置代表的是数据结构类型，basic意味该数据结构的基本算法操作。op为operation的
简记。从3_stack_queue_array/example_algorithm/queue/link_queue/起加入Makefile，方便编译与
运行。

文本文件都没有.txt后缀，这之于Windows系统可能有些麻烦，可以通过以下几种方式解决：
1，在Github网页上查看。
2，在Windows系统中修改这样的文件名，加上.txt后缀。
