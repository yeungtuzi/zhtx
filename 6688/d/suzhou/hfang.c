//ROOM:/d/suzhou/hfang.c
//by dwolf
//97.11.4 

#include <ansi.h>
#include <room.h>
inherit ROOM;

/*string* npcs = ({
        "longwu",
        "guodl",
	"yanqi",
	"wangd",
});*/


void create()
{
//	int i = random(sizeof(npcs));

	set("short", MAG"后房"NOR);
	set("long", @LONG
 	  这是镖局长老们进修的地方，但他们有时外出，不一定都在。屋子里
挂着一些字画。屋子西边放着一张床，床边挂着一把宝剑。
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"south" : __DIR__"dzju",
        ]));

        set("objects", ([
	__DIR__"npc/longwu" : 1,
	__DIR__"npc/wangd" : 1,
	]));
	
	create_door("south", "花雕门", "north", DOOR_CLOSED);                                 

	setup();
}

