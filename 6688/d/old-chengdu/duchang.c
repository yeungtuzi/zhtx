
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIR"纵横天下赌场"NOR);
	set("long", @LONG
这里是纵横天下赌场的大堂，四周的房间里传出来吆五喝六的
赌博声。墙上挂着一块牌子(paizi)。上面是为玩家服务的拱猪
房，可以找几个朋友一起来拱猪。
LONG
	);

	set("item_desc", ([
		"paizi" : "二楼的拱猪房正处于测试阶段。\n",
	]));
	set("exits", ([
                //"west" : "/u/ding/daxiao",
		"up" : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}

