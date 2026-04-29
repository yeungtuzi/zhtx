// Room: /d/qingcheng/yidao.c

inherit ROOM;

void create()
{
	set("short", "驿道");
	set("long", @LONG
这里是武夷山旁的一条驿道，往东南方向可以到福州。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : "/d/quanzhou/qzroad5",
		"southeast" : __DIR__"ssroad",
]));

	setup();
	replace_program(ROOM);
}
