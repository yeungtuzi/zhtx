// Room: /d/xixia/libu.c

inherit ROOM;

void create()
{
	set("short", "礼部");
	set("long", @LONG
这里是礼部，掌管礼仪、祭享、贡举等职。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"eroad4",
]));
	set("objects", ([
		__DIR__"npc/tao": 1,
	]));

	setup();
	replace_program(ROOM);
}
