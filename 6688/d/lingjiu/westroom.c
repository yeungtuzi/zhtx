// Room: /d/lingjiu/westroom.c

inherit ROOM;

void create()
{
	set("short", "护具库");
	set("long", @LONG
这里是灵鹫宫的护具库。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"floor",
]));
	set("objects", ([
		__DIR__"npc/obj/cape" : 1,
		__DIR__"npc/obj/cloak" : 1,
		__DIR__"npc/fumy" : 1,
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
