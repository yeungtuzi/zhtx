// /d/xizang/zmlm3.c

inherit ROOM;
#include <ansi.h>
#include "/d/xizang/zmlm.h"

void create()
{
        set("short", "世界屋脊");
        set("long", @LONG
这里距天下最高的珠穆朗玛峰顶不过数步之遥,能爬到这儿的人已经很少了.由此
往南就是无数人渴望登上的最高峰顶,往东是下山的路.
LONG
        );
        set("exits", ([
		"eastdown" : __DIR__"zmlm2",
		 "southup" : __DIR__"zmlm4",
]));
	set("outdoors", "xizang");
        setup();
}

void init()
{
        object ob;
        if( interactive( ob = this_player()))
        {
	remove_call_out("freezing");
        remove_call_out("choke");
        call_out("choke", 1, ob);
        }
}

int valid_leave(object me, string dir)
{
	if(dir="southup") {
	if((int)me->query("kee")< 100) 
		return notify_fail("你实在走不动了,还是赶快下山吧.\n");
	if( random((int)me->query_skill("dodge")) <= 100) {
message_vision(HIC "$N试了试,实在无法翻越冰坎,只好废然而返.\n"NOR, me);
        me->start_busy(random(3));
        return notify_fail("");
        }
	me->add("kee", -90);
	CHANNEL_D->do_channel(me, "rumor",
		sprintf("%s终于成功地登上了世界屋脊!\n", me->name(1)));
        if (!me->query("marks/^U^W^W^^^J^@^]^G^N^]^\^Y")) {
		me->set("marks/征服世界屋脊",1);
		me->add("combat_exp", 1000);
	}
message_vision(HIC "$N费了九牛二虎之力,终于爬上了珠穆朗玛峰顶.\n"NOR, me);
	return 1;
	}
	return ::valid_leave(me, dir);
}
