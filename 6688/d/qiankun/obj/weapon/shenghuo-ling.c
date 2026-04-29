//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 圣火令

#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;


void create()
{
        set_name(BLK"圣火令"NOR, ({ "shenghuo ling", "ling" }) );
        set_weight(1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_paimai",1);
        set("unpawnable",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是一块非金非木的令牌，正反两面写满了奇怪的文字，背景是火焰升腾之形。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        BLK"只听见「飕」地一声，$N的手中已经多了一把黑黝黝的$n。\n"NOR);
                set("unequip_msg", "$N随手将$n插入腰间。\n");
                set("adv_props/parry", 20);   
                set("adv_props/attack", 20);         
        }
    init_sword(320);
       setup();
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;

        if(victim == me) return;
        if(victim->query("id") == "long xiang") return;
        if(victim->query("id") == "buzhi huowu") return;
        if( objectp(weap = victim->query_temp("weapon")) )
        {

                wap = weight() / 500
                        + query("rigidity")
                        + me->query("str");

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str");


                if(  random(wap) > wdp/2 )
                {
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(me);
                        victim->reset_action();
                        return "$N将圣火令搭在"+weap->query("name")+"上，大喝一声，$n脸色大变，只感手中的"+weap->query("name")+"一阵剧烈跳动，被$N夹手夺过！\n";           
                }
                if(  random(wap) > wdp/4 )
                {
                        return "$N的圣火令搭在"+weap->query("name")+"上，$n只感手中的"+weap->query("name")+"一阵剧烈跳动，几欲把持不住！\n";
                }
                        
        }
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("shenghuo-shengong",1) < 200)
        {
                return notify_fail("你的圣火神功等级太低了，用不了这件兵器。\n");
        }
        if( this_player()->query("combat_exp") < 5000000)
        {
                return notify_fail("你江湖经验太低了，不配拥有这柄剑。\n");
        }
        return ::wield();
}

