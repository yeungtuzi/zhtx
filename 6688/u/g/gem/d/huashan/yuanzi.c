//yuanzi.c 院子
//by emote
inherit ROOM;
#include <room.h>
void create()
{
	set("short","院子");
	set("long",
@LONG
进了大门以后就是一个偌大的院子，院子里面站了不少华山的弟子，他
们正在聚精会神的练功。南走是华山派驻地的主厅--正气堂，西边则是厨房，
东边是众弟子的卧室。
LONG);
        set("exits", ([ /* sizeof() == 2 */
		"north"  : __DIR__"gate",
		"south"  : __DIR__"zhengqitang",
		"west"   : __DIR__"chufang",
		"east"   : __DIR__"sleeproom",
		
]));
        set("objects", ([
                 CLASS_D("huashan") + "/dayou":1,//高根明
		 CLASS_D("huashan") + "/yueling":1,//岳灵珊
		 __DIR__"npc/xiaotong":2,
]));

		create_door("north", "红木大门", "south", DOOR_CLOSED);
        	set("valid_startroom", 1);

		set("outdoors","huashan");
		setup();
		        "/obj/board/huashan_b"->foo();
}

