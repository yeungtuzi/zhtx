#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name("磁铁棋盘", ({ "qi pang" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个下围棋用的棋盘，用有磁性的钢铁做成，外面漆以木纹，再在其上刻以纵横十九道痕。\n");
                set("value", 700);
                set("material", "iron");
                set("wield_msg", "$N将$n掂了掂重量，然後抓在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(80);
        setup();
}

int post_parry_attack(object me, object victim)
{
	object victim_weapon;
	string material_type;
	int weight1, weight2;

	victim_weapon = victim->query_temp("weapon");
	if( !victim_weapon )	return; 
	material_type = victim_weapon->query("material");
	weight1 = weight(); weight2 = victim_weapon->weight();
	
	if( material_type == "iron" || material_type == "steel" ){
		if( weight1 < weight2 / 2 ) {
			message_vision(HIW"$N的" + victim_weapon->query("name")+HIW"被$n的"+query("name")+HIW"一带，运用不自如！\n"NOR, victim, me);
			victim->set_temp("fighting/parry", -20);
		}
		else{
			message_vision(HIW"$N的"+victim_weapon->query("name") + HIW"被$n的" + query("name") + HIW"牢牢吸住了！\n"NOR, victim, me);
			victim->start_busy(1);
		}
	}
	return ;
}
