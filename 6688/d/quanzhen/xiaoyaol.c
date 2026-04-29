// Room: /u/hacky/quanzhen/xiaoyaol.c
// Made by: hacky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[35m逍遥楼[2;37;0m");
	set("long", @LONG
这就是全真教众教徒休息娱乐的地方，房间很大，外形给人一种平易近人之感，
几个小十几岁的小道童正在这里嘻戏玩耍，全真七自也经常在这里交流切磋武功。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jingsy.c",
  "north" : __DIR__"youxiang.c",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhaozhij.c" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
