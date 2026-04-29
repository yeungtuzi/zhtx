//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 圣火令

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
        set_name(BLK"圣火令"NOR, ({ "shenghuo ling", "ling" }) );
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
                set("long",  "这是一块非金非木的令牌，正反两面写满了奇怪的文字，背景是火焰升腾之形。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        BLK"只听见「飕」地一声，$N的手中已经多了一把黑黝黝的$n。\n"NOR);
                set("unequip_msg", "$N随手将$n插入腰间。\n");
                set("weapon_prop/parry", this_player()->query_skill("qiankun-danuoyi",1)/4);   
                set("weapon_prop/speed", this_player()->query_skill("shenghuo-shengong",1)/4);
                set("weapon_prop/attack", this_player()->query_skill("shenghuo-shengong",1)/7);         
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
        if( this_player()->query_skill("shenghuo-shengong",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}



