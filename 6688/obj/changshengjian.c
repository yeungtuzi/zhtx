//sword.c 长生剑
//by tang

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_AUTOLOAD;
inherit F_SAVE;

void create()
{
        int res;
        
        if( catch(res = restore()) || !res )
        {

        	set_weight(20000);
		set("no_sell",1);
		set("unpawnable",1);
        	if( clonep() )
                	set_default_object(__FILE__);
        	else {
                	set("unit", "把");
                	set("long",

"这是长生剑客所用过的佩剑，据说剑中藏有一个大秘密。\n"
		);                                   
		set("paper",1);
                	set("value", 0);
                	set("material", "steel");
                	set("rigidity", 1000000);
                	set("wield_msg", YEL "铮地一声,$N的手中已多了一把寒光闪闪的$n。\n" NOR);
                	set("unequip_msg", HIY "$N将手中的$n插入腰间的剑鞘。\n" NOR);
		}

	     	init_sword(250);
		set("master","no body");
		save();
        }
	
        set_name(  GRN "长生剑" NOR, ({ "changsheng sword","sword","changsheng" }) );
	set("unpawnable",1);
	save();
	setup();
	
}

void init()
{
	add_action("do_turn","turn");     
}

string query_save_file()
{
	return "/data/changshengjian";
}

mixed query_autoload()
{
	return ( query("master") == this_player()->query("id") );
}

int do_turn(string arg)
{
	object obj;

	if(!arg || arg != "sword") return 0;

	message_vision("$N试着转动长生剑的剑柄...\n",this_player());
	if( !query("paper") )
		return notify_fail("你转开剑柄，但里面空空如也，什么也没有。\n");

	set("paper",0);
    	obj=new("/d/tieflag/obj/design");
    	obj->move(this_player());

    	tell_object(this_player(),"你发现里面藏着一个纸卷，你把纸卷拿了出来。\n");
    	return 1;
}                                                      

mixed hit_ob(object me, object victim, int damage_bonus)
{                                      
	mapping armors;     
	string *armortype;
	int i;
	object ob;

	if( (random(damage_bonus)+damage_bonus/2) < 200 ) return;
	if( me->query("force") < 200 ) return;                   
//	if( victim->query_temp("apply/armor") < 25 ) return;
	
	armors = victim->query_temp("armor");
	if( !mapp(armors) ) return;
	
	me->add("force",-200);
	if( me->query("force") < 1 ) me->set("force",0);
	
	armortype = keys(armors);
	if( !(i=sizeof(armortype)) ) return;
	
	while(i--)
	{       
		if( !objectp(ob = armors[armortype[i]]) ) continue;
		ob -> unequip();
		ob -> set("name", "破烂的"+ob->query("name"));
		ob -> set("armor_prop",0);
		ob -> set("long", ob->query("long") + ",\n只是可惜现在中间破了个大洞,看来没什么用处了.\n" );
		ob -> set("value",0);
		ob -> move(environment(victim));
	}
	
        victim->receive_wound("kee",damage_bonus/5);
	if( !userp(victim) )
	{
		victim->set_temp("apply/armor", -100);
		victim->set_temp("apply/armor_vs_force",0);
		victim->set_temp("apply/defense",0);
		victim->set_temp("apply/dodge",0);
	}

        return HIG"$N运足内力一逼,"+this_object()->name()+HIG"剑端发出尺许绿幽幽的剑芒,劈开了$n的层层护甲.\n"NOR;

}
