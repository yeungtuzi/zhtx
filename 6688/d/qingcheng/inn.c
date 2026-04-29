// Room: /open/hihi/inn.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",YEL "无醉不归家" NOR);
	set("long", @LONG
这是一个很大的酒店，在这里，你能买到方圆百里最好的酒，能订到
最好的筵席。 一切都摆的恰到好处， 来到这里，真有一种宾至如归的感
觉。真不愧叫"无醉不归家"啊。门外一面大旗(flag)正迎风飘展，在厅的
尽头，有一幅狂草(writing)不知道出自何人之手。
LONG
	);
 set("valid_startroom", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"innup",
  "east" : __DIR__"jie11",
]));
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/boss" : 1,
  __DIR__"npc/waiter" : 1,
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "writing" : "你好不容易才认出来上面写的是："+RED "何日君再来.\n"NOR,
  "flag" : CYN"                     无醉不归家 !\n"NOR,
]));

	setup();
	replace_program(ROOM);
}
