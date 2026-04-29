
#include <ansi.h>
#include "/ldg/std/adv_weapon.h"

inherit ADV_STAFF;

void create()
{
        set_name(HIC"灵"+HIB"蛇"+HIG"杖"NOR, ({"lingshe zhang","zhang" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIB"这是当年“西毒”欧阳峰的随身兵器，杖头有如灵蛇一样，据说毒性甚为强烈。\n"NOR);
                set("value", 10000);
                set("material", "steal");
                set("adv_props/defense",10);
                set("adv_props/attack",10);
                set("wield_msg", "$N「唰」的一声从背后摸出一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回腰间。\n");
        }
        init_staff(150);
        setup();
}

void owner_is_killed(object killer)
{
        object owner;
        if(environment()->query("id")!="ouyang ke")
        {
                destruct(this_object());
                return;
        }
        ::owner_is_killed(killer);
        return;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
               if (damage_bonus < 0 ) return 0;
        if (me->query("name")!="欧阳克") return 0;
          if(random(3)>1)
          victim->apply_condition("super_poisons",5+random(5));
          me->add("shen",-10000);

        return this_object()->name()+ HIB "的蛇头击中了$n的$l，$n只觉得伤口有些麻木，好象被毒蛇咬了一口！\n$N的脸上却透着诡异，嘿嘿的狞笑着。\n" NOR;
}


