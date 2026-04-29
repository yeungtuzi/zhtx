// Room: /d/jingcheng/djdp.c
// Made by: ysgl

#include <ansi.h>
inherit HOCKSHOP;

void create()
{
	set("short", "[1;37m唐记当铺[2;37;0m");
	set("long", @LONG
这是蜀中最大的一家当铺了。素来以买卖公平著称。门口挂了一块牌
子 (paizi)。当铺老板据说是蜀中唐门的人。所以一般人不敢到这里惹事
生非。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongdajie2",
]));

    set("dangpu_location","chengdu");
	setup();
}
