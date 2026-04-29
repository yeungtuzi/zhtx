//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 玄铁重剑

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
        set_name(BLK"玄铁重剑"NOR, ({ "xuantie zhongjian", "jian" }) );
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
                set("long",  "这把剑黑黝黝的毫无异状，却是沉重之极，三尺多长的一把剑，重量竟自不下七八十斤\n剑两边剑锋都是钝口，剑尖更圆圆的似是个半球。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIC"$N潜运真气，举重若轻的将$n握手中，挽了个剑花，四周登时风声大作。\n"NOR);
                set("unequip_msg", HIM"$N将$n插回腰间的剑鞘。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("xuantie-sword",1)/6);  
               set("weapon_prop/parry", this_player()->query_skill("xuantie-sword",1)/4);  
       }
    init_sword(350);
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
                        + me->query("str")*me->query_str();

                wdp = (int)weap->weight() / 500
                        + (int)weap->query("rigidity")
                        + (int)victim->query("str")*victim->query_str();

                if(  random(wap) > wdp )
                {
                        weap_name = weap->query("name");
                        weap->unequip();
                        weap->move(environment(victim));
                        weap->set("name", "断掉的" + weap->query("name"));
                        weap->set("value", 0);
                        weap->set("weapon_prop", 0);
                        weap->set("long", weap->query("long")+"可是，现在却已经断为两截，不知道还有什么用处。\n");
                        victim->reset_action();
                        return "只听见「叮」地一声爆响，$n手中的" + weap_name
                                + "已经被玄铁重剑雷霆之势震成两段！\n";
                }
                                
        }
}
int query_undodgeable(object me,object victim)
{
        object weap;
      
        return 100;  //普通技能或兵器10%的可dodge机率
}

int wield()
{
         if( this_player()->query_skill("xuantie-sword",1) < 100)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

