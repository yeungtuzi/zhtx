// Room: /d/xixia/northroad1.c

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
从此往北出中兴府是一望无际的大漠，狂风呼啸，狂沙漫
卷，除了商人驮队，自来少有行人。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"northbridge",
]));

	setup();
}

void init()
{
	__DIR__"northgate"->init();
}
