// Room: /d/xixia/ypath1.c

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这是一条长长的甬道，走在里面你只听见自己的脚步声，甬
道两边石壁上虽然点着油灯，但还是看不出甬道的深浅。你不禁
有些提心掉胆。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"neitang",
  "west" : __DIR__"ypath2",
]));

	setup();
	replace_program(ROOM);
}
