// /d/xizang/zmlm0.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/ice.h"

void create()
{
        set("short", "冰台阶");
        set("long", @LONG
这里是珠穆朗玛峰北坡的一道冰台阶,它有两人多高,结满坚冰,武功不高的人空
手是决计爬不上去的.
LONG
        );
        set("exits", ([
		 "southup" : __DIR__"zmlm1",
		"eastdown" : __DIR__"xmly8",
]));
	set("outdoors", "xizang");
        setup();
//        replace_program(ROOM);
}

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
        remove_call_out("freezing");
        call_out("freezing", 1, ob);
        }
}

int valid_leave(object me, string dir)
{
	if(dir="southup") {
	if((int)me->query("kee")< 100)
		return notify_fail("你实在走不动了,还是赶快下山吧.\n");
	if( random((int)me->query_skill("dodge")) <= 50) {
message_vision(HIC "$N试了试,实在无法翻越冰坎,只好废然而返.\n"NOR ,me);
	me->start_busy(random(3));
	return notify_fail("");
	}
	if( (int)me->query_skill("dodge") >=150) {
message_vision(HIC "$N提气纵身,拔地而起,跃上了冰坎!\n"NOR, me);
CHANNEL_D->do_channel(me, "chat", sprintf("%s哈哈哈大笑了几声.", me->name(1)));
	return 1;
	}
message_vision(HIC "$N费了九牛二虎之力,终于爬上了冰坎!\n"NOR, me);
	me->start_busy(random(5));
	me->add("kee", -50);
	return 1;
	}
	return ::valid_leave(me, dir);
}
