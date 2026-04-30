// xiaoyaoring 
//by masterall

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_FINGER;



void create()
{
        set_name(HIM"七"+HIY"彩"+HIC"宝石"+HIR"戒指"NOR, ({ "xiaoyao ring", "ring" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long",   "这是逍遥派掌门信物，执戒指者即为逍遥派本代掌门。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "diamond");
                set("wield_msg",
                        "$N将$n拿出戴在右手无名指上，一道七色的光气从$n上升起，反过来又注入$N顶门。\n"NOR);
                set("adv_props/parry",20);
                set("adv_props/attack", 20);
        }
        init_finger(300);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("liumai-shenjian",1) < 200)
        {
                return notify_fail("你的六脉神剑等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这枚戒指。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // 2026-04-30: unused variable commented out
        // object weap;
        int    wap,wdp,skills;
        // 2026-04-30: unused variable commented out
        // string weap_name;
        int skill;
        skill=this_player()->query_skill("liumai-shenjian",1);
        skills=-4*this_player()->query_skill("liumai-shenjian",1)/3;
        if (damage_bonus < 0 ) return 0;
        if(me->query("force") > me->query("max_force")*2) return 0;
        if( victim->query("force") < 1 ) return 0;
        if(victim == me) return;
        if(random(3) > 0)
        victim->add("force", skills);
        me->add("force", -skills);
        if( me->query("force")> 2*me->query("max_force") )
        {
        me->set("force",2*me->query("max_force"));
        return;
        }
        return query("name")+HIR"轻微的接触到"+HIY"$n的$l，"+HIG"立即爆发出"+HIC"一道七彩的光芒！\n"+HIB"$n只觉得"+HIM"自己的内力犹如"+HIW"泥牛入海，去不复返！\n"NOR;
}

