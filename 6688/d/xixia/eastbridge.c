// Room: /d/xixia/eastbridge.c

inherit ROOM;

void create()
{
	set("short", "吊桥");
	set("long", @LONG
这是一架可以随时升放吊桥，走在上面嘟嘟直响，桥
下护城河水绕城而流，只是河水看起来并不怎么清澈。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"eastroad1",
  "west" : __DIR__"eastgate",
]));

	setup();
	replace_program(ROOM);
}
