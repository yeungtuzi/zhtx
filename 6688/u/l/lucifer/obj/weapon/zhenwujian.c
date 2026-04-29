//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 真武剑

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit SWORD;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIG"真武剑"NOR, ({ "zhenwu jian", "jian" }) );
        set_weight(1);
        set("owner","no_owner");
        set("marks/寒于",1);
        set("no_drop",1);
        set("no_get",1);
        set("unpawnable",1);
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
                set("weapon_prop/attack", this_player()->query_skill("taiji-jian",1)/7);   
                set("weapon_prop/parry", this_player()->query_skill("taiji-quan",1)/4);   
                set("weapon_prop/defense", this_player()->query_skill("taiji-shengong",1)/15);      
        }
    init_sword(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("taiji-jian",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl,num;
        lvl=this_player()->query_skill("taiji-jian",1);
        num=lvl/400;
               if (damage_bonus < 0 ) return 0;
        me->add("force",num*me->query("force_factor"));
}

void init()
{
        add_action("do_jiedu","jiedu");     
}

int do_jiedu(string arg)
{
        string *conditions=({}),*list;
        int i;
        int has_poison;
        object me,target;

        me=this_player();
        target = present(arg, environment(this_player()));            


        if( !arg)       return notify_fail("你要给谁解毒?\n");                                                 
  //      if( me->is_fighting() )
  //              return notify_fail("战斗中运功解毒？找死吗？\n");

        if( (int)me->query("force") < 50 ) 
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

        if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
                return notify_fail( target->name() +
                        "已经受伤过重，经受不起你的真气震荡！\n");
        
        if( target != me )
                message_vision(
                        HIG "$N将真武剑搭在$n的疮口上，发动体内的真气吸取$n身上的毒素....\n"NOR,me, target );
        else
                message_vision(
                        HIG "$N将真武剑搭在自己的疮口上，发动体内的真气吸取身上的毒素...\n"NOR,me);

        list = get_dir("/daemon/condition/");
        
        i = sizeof(list);
        while( i-- )
        {
                arg = list[i];
                if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                        conditions += ({arg[0..strlen(arg)-3]});
        }
        
        i = sizeof(conditions);
        has_poison=0;
        while(i--) 
        {
                if( target == me )
                {
                        if( (int)me->query("force") < 50 ) 
                                return notify_fail("你的真气不够。\n");
                        if( me->query_condition(conditions[i]) > 0 )
                        {
                                me->apply_condition(conditions[i],0);
                                message_vision(HIG"过了不久，$N额头上冒出豆大的汗珠，从手指尖滴出一缕黑血，黑血渐渐由黑转红...\n"NOR,me);

                                if( wizardp(me) )
                                        message_vision("$N的"+conditions[i]+"被解啦。\n",me);
                                me->add("force",-50);
                                has_poison = 1;
                        }
                }
                else
                {
                        if( (int)me->query("force") < 50 ) 
                                return notify_fail("你的真气不够。\n");

                        if( target->query_condition(conditions[i]) > 0 )
                        {
                                target->clear_condition();
                                message_vision(HIG"真武剑不断的由绿转黑，再由黑转绿，"+HIC"\n$n的疮口冒出“嗤嗤”的白烟，不多一会，$n的脸上恢复了红润...\n"NOR,me,target);
                                if( wizardp(me) )
                                        message_vision("$n的"+conditions[i]+"被$N解啦。\n",me,target);
                                me->add("force",-50);
                                has_poison = 1;
                        }
                }       
        }
        
        if(!has_poison) return notify_fail("毒素已吸净！\n");

        write("Ok。\n");
        return 1;

}

