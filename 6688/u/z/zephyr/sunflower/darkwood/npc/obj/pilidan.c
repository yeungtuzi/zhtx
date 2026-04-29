// /pilidan
// borrowed from xat and revised
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_throw", "throw");
}

void create()
{
	set_name("霹雳弹", ({"pili dan","pili", "dan"}));
	set("long","此物小可藏于一手，小巧玲珑，难以想象这居然是江南霹雳堂震堂至宝。\n");
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "枚");
		set("menpai","pilitang");
		set("value", 500);
		set("unpawnable",1);
	}
	setup();
}

int do_throw(string arg)
{       
	object me,ob, *enemys;

	int i,nowkee,nowsen,nowgin,noweff_kee,noweff_sen,noweff_gin;
	mapping skill_status;
	string* sname;

	me=this_player();

	if(!me->is_fighting())
		return notify_fail("好好的干吗要用这么危险的火器？\n");
	if (arg=="pili dan")
		{	
			me->clean_up_enemy();
			enemys = me->query_enemy();
			i = sizeof(enemys);
			ob = enemys[random(i)];	
		}	
	else if(!(ob=present(arg,environment(me))))
			return notify_fail("这里没有这个人。\n");

	noweff_kee=ob->query("eff_kee");
	noweff_sen=ob->query("eff_sen");
	noweff_gin=ob->query("eff_gin");
	nowkee=ob->query("kee");
	nowsen=ob->query("sen");
	nowgin=ob->query("gin");

	if(userp(me))
		{
			if(userp(ob))	return notify_fail("这样可不好，没准会遭报应的。\n");
			else 
			{
				if ( random(100) > 90)
					{
						message_vision(RED"\n$N扔出霹雳弹，正好落在"+ob->query("name")+"怀中。只听" + "一声巨响，将他炸的鲜血淋漓！\n\n"NOR,me);
						ob->set("eff_kee",noweff_kee/2);
						ob->set("kee",nowkee/2);
						ob->set("eff_gin",noweff_gin/2);
						ob->set("gin",nowgin/2);
						ob->set("eff_sen",noweff_sen/2);
						ob->set("sen",nowsen/2);
					}
				else message_vision("\n$N扔出霹雳弹，赶紧伏下身。谁知过了半天什么动静也没有。\n\n",me);
			}
		}
	else
	{
		switch(random(2))
		{
		case 0:message_vision("\n$N扔出霹雳弹，赶紧伏下身。谁知过了半天什么动静也没有。\n\n",me);
		   break;
		case 1:message_vision(RED"\n$N扔出霹雳弹，正好落在"+ob->query("name")+"怀中。只听"+
			   "一声巨响，将他炸的鲜血淋漓！\n\n"NOR,me);
						ob->set("eff_kee",noweff_kee*19/20);
						ob->set("kee",nowkee*19/20);
						ob->set("eff_gin",noweff_gin*19/20);
						ob->set("gin",nowgin*19/20);
						ob->set("eff_sen",noweff_sen*19/20);
						ob->set("sen",nowsen*19/20);
		   break;
		}
	}
	destruct(this_object());
	return 1;
}
