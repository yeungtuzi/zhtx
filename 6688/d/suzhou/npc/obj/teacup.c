//OBJECT: /d/suzhou/npc/obj/teacup.c
//by dwolf for a secret.                  
//97.11.7

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG"翡翠杯"NOR, ({ "feicui bei", "bei" }) );  
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", YEL"一只千年翡翠做成的茶杯，可以装(fill)酒。\n"NOR);
                set("value", 10000);
        }
	set("unpawnable",1);
        setup();
}                                                    

void init()
{                            
	add_action("do_fill", "fill");
	add_action("do_drink","drink");
}

int do_fill(string arg)
{                         
	object obj;
	object ob = this_player();      
        
  	if(!arg || arg!="lihua jiu" )
        { 
       		tell_object(ob, YEL"这么好的酒杯，岂能随便装入凡酒，只有上等的梨花酒才配装进去。\n"NOR); 
			return 1;
	}
	if(!present("lihua jiu",ob) )
	{
		tell_object(ob,HIW"你身上并没有梨花酒，你怎么能装进去呢？\n"NOR);
			return 1;
	}
        if(objectp(obj=(present("lihua jiu",ob)) ) && obj->query("can_apply")<1)
        {
                tell_object(ob,"坛子里的最好的酒都倒光了，已经不配装进翡翠杯了。\n");
                 return 1;
        }
	if(this_object()->query("drinkable")==5 )
	{
		tell_object(ob,"酒杯已经装满了。\n");
			return 1;
	}
	obj->add("can_apply",-1);
        message_vision("$N拿出翡翠杯，往里面小心地注入梨花酒。\n",ob);
	this_object()->set("drinkable",5);
		return 1;
}

int do_drink(string arg)
{
	object ob=this_player();
	object what=this_object();

	if(!arg || arg!=what->query("id") )
		return notify_fail("你要喝什么啊？\n");
	if(!what->query("drinkable") || what->query("drinkable")<1 )  
	{
		message_vision("$N拿出一个空的翡翠杯，想要喝酒，真傻到极点了。\n",ob);
			return 1;
	}
	if( ob->query("water")>=(int)ob->max_water_capacity() )
	{
		tell_object(ob,"你已经喝饱了。\n");
			return 1;
	}
	add("drinkable",-1);
	ob->add("gin",50);
	ob->add("sen",50);
	tell_object(ob,"你喝下一口酒后精神突然大振。\n");
		return 1;
}
                 
