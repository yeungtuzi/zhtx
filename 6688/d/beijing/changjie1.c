// Room: changjie1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", CYN"十里长街"NOR);
	set("long", @LONG
你走在一条繁忙的街道上，这里车水马龙，人来人往，热闹非凡。街道
的南边是一家钱庄，北边是一个茶馆，茶馆中喧哗声源源不断的传来，看来
生意非常的不错。
LONG
	);
        set("outdoors", "city2");


	set("exits", ([
		"east" : __DIR__"changjie2",
		"south" : __DIR__"qianzhuang",
		"west" : __DIR__"aobai1",
		"north" : __DIR__"chaguan",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));

	setup();
	replace_program(ROOM);
}

