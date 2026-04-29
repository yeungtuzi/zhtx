//ROOM: d/hangzhou/wlmen.c
// by tlang
// 97.11.4

#include <ansi.h>
inherit ROOM;   

void create()
{
	set("short", YEL"武林门"NOR);
	set("long", @LONG
	  人常说江南的春色若有十分，那么有七分是在杭州，杭州的春色若有十分，
那么有七分是在西湖。其实很是正确，武林门外的秀丽景色深刻地体现了这些话的内
容。站在武林门外，只见轻雪般的垂柳，半开的红荷，朦胧的远山倒映在闪动着金光
的湖水里。
LONG
	);
	set("no_sleep_room",0);
	set("outdoors","suzhou"); 
	set("exits", ([
		"west" : __DIR__"gchang",
		"east" : __DIR__"xhroad",
]));  

	set("objects", ([
		 "/d/suzhou/npc/bing" : 3,
		 "/obj/npc/wujiang1"+random(3) : 1,
]));
	setup();
}   
    

void init()
{
        object me,guanchai;

        me = this_player();

        if( interactive(me) && me->query("pk_exp") > 0 && !me->query_temp("be_ki
lled"))
        {
        message_vision(HIR "突然间斜刺里冲出一个官差！\n\n" NOR, this_player());
        guanchai=new("/d/city/npc/guanchai");
        guanchai->move("/d/city/dongmen");
        write(RED"官差大喝道：你欺凌弱小，拿命来！\n"NOR);
        }


}

int valid_leave(object me, string dir)
{

        if( me->query("pk_exp") > 0 )
        {
                return notify_fail("你还没有对付官差，怎么离开这里？\n");
        }
        return ::valid_leave(me, dir);
}







