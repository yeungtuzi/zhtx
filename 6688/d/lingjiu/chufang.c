// Room: /d/lingjiu/chufang.c

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里是灵鹫宫的厨房，几个灵鹫宫的弟子正在忙碌着。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
	set("objects", ([
		__DIR__"npc/lanjian" : 1,
		__DIR__"npc/dizi" : 2,
		__DIR__"obj/suancaiyu" : 1,
		__DIR__"obj/lobster" : 1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
