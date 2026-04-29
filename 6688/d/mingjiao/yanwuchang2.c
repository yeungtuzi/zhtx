
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIY"右演武场"NOR);
	set("long", @LONG	
	这是明教演武操练的地方，巨大的青条石铺就的广场十分的平坦，四面
放满刀枪剑戟等十八般兵器。
LONG
	);

	set("valid_startroom",1);
	set("exits", ([
		"east"  : __DIR__"zoulang2",
		"west"  : __DIR__"yanwuchang",
	]));

	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}