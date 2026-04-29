// Room: /open/p/pock/huayuan.c

inherit ROOM;

void create()
{
	set("short", "[35m大花园[2;37;0m");
	set("long", @LONG
这里原来是松风观后面的一块空地，后来经过好些人的努力，终于把这里改造
成了一个大花园。这里地理因为处于青城山山腰的原因，花开得又红又滟。为青城
的秀更添几分色彩。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"guan1.c",
		"north" : __DIR__"zoulang2",
]));

	setup();
	replace_program(ROOM);
}
