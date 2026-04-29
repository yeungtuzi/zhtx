//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 玄铁重剑

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;


void create()
{
        set_name(BLK"玄铁重剑"NOR, ({ "xuantie zhongjian", "jian" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这把剑黑黝黝的毫无异状，却是沉重之极，三尺多长的一把剑，重量竟自不下七八十斤\n剑两边剑锋都是钝口，剑尖更圆圆的似是个半球。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIC"$N潜运真气，举重若轻的将$n"+HIC"握手中，挽了个剑花，四周登时风声大作。\n"NOR);
                set("unequip_msg", HIM"$N将$n插回腰间的剑鞘。\n"NOR);
                set("adv_props/attack", 20);  
                set("adv_props/parry", 20);  
       }
    init_sword(350);
       setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int level;
        object weapon1, weapon2;
        string name1, name2;

        level = me->query_skill("xuantie-sword", 1);

        if (level < 220 )       return 0;

        if( me->query_skill_mapped("parry") != "xuantie-sword" )  return 0;
        if( victim->query("id") == "long xiang" )  return 0;
        if( victim->query("id") == "buzhi huowu" )  return 0;

        if( !me->query_temp("weapon") )  return 0;
        if( random(3) > 1 )  return 0;
  //      if( !victim->query_temp("weapon") )  return 0;

        weapon1 = me->query_temp("weapon");
        name1 = weapon1->query("name");


        if( objectp(weapon2 = victim->query_temp("weapon")) )
                name2 = weapon2->query("name");
        else    name2 = "手臂";

/*
        if( victim->query("force") < victim->query("force_factor")
          || victim->query("force_factor") == 0)
                return 0;
*/
        if( me->query("force") < 500)
                return 0;

                if( random(victim->query("force")/2 + me->query("force")) > victim->query("force")/2){
                victim->add("force", -6*me->query("force_factor"));
//                victim->start_busy(1);
           return name()+HIW"“叮”的一声撞上了$n的" + name2 + HIY"，四溅的火星迸得缤纷乱飞！\n"+HIY"$n感到$N的内力如海潮般从四面八方齐至，此声势比之雷震电轰更是厉害！\n$n已经渐渐感到真气略有不纯，攻守交变之间也颇有滞涩。\n"NOR;

                }else{
                victim->add("force", -1*victim->query("force_factor"));
                me->add("force", -1*me->query("force_factor"));
          return name()+HIW"“叮”的一声撞上了$n的" + name2 + HIY"，四溅的火星迸得缤纷乱飞！\n"+HIG"$n迎波击刺！" + name2 + HIG"上所发劲风和$N斗了个旗鼓相当！！\n"NOR;
                victim->add("force", -2*victim->query("force_factor"));
                me->add("force", -2*me->query("force_factor"));
                }

        return 1;

}
int query_undodgeable(object me,object victim)
{
        object weap;
      
        return 100;  //普通技能或兵器10%的可dodge机率
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("xuantie-sword",1) < 219)
        {
                return notify_fail("你的玄铁剑法等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

