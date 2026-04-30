 //OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 紫薇软剑

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;

void create()
{
        set_name(HIM"紫薇软剑"NOR, ({ "ziwei ruanjian", "jian" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是当年名震天下的独孤求败早年剑使用的一把剑，长约四尺，青光闪闪，确是利器。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIC"青光一闪，$n"+HIC"已在$N手中，四周尽是逼人的杀气。\n"NOR);
                set("unequip_msg", HIM"$N将$n插回腰间的剑鞘。\n"NOR);
                set("adv_props/attack", 20);  
                set("adv_props/dodge", 20);  
       }
    init_sword(320);
       setup();
}

int query_unparryable(object me,object victim)
{
        // 2026-04-30: unused variable commented out
        // object weap;
      
        return 100;  //普通技能或兵器10%的可parry机率
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("dugu-jiujian",1) < 220)
        {
                return notify_fail("你的独孤九剑等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int damage;
        damage = me->query_skill("dugu-jiujian", 1);
        if (damage_bonus < 0 ) return 0;
        if(random(3)>1) return 0;
        if(victim == me) return;
        if(me->query_skill_mapped("sword") != "dugu-jiujian") return 0;
        if(me->query_skill("blade",1) < 250) return 0;
        if(me->query_skill("spear",1) < 250) return 0;
        if(me->query_skill("whip",1) < 250) return 0;
        if(me->query_skill("strike",1) < 250) return 0;
        if(me->query_skill("force",1) < 250) return 0;
        if(me->query_skill("throwing",1) < 250) return 0;
        if(me->query_skill("sword",1) < 250) return 0;
 
        if(random(7)==0)
        {
        victim->receive_wound("kee",damage);
        return this_object()->name()+ HIR"化作一柄百炼神刀，迎着烈烈风声在$n的$l上划出了一道血线，随即如鲜花盛开般绽放！\n" NOR;
        }
        else if(random(7)==1)
        {
        victim->receive_wound("kee",damage);
        return this_object()->name()+ HIG"化作一柄玄铁神枪，如游龙，似飞凤，顷刻间已是点点血雨，万道玄光！\n" NOR;
        }
        else if(random(7)==2)
        {
        victim->add("force", -damage);
        return this_object()->name()+ HIB"化作一柄九截神鞭，如大江东去，黄河入海之势向$n奔涌袭来！\n" NOR;
        }
        else if(random(7)==3)
        {
        victim->add("force", -damage);
        return this_object()->name()+ HIW"突然消失得无影无踪，$n踌躇之际却不知$N已人身剑合一，正在猛力一掌向自己击来！\n" NOR;
        }
        else if(random(7)==4)
        {
        victim->receive_damage("sen",damage/4);
        return this_object()->name()+ BLK"化作点点乌光，“随风潜入夜，润物细无声”，$n却不知其中的意境已经杀气四起，危机重重！\n" NOR;
        }
        else if(random(7)==5)
        {
        victim->receive_damage("gin",damage/4);
        return this_object()->name()+ HIY"随着$N体内的真气鼓荡起来，$n只觉得自己的百骸诸穴都在$N的控制之下，躲无可躲，避无可避！\n" NOR;
        }
        else 
        {
        victim->add_temp("apply/attack", -damage/20);
        if( victim->query_temp("apply/attack") < 0 ) victim->set_temp("apply/attack", 0);

        return this_object()->name()+ HIC"的绚丽的光芒刹那间消失得无影无踪，$N无招的剑意渐渐将$n的意志蚕食，摧垮……！\n" NOR;
        }
}


