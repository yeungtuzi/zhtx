// This is roar's room

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "撒拿旦的大殿");
	set("ghostplace",1);
	set("long", @LONG
不要过于在乎自己的得失，死亡就如同出生，成长，衰老一样，是生命的普遍
过程，如果不能死亡，生命也就失去了意义。不仅仅生命会死亡，我们平常所见的
万事万物----太阳，月亮，星辰，大海，甚至宇宙本身，都会死亡，只有生生死死
无限循环，才是自然的真谛
LONG
	);
	set("exits",([
		"back" : __DIR__"deathhall",
	]));
	setup();
/*	replace(ROOM);*/
}
