#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(MAG"灭世魔刀"NOR, ({ "xiuluo dao"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                // set("unpawnable",1);
                set("value", 80000);
                set("material", "刚玉");
		set("rigidity",1000000);
                set("long",
                        "这把刀刀身宽而方，除刀柄之外全都开了锋，\n"
                        "发出蓝印印的光芒。\n");
                set("wield_msg", RED"$N抽出一柄$n握在手中，顿时天地之间鬼哭神嚎！\n"NOR);
                set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/attack", 10);
                set("weapon_prop/intelligence", 10);
                set("replica_ob", "/d/heimuya/obj/blade");
        }
        init_blade(150,EDGED | SECONDARY);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-dao-jue",1) < 120)
	{
		return notify_fail("你使不动这件兵器。\n");
	}
	return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
//	if(random(3)==0)
        victim->receive_wound("kee",damage_bonus/2);
        return this_object()->name()+ HIR "在$n的$l轻轻划过，所到之处嗤嗤之声不绝于耳，$n皮开肉绽，连声惨嚎！\n" NOR;
}
