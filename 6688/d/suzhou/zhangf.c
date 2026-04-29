//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"镖局帐房"NOR);
	set("long", @LONG
		这是镖局管理帐目的地方，地方不大，可也不小，人虽然不多，
但都很精干，主持的是一个年青人，大家看上去对他都很尊敬。房中有一张桌子，
十来把椅子，现在帐房中的人正坐在椅子上聊天。北边一道门，门后面传来轻微
的读书声，让人禁不住地好奇。
LONG	
	);
//	set("no_fight","1");
	set("exits",([
	"west" : __DIR__"lwchang",
	"north" : __DIR__"school.c",
	]));
	set("objects",([
	__DIR__"npc/zhangf" : 1,
	]));
	create_door("north","青竹门","south",DOOR_CLOSED);

	setup();
}

int valid_leave(object me, string dir)
{
        if ( !me->query("biao_ju") && dir == "north"  
&& (present("lin taiping", environment(me))))
        return notify_fail("林太平伸手拦住你,道：" + RANK_D->query_respect(me) + 
",这后面是我镖局中人学艺的地方，请止步。\n");
        return ::valid_leave(me, dir);
}