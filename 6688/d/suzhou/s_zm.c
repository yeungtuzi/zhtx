// This is a room made by roommaker.
//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"甑家大门"NOR);
	set("long", @LONG
	这是苏州地段有名的乡绅甑士隐老先生的家，大门虽然已经年代久远，
但依然气派，几个家丁站在门口，注视着来往的行人。	
LONG
);
	set("exits",([
	"north" : __DIR__"s_slx2",
	"south" : __DIR__"s_zqt",
	]));

	set("objects",([
	__DIR__"npc/jiading" : 1,
	]));

	setup();
	replace_program(ROOM);
}
