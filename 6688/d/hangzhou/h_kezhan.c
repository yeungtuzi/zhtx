//by tlang

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG "西子客栈" NOR);
	set("long", @LONG
	这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落
脚，你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接
待着南腔北调的客人。客店的主人从不露面，据说就是西施。墙上挂着一个
牌子(paizi)。北边西湖边有个亭子。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
        "paizi" : "楼上客房，每夜五两白银。\n",
	]));

	set("exits", ([
		"northeast" : __DIR__"h_nslu2",
		"north" : __DIR__"hsting",
		"up" : __DIR__"h_kezhan2",
		"east" : __DIR__"h_nslu",
		"west" : __DIR__"h_nslu3",
	]));

	set("objects",([
	__DIR__"npc/xiaoer2.c" : 1,
	]));

	setup();
}

int valid_leave(object ob, string dir)
{
        if ( !ob->query_temp("rent_paid") && dir == "up"  )
	return notify_fail("店小二一下挡在门前，白眼一翻：怎麽着，想白住啊！\n");
	return ::valid_leave(ob, dir);    
}
       
