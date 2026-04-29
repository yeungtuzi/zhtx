
inherit ROOM;

void create()
{
        set("short", "小桥流水");
        set("long", @LONG
一条清澈的小溪上横跨着一座木桥。桥的那边是一片茂盛的竹林。
在竹林与梅花的掩映之中，一座精巧的庄院若隐若现。蝴蝶在你的
身边上下盘旋。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"hdg1",
  "south" : __DIR__"entrance",
]));
        set("outdoors", "mingjiao");

        setup();
        replace_program(ROOM);
}

