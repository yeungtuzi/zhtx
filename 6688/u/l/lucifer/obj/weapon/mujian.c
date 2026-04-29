//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 木剑

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
        set_name(HIW"木剑"NOR, ({ "mu jian", "jian" }) );
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
                set("long",  "这是一柄木剑，拿在手里轻飘飘的浑似无物。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIW"$N身随意转，不知不觉间你手中已然多了一把剑。\n"NOR);
                set("unequip_msg", HIW"$N将$n插回腰间的剑鞘。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("dugu-jiujian",1)/6);  
                set("weapon_prop/defence", this_player()->query_skill("dugu-jiujian",1)/10);  
       }
    init_sword(400);
       setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;
        int lvl,num;
        lvl=this_player()->query_skill("dugu-jiujian",1);
               if (damage_bonus < 0 ) return 0;
        num=lvl/400;
        me->add("force",num*me->query("force_factor"));

        if(victim == me) return;
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = weight() / 500
                        + query("rigidity")
                        + me->query("str")*me->query_str();

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str");


                if(  random(wap) > wdp/2 )
                {
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(me);
                        victim->reset_action();
                        return "$N将木剑搭在"+weap->query("name")+"轻轻一带，$n脸色大变，只感手中的"+weap->query("name")+"一阵剧烈跳动，被$N顺手夺过！\n";           
                }
                if(  random(wap) > wdp/4 )
                {
                        return "$N的木剑搭在"+weap->query("name")+"上，$n只感手中的"+weap->query("name")+"一阵剧烈跳动，几欲把持不住！\n";
                }
                        
        }
}

int query_unparryable(object me,object victim)
{
        object weap;
      
        return 100;  //普通技能或兵器10%的可parry机率
}
int query_undodgeable(object me,object victim)
{
        object weap;
      
        return 100;  //普通技能或兵器10%的可dodge机率
}


int wield()
{
        if( this_player()->query_skill("dugu-jiujian",1) < 350)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}


