// Room: /class/qingcheng/port.c

inherit ROOM;

void create()
{
	set("short", "[33m小河边[2;37;0m");
	set("long", @LONG
小河边的一草一木都是如此的青翠，使人心中的那一团绿浓的化也化不开。
这里的水是青的，远方的山是绿的，的确是一个清修的好去处。
		  说不定有些贤士高人在附近隐居呢？
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
//                __DIR__"npc/mudaoren" : 1,
//                "/obj/gf/secret/npc/mudaoren" : 1,
                "/u/z/zephyr/mudaoren" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"bridge",
		"east" : __DIR__"nankou1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
