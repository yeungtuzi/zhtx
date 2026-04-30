#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_SWORD;

void create()
{
        set_name(HIC "绣花针" NOR,  ({ "xiuhua zhen", "zhen" }) );
        set_weight(1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",  "这是一根女子绣花的针，不知道拿在手里有什么用。\n");
                set("value", 110);
                set("no_get",1);
                set("rigidity",1000000);         
                set("material", "steal");
                set("adv_props/add_max_kee",150);
                set("wield_msg",
                        HIM"$N「唰」的一声抽出一根$n捏在手中。\n"NOR);
                set("unequip_msg", HIM"$N将手中的$n插回绣花绷。\n"NOR);
                set("adv_prop/attack", 40);
                set("adv_prop/dodge", 75);   
       }
    init_sword(550);
       setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();
        if( this_player()->query_skill("pixie-sword",1) < 220)
        {
                return notify_fail("你的辟邪剑法等级太低了，用不了这件兵器。\n");
        }
        
        return ::wield();
}                                                

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // 2026-04-30: unused variable commented out
        // object weap;
        // 2026-04-30: unused variable commented out
        // int    wap,wdp;
        // 2026-04-30: unused variable commented out
        // string weap_name;
        if (damage_bonus < 0 ) return 0;
        if(victim == me) 
        return;
        if (random(1000000)>0)
        victim->receive_wound("gin",300);
        return this_object()->name()+ HIM "轻轻刺中了$n的$l，$n只觉得浑身刺痛，生不如死！\n" NOR;
       }

