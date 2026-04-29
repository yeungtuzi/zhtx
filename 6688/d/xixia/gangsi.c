// Room: /d/xixia/gangsi.c

inherit ROOM;

void create()
{
	set("short", "钢丝上");
	set("long", @LONG
这是一根极细的钢丝，且漆得黑黝黝的，若不凝神细看，还真难发现。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bank1",
  "west" : __DIR__"bank2",
]));

	setup();
	replace_program(ROOM);
}
