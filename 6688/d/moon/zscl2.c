/* 通往再生草庐的小路 蓝凤剑客柳栖梧 墨龙剑侠龙坚石
   zscl2.c */

inherit ROOM;  

void create()
{
        set("short", "王屋山小路");
        set("long", @LONG
此处王屋山中，耳畔但闻得山林松涛,一对中年剑客走在前面，时不时低声私语，好不恩爱！
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"zscl3",
  "westdown" : __DIR__"zscl1",
]));
        set("objects", ([
        __DIR__"npc/longjianshi" : 1,
        __DIR__"npc/liuqiwu" : 1,

                        ]) ); 
   setup();      
   replace_program(ROOM);
}
