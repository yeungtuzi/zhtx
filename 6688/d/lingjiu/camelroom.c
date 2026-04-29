// Room: /d/lingjiu/camelroom.c

inherit ROOM;

void create()
{
	set("short", "骆驼房");
	set("long", @LONG
这里是灵鹫宫伺养骆驼的地方，灵鹫宫偏处西北，多沙漠和
干旱之地，在这种情况下，骆驼就有用了。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"leftroad",
]));
	set("objects", ([
		__DIR__"npc/camel" : 2,
	]));

	setup();
	replace_program(ROOM);
}
