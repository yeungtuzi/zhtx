
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY"殿前演武场"NOR);
	set("long", @LONG	
	这是明教大较武艺之所在，每逢五年中秋之期，教主都会在此主持
比武大会，并从中挑选出类拔萃的人才收为光明使者。其中最出色者将成为
掌教弟子，由教主亲传明教至高无上的护教神功 - 乾坤大挪移。
LONG
	);

	set("valid_startroom",1);
	set("exits", ([
		"west"  : __DIR__"yanwuchang1",
		"east"  : __DIR__"yanwuchang2",
		"north" : __DIR__"guangmingding",
		"southdown" : __DIR__"shijie5",
	]));

	set("outdoors", "mingjiao");
	set("no_fight",1);
	set("no_magic",1);
	set("no_poison",1);
	set("no_clean_up",1);
	setup();
	replace_program(ROOM);
}