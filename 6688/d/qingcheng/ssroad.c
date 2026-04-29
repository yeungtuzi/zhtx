// Room: /class/qingcheng/ssroad.c

inherit ROOM;

void create()
{
	set("short", "[33m幽径[2;37;0m");
	set("long", @LONG
 这是一条用用青石铺成的大道，它已经被来往的车马碾的有点不平整了.
它是连接中原和福州的要道。它的南边有一个小亭。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/doctor" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"beikou1",
		"northwest" : __DIR__"yidao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
