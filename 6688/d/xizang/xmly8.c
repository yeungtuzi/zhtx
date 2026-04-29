// /d/xizang/xmly8.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰川");
        set("long", @LONG
这是一道从喜马拉雅山绝顶延伸下来的冰川,顺着它应该就可以攀上天下最高
的山峰--珠穆朗玛峰.珠穆朗玛是藏语中第三女神的名字, 这座山峰亦被藏民视为
神圣之地,有着无数美丽的传说.
LONG
        );
        set("exits", ([
		   "westup" : __DIR__"zmlm0",
		"northdown" : __DIR__"xmly7",
]));
	set("objects", ([
		__DIR__"npc/snowman" : random(2),
	]));
	set("outdoors", "xizang");
        setup();
//        replace_program(ROOM);
}

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
        remove_call_out("freezing");
        call_out("freezing", 1, ob);
        }
}
