// Room: /u/p/pock/bj/duixiu.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"堆绣山"NOR);
	set("long", @LONG
皇宫建立在一片非常平的平地上，没有什么高低起伏的地方，本来是没有什么山
的，后来皇上命人建造了这座假山，再在山上建了一个小亭。每年重阳的时候，皇上
率领众妃子来此登高。故这山又叫堆秀山。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"road",
	]));
	set("outdoor","bj");
	setup();
	replace_program(ROOM);
}
