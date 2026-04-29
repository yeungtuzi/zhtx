// /d/xizang/zmlm2.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/zmlm.h"

void create()
{
        set("short", "珠穆朗玛峰北侧");
        set("long", @LONG
这里已经接近珠穆朗玛峰的最高处,地势反而平缓.站在这里极目四望,可以看到
远远近近的雪峰连绵起伏,如同大海上的波浪.你将视野收回近处,注意到在一片莹白
的冰雪中嵌着一两块拳头大小的雪色石头(stone),看上去非常可爱.
LONG
        );
	set("item_desc", ([
	"stone" : "这是块雪白的小石头,似乎可以带(take)回去作个纪念.\n",
	 "石头" : "这是块雪白的小石头,似乎可以带(take)回去作个纪念.\n",
	]));
        set("exits", ([
		"northeast" : __DIR__"zmlm1",
		   "westup" : __DIR__"zmlm3",
]));
	set("outdoors", "xizang");
	set("stone", 1);
        setup();
//        replace_program(ROOM);
}

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
	add_action("do_take", "take");
	remove_call_out("freezing");
        remove_call_out("choke");
        call_out("choke", 1, ob);
        }
}

int do_take(string arg)
{
	object ob, me;
	if (!arg || (arg=="")) return notify_fail("你要拿什么?\n");
        if ((arg!="stone") && (arg!="石头") && (arg!="小石头"))
                return notify_fail("这里没有" + arg +"可拿\n");
	if (!me->query_temp("weapon") && !me->query_temp("secondary_weapon"))
		return notify_fail("空手可无法挖出嵌在冰块里的石头.\n");
        me = this_player();
        ob = new(__DIR__"obj/icestone");
        ob->move(me);
        add("stone", -1);
        return 1;
}

void reset()
{
        ::reset();
        set("stone", random(2));
}
