#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
    set_name(RED"屠龙刀"NOR, ({ "tulong dao", "blade","dao" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 50000);
        	set("material", "iron");
                set("rigidity",500000);
        	set("long", "这是天下第一利器，有“倚天不出，谁与争锋”之说。\n");
        	set("wield_msg",RED"只听见噌地一声，$N手中已多一一把寒光闪闪的宝刀，刹时间,天地变色,\n草木动容,四周笼罩着一股无边的杀气。\n"NOR);
	}
    	init_blade(250);
	setup();
}

int post_parry_attack(object me, object victim)
{
	object weap;
	int    wap,wdp;
	string weap_name;

	if(victim == me) return 0;
	if( objectp(weap = victim->query_temp("weapon")) )
	{

		wap = weight() / 500
			+ query("rigidity")
			+ me->query("str")*me->query_str();

		wdp = (int)weap->weight() / 500
			+ (int)weap->query("rigidity")
			+ (int)victim->query("str")*me->query_str();

                if(  random(wap) > wdp )
		{
			weap_name = weap->query("name");
			weap->unequip();
			weap->move(environment(victim));
			weap->set("name", "断掉的" + weap->query("name"));
                      	weap->set("value", 0);
			weap->set("weapon_prop", 0);
        		weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有什么用处。\n");
			victim->reset_action();
			message_vision(HIW"只听见「擦」地一声轻响，$N手中的" + weap_name + "已经被锋锐无伦的屠龙刀削成两段！\n"NOR, victim);
			return 1;
		}
				
	}

	return 1;
}
