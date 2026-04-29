//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 铁罗汉

#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_HANDS;


void create()
{
        set_name(HIW"铁罗汉"NOR, ({ "tie luohan", "quan" }) );
        set_weight(1);
        set("unpawnable",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "对");
                set("long",   "这是当年峨嵋派开山祖师郭襄十六岁生日那天少林无色禅师请人带去的生日礼物。\n这是一对精铁铸成的罗汉。这对铁罗汉肚腹之中装有机括，\n扭紧弹簧之后，能对拆一套少林罗汉拳。\n后来郭襄转送武当派开山祖师张三丰，\n张三丰在武当形势危及的时候委托门下弟子俞岱岩保留，流传至今。\n想不到一件不起眼的东西竟然有这样大的来头!\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "iron");
                set("wear_msg",
                        HIW "$N双手一分，将$n"+HIW"握在手中，鼓足内力，“铛”的一碰，刹那间虎啸龙吟，不绝于耳。\n"NOR);
                set("unequip_msg", HIW "寒芒一闪，$N将$n"+HIW"收回腰间。\n"NOR);
                set("adv_props/attack", 20);   
                set("adv_props/parry", 20); 
                set("adv_props/damage", 300);  
        }
       call_out("check",5);
       setup();
}

int wear()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("cuff",1) < 220
          ||this_player()->query_skill("strike",1) <220)
        {
                return notify_fail("你的拳法和掌法太低了，用不了铁罗汉。\n");
        }
        if( this_player()->query_temp("weapon") )
                return notify_fail("你只能在空手时使用铁罗汉！\n");
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这件神器。\n");
        }
        return ::wear();
}

void check()
{
        object me;
        string name;
        string *conditions=({}),*list,arg;
        int i,flag,tm;
        string eqflag;

        remove_call_out("check");
        call_out("check",5);

        name = query("name");
        me=environment();
        tm = me->query_condition("tm_poison");
        if(!me) return ;
        if( me->is_character() &&  ( eqflag=query("equipped")) && ( eqflag =="worn")  )
        {

                list = get_dir("/daemon/condition/");
        
                i = sizeof(list);
                conditions = ({});
                flag = 0;
                while( i-- )
                {
                        arg = list[i];
                        if( arg[strlen(arg)-8..strlen(arg)-3] == "poison" )
                                conditions += ({arg[0..strlen(arg)-3]});
                        conditions += ({"iceshock"});
                        conditions += ({"threesmile"});
                        conditions += ({"zhang_qi"});
                }
        
                i = sizeof(conditions);

                while(i--) 
                {
                        if( me->query_condition(conditions[i]) > 0 )
                        {
                        me->apply_condition(conditions[i],0);
                        me->apply_condition("tm_poison", tm);
                        me->add("force", -500); 
                        message_vision(name+HIW"上面突然闪过一阵异芒，"+BLK"从$N手臂上出吸出一道黑气。\n"NOR,me);
                                flag = 1;
                        }
                }                   

        }
}




