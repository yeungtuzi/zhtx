// Room: /d/xixia/yongdao.c

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
进了山洞，又是一条长长的甬道，这回真的是完了！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"neishufang",
  "out" : __DIR__"ygate",
]));

	setup();
	replace_program(ROOM);
}
