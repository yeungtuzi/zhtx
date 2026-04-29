// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name( YEL "出跸刀" NOR, ({ "chubi dao", "dao", "blade" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long",YEL@LONG
这是一柄黄杨木雕的弯刀，无鞘，刀身长三尺半，上面雕有美人出跸图，
图上人物凡143，马匹109，车辆16，云麾、车盖、仪仗等均历历可数，
据说这些东西如果放为原大，那就要前后排上十来里长，如果化成图画，
裱上手卷，也得绵延十数丈。画与雕刻都出自名家，形态逼真，神情生动。
LONG NOR
         );
                set("unpawnable",1);
                set("value", 0);
                set("material", "wood");
                set("wield_msg", "$N从腰间解下$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n挂回腰间。\n");
                set("weapon_prop/attack", 50);
                set("weapon_prop/defense", 10);
        }

        init_blade(200);
        setup();
}

int wield()
{
        object me,ob;
        me = this_player();
        ob = this_object();
        if( this_player()->query_skill("spring-blade",1) < 400)
        {
                return notify_fail("你的春风快意刀法等级太低了，用不了出跸刀。\n");
        }
        return ::wield();
}

