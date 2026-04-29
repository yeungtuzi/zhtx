// Room: /d/xixia/southstreet3.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
一条由白石板铺成的宽敞街道，北边是皇宫的永定门，所以这里
行人不多，不过常有轿子马车之类的通过，有时也有禁卫军，都是秩
序井然，往南通向南城门。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southstreet2",
  "north" : __DIR__"psouthgate",
]));

	setup();
	replace_program(ROOM);
}
