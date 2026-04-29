inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这是一个水底的小洞，光线阴暗，偶尔有一两个漩涡。靠里边有
数个骷髅，象是为抢什么东西互相残杀而死的。隐隐，你觉得脚下踩
着什么一本书。
LONG
        );
        set("exits", ([ 
  
  "out" : __DIR__"dixiahe6",
  
]));
       set("objects",([
                __DIR__"obj/jiuyin-zhenjing1.c" : 1,
		
        ]));
        setup();
}

