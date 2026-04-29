//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 玉竹杖

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_STAFF;

void create()
{
        set_name(HIG"玉竹杖"NOR, ({ "yuzhu zhang", "zhang" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long",   "一根泛着淡淡青光的竹杖。它是丐帮帮主的信物。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "bamboo");
                set("wield_msg",
                        HIG "$N抽出一根青光闪闪的竹杖抓在手中。\n"NOR);
                set("unequip_msg", HIG "$N把手中的玉竹杖插回腰中。\n"NOR);
                set("adv_props/attack", 20);   
                set("adv_props/speed", 20);  
                set("adv_props/dodge", 20);         
        }
    init_staff(300);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("dagou-bang",1) < 200)
        {
                return notify_fail("你的打狗棒法等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这根丐帮神兵。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int dodge,def,parry,skill;
        dodge=victim->query_temp("apply/dodg");
        def=victim->query_temp("apply/defense");
        parry=victim->query_temp("apply/parry");
        skill=me->query_skill("dagou-bang",1)/3;
        if (damage_bonus < 0 ) return 0;
        if(random(3)>0)
        if(victim == me) return;

        victim->add_temp("apply/dodge", -dodge/4 - skill);
        victim->add_temp("apply/defense", -def/20 - skill/5);
        victim->add_temp("apply/parry", -parry/4 - skill);
        victim->receive_wound("kee",damage_bonus/10);
     
        if( victim->query_temp("apply/dodge") < 0 ) victim->set_temp("apply/dodge", 0);
        if( victim->query_temp("apply/parry") < 0 ) victim->set_temp("apply/parry", 0);
        if( victim->query_temp("apply/defense") < 0 ) victim->set_temp("apply/defense", 0);

        return this_object()->name()+ HIG "带着疾风扫到$n的$l，$n站立不稳一个跟头摔倒在地！\n"+HIB"$n觉得周身经脉颇为不畅，辗转腾挪已经有些不大灵光！\n" NOR;
}

