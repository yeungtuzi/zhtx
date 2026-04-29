//OBJ:/d/xueshan/npc/obj/xsword.c
//By masterall for 妖刀狗屠

#include <weapon.h>
#include <ansi.h>

inherit F_AUTOLOAD;
inherit BLADE;
//inherit F_UNIQUE;

int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIG"妖"+HIB"刀"+HIY"狗"+HIR"屠"NOR, ({ "yaodao goutu", "dao" }) );
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
                set("long",   "这是一把深红色的鬼头刀，拿在手中沈甸甸地。\n");
                set("value", 0);
                set("rigidity",420000);
                set("material", "crimsonsteel");
                set("wield_msg",
                        HIR "$N「飕」地一声抽出一把背厚刃薄的$n握在手中。\n" NOR);
                set("unequip_msg",  "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/attack", this_player()->query_skill("spring-blade",1)/7);   
                set("weapon_prop/courage", this_player()->query_skill("celestial",1)/4);       
        }
    init_blade(300);
       setup();
}

int wield()
{
        if( this_player()->query_skill("spring-blade",1) < 250)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
          int skill;
          skill=this_player()->query_skill("spring-blade",1);
               if (damage_bonus < 0 ) return 0;
          if(skill>random(399))
     //   if(random(3)>0)
        victim->receive_wound("kee",damage_bonus/2);
        return this_object()->name()+ HIR "在$n的$l轻轻划过，所到之处嗤嗤之声不绝于耳，$n皮开肉绽，连声惨嚎！\n" NOR;
}




