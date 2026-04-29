//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 真武剑

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;

void create()
{
        set_name(HIG"真武剑"NOR, ({ "zhenwu jian", "jian" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",   "这是武当镇山之宝，剑身通体碧绿，寒气摄人魂魄。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "steel");
                set("wield_msg",
                        YEL "铮地一声,$N的手中已多了一把斩妖除魔的$n。\n"NOR);
                set("unequip_msg", HIY "$N将手中的$n插入腰间的剑鞘。\n"NOR);
                set("adv_props/attack", 20);   
                set("adv_props/parry", 20);   
                set("adv_props/defense", 5);      
        }
    init_sword(300);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("taiji-jian",1) < 200)
        {
                return notify_fail("你的太极剑等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int tzq,mzq,bili,dam,dam2;
        tzq = victim->query("shen");
        mzq = me->query("shen");
 //       bili = -1*mzq/tzq;
        dam = 500*mzq / 2000000000;
        dam2 = 500*tzq / 2000000000;
        if(dam > 500) dam= 500;
        if(dam < 1) dam = 1;
        if(dam2 > 500) dam2 = 500;
        if(dam2 < 1) dam2 = 1;

        if (damage_bonus < 0 ) return 0;
        if(random(3)>0)
        if(!userp(me))return 0;
        if( tzq == 0) return 0;
        if(victim == me) return;

        if(victim->query("shen") <= 0){
        victim->receive_wound("kee", dam + 1);
        return query("name")+HIY"爆发出绚丽的光芒，世间的种种丑恶，邪魔外道，牛鬼蛇神刹那间被击得烟消云散！\n"NOR;

        }else if (victim->query("shen") > 0 && victim->query("shen") < me->query("shen")){
        victim->receive_wound("kee", random(200)+1);
//        me->receive_wound("kee", random(20)+1);
        return query("name")+HIC"凄鸣一声，飞向天空，似乎不忍再看这一出骨肉相残的人间悲剧！\n"NOR;
        }else{
        me->receive_wound("kee", dam2 + 1);
        return query("name")+HIR"在刺中$n的一刹那突然停滞不前，反而向着$N重重击来！\n"NOR;
        }

}

