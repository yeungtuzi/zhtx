// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"林氏饭馆");
	set("long", @LONG
	这是林太平家开的连锁饭馆，虽然没有八仙楼那么气派，但其实力却是
不可忽视的。现在正是热季，里面有不少吃客。
LONG
);

	set("exits",([
	"north" : __DIR__"s_slx",
	]));
	
	set("objects",([
	__DIR__"npc/s_xer" : 1,
	__DIR__"npc/ren" : 2,
	]));

	setup();
	replace_program(ROOM);
}
