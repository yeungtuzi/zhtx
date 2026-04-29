// Room: /d/xixia/eroad10.c

inherit ROOM;

void create()
{
	set("short", "宫中小径");
	set("long", @LONG
这里不过是皇宫内一条寻常的小径，路两旁或假山、或花坛，或
或亭台、或楼阁，前面突然传来一股饭香，你的肚子不禁咕噜咕噜的
响了起来。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"echufan",
  "west" : __DIR__"eroad9",
]));

	setup();
	replace_program(ROOM);
}
