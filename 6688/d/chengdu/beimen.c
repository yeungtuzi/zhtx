// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
	这是北城门。出了城往东北方向走就到了剑门关了,北方是一片崇山
峻岭，一条栈道在山里蜿蜒而上。西南方向就是名震川中的青城派的所在地。
往北走是一条笔直的甬道，两边种满了柏树，那就是诸葛孔明的祠堂所在了。
LONG
	);


	set("exits", ([
		"south" : __DIR__"beidajie1",
		"north" : __DIR__"bailin1",
		"northwest" : "/d/qingcheng/qchyidao", //need to be modified
		"northeast" : "/d/road/rjmtocd2"  // need to be modified
	]));

        set("objects", ([
                "/obj/npc/wujiang10" : 1,
                "/obj/npc/bing" : 2,
        ]));

	set("outdoors", "city");
	setup();
}

