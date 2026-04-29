// /d/xizang/npc/obj/paper.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("碎纸片", ({ "paper piece", "paper", "piece" }));
	set_weight(6);
	if( clonep() )
		set_default_object(__FILE__);
	set("unit", "块");
	set("long", "这是一块碎纸片,上面有几个似乎用血写成的模糊的藏文字.\n");
	set("value", 0);
}

void init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	object me;
	if(!arg ||(arg!="paper" && arg!="paper piece" && arg!="piece"))
		return notify_fail("你要读什么?\n");
	me=this_player();
	if(me->query("race")!="藏族人" && !me->query("marks/大雄"))
		return notify_fail("你看不懂藏文.\n");
//这里保留玩家选择藏族的接口

	if(!me->query_skill("literate"))
		return notify_fail("你是文盲.\n");
	write("纸片上写的是: "+HIR+"有难,救我!\n"NOR);
	me->set("marks/格萨尔", "message_read");
	return 1;
}
