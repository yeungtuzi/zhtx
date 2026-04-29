//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 紫金杖

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_HAMMER;

void create()
{
        set_name(HIR "紫金"+HIY"锤" NOR , ({ "zijin chui", "chui" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long", "一把用紫金精心打造的金锤，紫光中透着寒气，令人不寒而栗\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "violet-gold");
                set("wield_msg", HIM "一道紫光闪过之后，$N手里多了对称心如意的$n" HIM + "。\n天地间刹时黯然失色，$N只觉得全身充满了力量。\n" NOR);
                set("unwield_msg", "$N放下手中的$n。\n");
                set("adv_props/attack", 20);   
                set("adv_props/armor", 200);         
        }
    init_hammer(300);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("wuxinglun",1) < 200)
        {
                 return notify_fail("你的五行轮法等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这根利器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{                                      
        int damage,skill;
        object weapon1, weapon2;
        string name1, name2;


        damage=victim->query_temp("apply/damage");
        skill=me->query_skill("wuxinglun",1)/10;

        weapon1 = me->query_temp("weapon");
        name1 = weapon1->query("name");

        if (damage_bonus < 0 ) return 0;

        if(random(3)>0)

        victim->add_temp("apply/damage", -damage/20 - skill);
        victim->receive_wound("kee",damage_bonus/15);
     
        if( victim->query_temp("apply/damage") < 0 ) victim->set_temp("apply/damage", 0);

        if( objectp(weapon2 = victim->query_temp("weapon")) )
        {
          name2 = weapon2->query("name");
          return name()+HIY"金光乍现，一阵“叮叮当当”的巨响过后，$n发现自己的" + name2 + HIY"上已经多了好几个豁口！\n"NOR;

        }
        else
        {    
          name2 = "手臂";
          return name()+HIW"以排山倒海之势撞向$n的手臂，$n急忙招架相应，顿时震得膀臂发麻！\n"NOR;
        }

}

