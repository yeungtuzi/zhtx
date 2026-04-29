// /d/xizang/shop2.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "货物仓库");
        set("long", @LONG
这里是鹰记商号的货仓,里面堆满了商家交托运送的货物.
LONG
        );
        set("exits", ([
                "west" : __DIR__"storage",
		"south": __DIR__"shop",
        ]));
	set("objects", ([
		OBJ_DIR"toy/goods" :random(9),
]));
	set("has_sun", 1);
	create_door("south", "木门", "north", DOOR_CLOSED);
        setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	object me, ob;
	if(!arg || (arg!="goods" && arg!="货物"))
		return notify_fail("你要搜查什么?\n");
	me=this_player();
	if(me->query_str() < 30)
	return notify_fail("你试图搜查一下货箱后面,但是怎么也搬不动它们.\n");

	message_vision("$N搬开每个货箱仔细搜查了一阵,累得满头大汗!\n", me);
	me->add("workpoints", random(30)+1);

	if((me->query("kar") > random(30)+10) && query("has_sun")>=1) {
		message_vision(
"在一个大箱子后面,$N发现有面金光闪闪的盾牌!\n", me);
		ob=new(__DIR__"npc/obj/sun");
		ob->move(me);
		add("has_sun", -1);
		return 1;
	}
	message_vision("但是什么也没有发现!\n", me);
	return 1;
}

void reset()
{
	::reset();
	set("has_sun", 1);
}
