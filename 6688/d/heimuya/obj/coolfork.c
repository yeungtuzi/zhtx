#include <ansi.h>
#include <weapon.h>

inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name(CYN"失魂魔叉"NOR, ({ "shihun cha", "cha", "fork"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                // set("unpawnable",1);

                set("value", 80000);
                set("material", "刚玉");
		set("rigidity",50000);
                set("long",
                        "这把兵器和普通的雷震铛并无太大区别，只是前端开孔，不知有何妙用。\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插入身边的地上。\n");
                set("weapon_prop/attack", 20);
                set("replica_ob", "/d/heimuya/obj/fork");
        }
        init_fork(250);      
        setup();
}

int wield()
{
	if( this_player()->query_skill("mo-cha-jue",1) < 120)
	{
		return notify_fail("你使不动这件兵器。\n");
	}
	return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // 2026-04-30: unused variable commented out
        // object weap;
        // 2026-04-30: unused variable commented out
        // int    wap,wdp;
        // 2026-04-30: unused variable commented out
        // string weap_name;

        if(victim == me) return;
	if(random(3)==0)
	victim->receive_wound("sen",damage_bonus/6,me);
	return query("name")+RED"前端孔洞破空发出呜呜之声，扰得$n心神大乱！\n";
}
