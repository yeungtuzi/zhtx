//gate.c 大门
//by emote
inherit ROOM;
#include <room.h>
void create()
{
	set("short","大门");
	set("long",
@LONG
这里就是威镇江湖的华山派的驻地了。这里有一扇巨大的红木大门，不
过一般都是关上的。门口有个精神的小伙子在看守着，旁边还站着几个小弟
子，看来是正在练功的了。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"north"  : __DIR__"luoyan",
		"south"  : __DIR__"yuanzi",
		
]));
        set("objects", ([
                 __DIR__"npc/luo":1,//罗白英
				 __DIR__"npc/xiaotong":2,
]));

		create_door("south", "红木大门", "north", DOOR_CLOSED);


		set("outdoors","huashan");
		setup();
		replace_program(ROOM);
}

