//kedian1.c 如归客栈
//written by pock 


#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", CYN"如归客栈"NOR);
	set("long", @LONG
一间开在繁华地带的客栈，它的老板可真找到了黄金地段。这里客人很多，
因为这里的服务可以说是京城最好的，整个客栈的装修非常接近于家庭的特色，
果然可以称为“宾至如归”。
LONG
	);
        set("no_sleep_room",1);


	set("exits", ([
		"west" : __DIR__"xisi",
		"north":__DIR__"kezhan4",
		]));
	set("objects",([
		__DIR__"npc/xiaoer":1,
		]));
	setup();


}
int valid_leave(object me, string dir)
{
         if ( me->query_temp("riden") && dir == "north")
                return notify_fail("这个地方不能骑马过去。\n");
         if ( !userp(me) && dir == "north" )
                        return 0;      
       if ( !me->query_temp("rent_paid") && dir == "north" )
        return notify_fail("店小二笑嘻嘻地双手一拦，道：“客官请先交钱后住店。每天五两银子。”\n");
        return ::valid_leave(me, dir);    
}
