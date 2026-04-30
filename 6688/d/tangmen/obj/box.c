//box.c     
//by tang
#include <ansi.h>

inherit ITEM;

void create()
{
        	// 2026-04-30: unused variable commented out
        	// object obj;
        	set_name("剑匣", ({ "box" }) );
        	set_weight(4000);
    	set_max_encumbrance(5000);    
	set("no_get", 1);
	set("sword", 1);
        	if( clonep() )
                	set_default_object(__FILE__);
        	else {
        		set("unit", "个");
        		set("long", "这是一个铜制的剑匣，可以用来装剑。\n");
                	set("value", 1);
        	}
}

void init()
{                                       
	add_action("do_open","open");	
}                                                     

int do_open(string arg)
{
	object ob,me,fake_sword,*swords,env;    
	int i;
	

	me = this_player();
	
	if ( arg=="box")
	{
		if( !me->query_temp("marks/changsheng-ok") )
		{
			message_vision("\n$N小心翼翼地打开剑匣,突然...\n",me);
			message_vision("一蓬细如牛毛的针雨从匣中射出,\n",me);
			message_vision("尚未等$N反应过来,$N手上已经钉满了绿幽幽的唐门毒针.\n",me);
			me->set_temp("last_damage_from",me);
			me->apply_condition("tm_poison",100);
			me->update_condition();
			me->check_status();               
			return 1;
		}
		if (  me->query_temp("marks/sword") || !this_object()->query("sword") )
		{              
			message_vision("$N打开剑匣，但里面空空的，什么也没有。\n",this_player());
			me->set_temp("marks/sword", 1);
			return 1;
		}

		if( !objectp(fake_sword=present("sword",me)) || fake_sword->query("name") != HIG "长生剑" NOR )
		{
			return notify_fail("你刚要打开盒子,突然意识到:坏了,没有带把看起来一样的剑来掉包.\n");
		}

		message_vision("$N打开剑匣，取出一把剑。然后小心翼翼的把自己带来的剑按原位置放了进去\n", me); 
		destruct(fake_sword);
		
		swords = filter_array(children("/obj/changshengjian"),(: clonep($1) :));
		i = sizeof(swords);
		while( i-- )
		{
			env = environment(swords[i]);			
			if( userp(env) )
				tell_object(env,swords[i]->name()+HIG"发出一阵清亮的啸声,然后在一团绿色的光雾中消失了!\n"NOR);
			destruct(swords[i]);
		}
		ob=new("/obj/changshengjian");
		ob->move(me);                              
		set("sword", 0);
		ob->set("master",me->query("id"));
		ob->save();                                    
		me->set_temp("marks/sword", 1);     
		me->delete_temp("marks/changsheng-ok");
		return 1;
	}
	return 0;
}
