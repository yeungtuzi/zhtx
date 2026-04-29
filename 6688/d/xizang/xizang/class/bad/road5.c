// /d/xizang/class/bad/road5.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "石板街");
	set("long", @LONG
这是一条青石板铺成的街道,北边是个转角,南边不远有座石砌大屋,檐下高悬一
块大匾(sign),东边堆了些石料(stones),西边是酒铺.四外远处群山环抱,连绵不绝.
LONG
);
	set("item_desc", ([
	"sign" 	 : HIY+"唯我独尊堂"+NOR+"\n",
	"stones" : "这是一堆自附近山中开采来的石料,堆在这里好象很久了\n",
	]));
	set("exits", ([
		"north" : __DIR__"road4",
		"south" : __DIR__"road6",
		 "west" : __DIR__"w_shop",
	]));
	set("outdoors", "xizang");
        setup();
	replace_program(ROOM);
}
