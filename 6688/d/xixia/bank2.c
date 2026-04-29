// Room: /d/xixia/bank2.c

inherit ROOM;

void create()
{
	set("short", "幽兰涧旁");
	set("long", @LONG
这里是深涧的另一边，前边你看到了一大片竹林。再走下去，也
不知道是福是祸，不过既然已经走到这里，只有硬着头皮走下去。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"gangsi",
  "west" : __DIR__"bamboo1",
]));

	setup();
	replace_program(ROOM);
}
