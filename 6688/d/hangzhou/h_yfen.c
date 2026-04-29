//by tlang

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",RED"岳坟"NOR);
	set("long", @LONG
	这是南宋民族英雄岳飞的祀庙.坐落在湖畔的栖霞岭下.庙貌庄严巍
峨.在庙门前立着几蹲铁像,正是当年害死岳飞的奸臣戾妇王俊,秦绘夫妇等的
塑像,只见铁像上面脏兮兮的,看来是游人们的杰作了.
LONG
        );
        set("exits", ([
	"east"  : __DIR__"h_hzxg", 
	"west"  : __DIR__"h_tyl",
	"southdown" : __DIR__"h_qyuan",
	"southeast" : __DIR__"h_bank",
	 ]) );
	
	set("item_desc",([
	"status" : "几蹲脏乎乎的铁像.好像有不少人向上吐了口水.\n",
	"塑像" :   "几蹲脏乎乎的铁像.好像有不少人向上吐了口水.\n",         
	"铁像" :  "几蹲脏乎乎的铁像.好像有不少人向上吐了口水.\n",
	]));

	set("count",5);
	set("trigger",1);	

        setup();
}

void init()
{
	add_action("do_tu","tu");
}

int do_tu(string arg)
{

	object ob=this_player();
	object obj;

	if(!arg )
		return notify_fail("你张口想吐口水,却不小心吐在自己衣服上.\n");
	if(arg=="status" || arg=="塑像" || arg=="铁像")
	{
		if(query("count")<1)
			return notify_fail("塑像已经太脏了,你就别再污染环境了.\n");

		if(ob->is_busy() || ob->query_temp("water/status") )
		{	
		tell_object(ob,"你吐几下就够了,不要污染环境.\n");
			return 1;
		}

		if(ob->query("combat_exp")>=10000 )
		{
			tell_object(ob,"你也不小了,难道不懂的爱护环境卫生吗?\n");
				return 1;
		}
		if(ob->query("bellicosit")>0 || query("trigger")<1 )
		{
			add("count",-1);
			ob->add("bellicosit",-1);
			ob->start_busy(2);	
			ob->set_temp("water/status",1);
			tell_object(ob,"你张口对着塑像恨恨地吐了一口口水.奇怪的是，你心中的恶念在一点点消失。\n");
			message_vision("$N对着塑像恨恨地吐了一口口水.\n",ob);
				return 1;
		}
		add("trigger",-1);
		add("count",-1);
		ob->start_busy(2);
		ob->set_temp("water/status",1);
		obj=new("/d/hangzhou/npc/obj/book1.c");
		obj->move(ob);
		tell_object(ob,"你张口对着塑像恨恨地吐了一口口水,想不到塑像\n
				突然转开，下面露出一个洞来，你下去发现一本书，\n
				就把它拣了起来，然后跳出洞，塑像马上又转了回去。\n");
		message_vision("$N对着塑像恨恨地吐了一口口水,接着发生了一件\n
				不可思议的事。。。。。。可惜你没看清。\n",ob);
			return 1;
	}
	return 0;			
}

