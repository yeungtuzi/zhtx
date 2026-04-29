// sanqingdian.c 三清殿
// by Xiang

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "三清殿");
	set("long","这里是凌霄宫的三清殿，是武当派会客的地点。供着元始天尊、太上道君和天
上老君的神像，香案上香烟缭绕。正厅上高挂着

                        " + YEL "三     清     殿" NOR + "

靠墙放着几张太师椅，地上放着几个蒲团。东西两侧是走廊，南边是练武的广场，
北边是后院。\n");
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"houyuan",
		"east" : __DIR__"donglang1",
		"west" : __DIR__"xilang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/guxu" : 1,
		CLASS_D("wudang") + "/song" : 1]));
	setup();
//	replace_program(ROOM);
	"/obj/board/wudang_b"->foo();
}

