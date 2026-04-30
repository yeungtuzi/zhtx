#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name(HIC "绣花针" NOR, ({"xiuhua zhen", "needle" }) );
     if ( clonep() )
              set_default_object(__FILE__);
     else {
             set("long", "一种上等铁做成的绣花针\n");
          set("unit", "根");
          set("weight", 30);
	  set("value", 100);
          set("material", "steel");
          set("wield_msg", "$N「唰」的一声抽出一根$n握在手中。\n");
          set("unwield_msg", "$N将手中的$n插回绣花绷。\n");
          set("material", "iron");
     }
     init_sword(200);
     setup();
}
/*
int wield()
{
        if( this_player()->query_skill("pixie-sword",1) < 200)
        {
                return notify_fail("你使不动这件兵器。\n");
        }
        return ::wield();
}
*/

mixed hit_ob(object me, object victim, int damage_bonus)
{
        // 2026-04-30: unused variable commented out
        // object weap;
        // 2026-04-30: unused variable commented out
        // int    wap,wdp;
        // 2026-04-30: unused variable commented out
        // string weap_name;
        if (damage_bonus < 0 ) return 0;
        if( me->query_skill("pixie-sword",1) < 200) return 0;
        if(victim == me) return;     
        if(random(3)>0)
//        victim->receive_wound("gin",damage_bonus/20,me);
        return this_object()->name()+ HIM "轻轻刺中了$n的$l，$n只觉得浑身刺痛，生不如死！\n" NOR;
}

