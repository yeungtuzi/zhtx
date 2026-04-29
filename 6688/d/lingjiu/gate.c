// Room: /d/lingjiu/gate.c

inherit ROOM;

void create()
{
	set("short", "灵鹫宫门前");
	set("long", @LONG
走近城堡，迎面一扇巨石大门，高达五丈，气势逼人。抬头你看到门上
巨幅匾额上大书三字“灵鹫宫”，笔意纵横，不可一世。石门左右两边
各立一只高约三丈的石鹫，嘴喙爪利，神态可怖。四周是松海，难知尽
头，城堡傲然拔起，上端雾气缭绕，疑与天接。俯瞰峰下，众生渺小，
唯我灵鹫宫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"floor",
  "south" : __DIR__"entrance",
]));
	set("outdoors", "lingjiu");
	set("objects", ([
		__DIR__"npc/chengqs" : 1,
		__DIR__"npc/dizi9" : 2,
]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
