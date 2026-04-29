#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("毒蒺藜", ({ "du jili", "jili" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "唐门特制的剧毒暗器.\n");
                set("unit", "堆");
                set("base_unit", "颗");
                set("base_weight", 1);
                set("base_value", 100);
        }
        set_amount(50);
	set("poison","tm_poison");
        init_throwing(25);
        setup();
}

void init()
{
	add_action("do_throw","throw");
}

int do_throw(string arg)
{                         
	object me,you,obj;
	int i,j,damage1,damage2,level;      
	string skill;            
                              
	if( !arg)	return notify_fail("你要射谁?\n");                                                            

	me=this_player();
	you = present(arg, environment(this_player()));            
	obj=present("glove",me);

	if( !objectp(you) )
		return notify_fail("这里没有这个人。\n");           
	if( !you->is_character() || you->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
                       
	if( me->is_busy() )	return notify_fail("你正在忙别的，腾不出手来发暗器。\n");

	i=me->query("combat_exp");
               j=you->query("combat_exp");
                          
	if( j==0 )	j=1;
	i=100*i/j+200;

	if (me->is_fighting(you) )
	{
		if (query_amount()>0)
		{             
			if( query_amount()==1 )	unequip();
			add_amount(-1);

			me->start_busy(1);                                                

			if ( !me->query_temp("armor/finger") )
				me->apply_condition("tm_poison", random(4) + 1 +me->query_condition("tm_poison"));
			if ( random(i)>=199 )
			{
				damage1=me->query_skill("throwing",1);   
				if( damage1<1 )	damage1=1;
				skill=me->query_skill_mapped("throwing");
				damage2=me->query_skill(skill,1);   			
				if( damage2<1 )	damage2=1;
				damage1=random(damage1)/2+damage2/3;
				you->set("kee", you->query("kee")-damage1);

				level=me->query("dugong",1);
				you->apply_condition("tm_poison", random(level)/10 + 1 +
					you->query_condition("tm_poison"));
				message_vision("$n被$N发出的唐门暗器毒蒺藜射中。\n",me,you);
				return 1;
			}  

			message_vision("$n不慌不忙地躲过$N发出的毒蒺藜。\n",me,you);
			return 1;
		}       
		tell_object(me,"你已经无暗器可发了。\n");
		return 1;
	}
	tell_object(me,"你只能在战斗中发射暗器。\n");
	return 1;
}


