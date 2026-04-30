#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;


void create()
{
        set_name(HIR"血"+HIB"阴"+HIW"剑"NOR, ({ "xueyin sword", "sword" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "一把殷红的长剑，烁烁的闪着蓝光。\n");
                set("unit", "把");
                set("value", 0);
                set("material", "steal");
                set("adv_props/attack", 50);
                set("adv_props/defense", 20); 
                set("wield_msg", "$N「唰」的一声抖出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
  

        }
        set("poison/type","super_poisons");
        set("poison/amount",9999999);
        init_sword(300);
        setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query("shen") > -10000 )
        {
                return notify_fail("你是个正派人士，怎么能用这样的凶器？\n"); 
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 0 ) return 0;
        if(victim == me) return;
        if(random(3)>0)return 0;
        if(victim->query("shen") < 0)return 0;
        victim->receive_wound("kee",damage_bonus/8,me);
        victim->update_condition("super_poisons");
        return this_object()->name()+ HIB "的剑锋划破了$n的$l，"+HIR"飞溅出的血光"+HIG"刹那间变成了绿色，"+HIB"阴森森的可怖，鬼憧憧般骇人！\n" NOR;
}


void owner_is_killed(object killer)
{
        // 2026-04-30: unused variable commented out
        // object owner;
        if(environment()->query("id")!="yan bei")
        {
                destruct(this_object());
                return;
        }
        ::owner_is_killed(killer);
        return;
}


