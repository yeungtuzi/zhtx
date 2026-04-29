// Room: /d/xixia/eroad9.c

inherit ROOM;

void create()
{
	set("short", "御道");
	set("long", @LONG
走到这里，你感到胸怀登宽，原来这里院落较前面大为开阔。眼
前你看到一条御道笔直地通向前方，御道全部铺上红地毯，看上去甚
是触目。
LONG
	);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"eroad10",
  "north" : __DIR__"ebridge",
  "south" : __DIR__"wumen",
  "west" : __DIR__"eroad11",
]));

	setup();
	replace_program(ROOM);
}
