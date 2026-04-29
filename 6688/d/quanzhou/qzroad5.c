// Room: /d/quanzhou/qzroad5.c

inherit ROOM;

void create()
{
	set("short", "武夷山路");
	set("long", @LONG
你走在东南第一山脉武夷山上。海风从东面吹来，带着几分寒意。
南边就是著名的海港泉州了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"east" : "/d/qingcheng/yidao",
		"northwest" : "/d/road/rfztoyt1",
		"south" : "/d/quanzhou/beimen",
]));
	set("objects", ([ /* sizeof() == 1 */
		"/d/wudang/npc/yetu" : 2,
]));
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
