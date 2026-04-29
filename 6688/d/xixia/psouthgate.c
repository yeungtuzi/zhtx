// Room: /d/xixia/psouthgate.c

inherit ROOM;

void create()
{
	set("short", "永定门");
	set("long", @LONG
这里是通向皇宫的南门──永定门，宫墙上盖着硫璃瓦，熠熠生
光。朱漆刷着的宫门上整整齐齐地钉着九九八十一枚铜钉，宫门前不
远处树立着两根华表，以求苍天庇佑。宫门两旁各站着两个侍卫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"eroad1",
  "south" : __DIR__"southstreet3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shiwei" : 4,
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
