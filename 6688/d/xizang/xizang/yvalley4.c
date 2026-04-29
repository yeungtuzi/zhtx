// /d/xizang/yvalley4.c

inherit ROOM;

void create()
{
        set("short", "峡谷");
        set("long", @LONG
这里是雅鲁藏布江北岸的峡谷.
LONG
        );
        set("exits", ([
   "southeast" : __DIR__"yvalley3",
     "northup" : __DIR__"mountain",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
