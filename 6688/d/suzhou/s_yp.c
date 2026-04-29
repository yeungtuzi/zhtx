// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"药铺"NOR);
	set("long", @LONG
	 这里是一间规模不小的药铺，奇怪的是，在这里你闻不到一丝药铺
应有的药味，有的只是一股淡淡的檀香，令人觉得心旷神怡，药铺的柜台就在
店□靠北的一面，柜台後是一个巨大的药柜， 上面的小抽屉只怕有七、八百
个之多，但是全部没有贴标签。
LONG
);

	set("exits",([
	"south" : __DIR__"s_slx5",
	]));
	
	set("objects",([
	__DIR__"npc/s_yang" : 1,
	]));

	setup();
	replace_program(ROOM);
}
