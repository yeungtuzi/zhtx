// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"后房"NOR);
	set("long", @LONG
	这是女仆们睡觉的地方。粉红色的轻纱挂在窗户上，似乎把外面的世界
也隔开了，显的相当安静。
LONG
);
	set("exits",([
	"east" : __DIR__"s_zhf",
	]));

/*	set("objects",([
	__DIR__"npc/jiading" : 1,
	]));
*/
	set("sleep_room",1);

	setup();
	replace_program(ROOM);
}
