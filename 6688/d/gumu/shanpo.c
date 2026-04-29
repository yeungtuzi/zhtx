// Room: /d/gumu/山坡.c 
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "山坡");
        set("long", @LONG
    这儿是少室山下的一个小山坡，西边是一片平原，平
原那边隐隐可以看见的是一群山峰，东边就是著名的少室山，
这儿不断有人来来往往，大多数是上山还愿的，少数人太阳穴
凸凸的，一眼可以看出是武林中人。


LONG
        );
       set("exits", ([  
  "westdown" : __DIR__"pingyuan.c",
 "eastup" : "/d/shaolin/shijie4",
 
 
]));
 /* set("objects", ([
                __DIR__"npc/yangnu" : 1,
        ]));*/
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}