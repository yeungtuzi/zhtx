//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "溪水");
	set("long", @LONG
	这是南宋民族英雄岳飞的祀庙.坐落在湖畔的栖霞岭下.庙貌庄严巍峨.在庙门前立着几蹲
铁像,正是当年害死岳飞的奸臣戾妇王俊,秦绘夫妇等的塑像,只见铁像上面脏兮兮的,看来是游人们
的杰作了.
LONG
        );
        setup();
}

void init()
{
	add_action("do_swim","swim");
}

int do_swim(string arg)
{
	object ob=this_player();

	if(!arg || arg!="center" )
	{
		tell_object(ob,"你不知道往哪个方向游才好。\n");
		return 1;
	}
	if(!ob->query_temp("is_swimming") || 
ob->query_temp("is_swimming")<5 )
	{
		tell_object(ob,"你继续往水中心的一个岛上游去。\n");
		message_vision("$N往中心的一个小岛游去。\n",ob);	
		ob->add_temp("is_swimming",1);
		return 1;
	}
	tell_object(ob,"你终于游到了小岛上，不禁感到有些累。\n");
	message_vision("$N游到了小岛上。\n",ob);
	ob->delete_temp("is_swimming");
	ob->move("/d/hangzhou/h_river3");
	return 1;	
}

