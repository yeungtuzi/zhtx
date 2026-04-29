//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 绣花针

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
        set_name(HIM "绣花针" NOR,  ({ "xiuhua zhen", "zhen" }) );
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
                set("long",  "这是一根女子绣花的针，不知道拿在手里有什么用。\n");
                set("value", 0);
                set("rigidity",1000000);
                set("material", "crimson gold");
                set("wield_msg",
                        HIM"$N「唰」的一声抽出一根$n捏在手中。\n"NOR);
                set("unequip_msg", HIM"$N将手中的$n插回绣花绷。\n"NOR);
                set("weapon_prop/attack", this_player()->query_skill("pixie-sword",1)/7);
                set("weapon_prop/dodge", this_player()->query_skill("kuihua-shengong",1)/4);   
       }
    init_sword(350);
       setup();
}

int wield()
{
        if( this_player()->query_skill("pixie-sword",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weap;
        int    wap,wdp;
        string weap_name;
        int skill;
        skill=this_player()->query_skill("pixie-sword",1);
               if (damage_bonus < 0 ) return 0;
        if(victim == me) return;
  //      if(random(3)==0)
        if(skill>random(399))
        victim->receive_wound("gin",damage_bonus/2,me);
        return this_object()->name()+ HIM "轻轻刺中了$n的$l，$n只觉得浑身刺痛，生不如死！\n" NOR;
}


