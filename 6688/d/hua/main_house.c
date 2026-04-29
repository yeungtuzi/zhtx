inherit ROOM;

void create()
{
	set("short", "村长府邸");
	set("long", @LONG
这是本村最大的宅院。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"villige",
]));
	set("objects", ([
		__DIR__"npc/cunzhang": 1,
	]));
	setup();
}
