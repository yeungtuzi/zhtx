// 幽明山庄
// by yeung. All rights reserved.

#include <ansi.h>

inherit "/std/room/doom.c";

void create()
{
	set("short", "幽明山庄正门");
	set("long", 
"       幽明山庄现在就耸立在你的面前，这山庄看起来已久久无人居住，\n"
"大雪堆积在檐上，瓦上，廊上，梁上，隐隐有一股杀气透出来。庄墙外到处\n"
"是积雪，一支生锈的铁箭订在墙上，兀自涔涔滴血。雪地上是触目惊心的血\n"
"字：\n"+
HIR"                      一 入 幽 冥 庄\n"
   "                      此 生 不 还 乡\n\n\n"NOR
	);

	set("exits", ([ /* sizeof() == 2 */
	  "north" : __DIR__"yongdao1",
	  "south" : __DIR__"xueyuan",
	]));
	

	setup();
}
