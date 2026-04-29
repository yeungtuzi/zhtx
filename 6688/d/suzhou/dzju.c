// Room: /d/suzhou/dzju.c
//by dwolf 
//97.11.5

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",MAG"弟子居"NOR);
	set("long", @LONG
	这是镖局男弟子睡觉的地方。里面放着十几张小床，上面睡了一些弟子，
只有东边有几张空床。北边有道门，可以通向镖局长老们休息的地方。
LONG
	);               
	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_light", 1);

	set("exits", ([
		"southwest"  :__DIR__"bjhyuan", 
		"north" : __DIR__"hfang",
	]));                                
	create_door("north", "花雕门", "south", DOOR_CLOSED);

	setup();
}

