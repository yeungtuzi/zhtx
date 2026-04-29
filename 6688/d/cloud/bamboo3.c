//write by lysh

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "张家花园");
	set("long", @LONG
这是张家的花园，绮云镇最大的花园，花草丛生。由于张百万
不见外人，深宅大园中，这里人迹罕至，惟闻足底叩击路面,微
风吹拂叶，又如簌簌低吟。令人尘心为之一涤，真是绝佳的所在。
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"bamboo"+(random(5)+1),
		"southwest" : __DIR__"bamboo"+(random(5)+1),
		"northwest" : __DIR__"bamboo"+(random(5)+1),
		"southeast" : __DIR__"bamboo"+(random(5)+1),
		"south" : __DIR__"bamboo"+(random(5)+1),
		"north" :__DIR__"bamboo"+(random(5)+1),
                "east" :__DIR__"xiaoting",
                "west" : __DIR__"bamboo4",
	]));
        set("objects", ([
        __DIR__"obj/huacao" : 1,
                        ]) );

	set("outdoors", "zhang");

	setup();

}



int valid_leave(object me, string dir)
{

	if (dir == "west" ) me->add_temp("bamboo/count", 1);
	
	else 			 me->set_temp("nofindout", 1);

	return ::valid_leave(me, dir);
}


