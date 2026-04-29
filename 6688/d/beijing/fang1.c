#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"房舍"NOR);
	set("long", @LONG
这里是一间小屋，物品多而杂，可见这里的主人平时是没有多少时间去整
理的。一个太监正在唠叨，可能是今天碰到了什么不顺心的事吧，看来还是不
要在这里随便走动，要是他嚷嚷起来，侍卫一来就不容易脱身了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"zoulang1",
	]));
	set("objects", ([
		__DIR__"npc/taijian":1,
	]));

	setup();
	replace_program(ROOM);
}



