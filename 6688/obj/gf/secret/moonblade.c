// houndbane.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name( CYN "小楼一夜听风雨" NOR, ({ "moon blade", "dao", "blade" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把弯弯的刀。弯刀如月，本应如一弯新月；但这把刀，看上去却如满月。\n");
                set("unpawnable",1);
                set("value", 0);
                set("material", "moonsteel");
                set("wield_msg", "如一汪秋水晃动，$N抽出$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
                set("weapon_prop/courage", 50);
                set("weapon_prop/attack", 50);
                set("weapon_prop/defense", 50);
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
                return notify_fail("你的春风快意刀法等级太低了，用不了圆月弯刀。\n");
        }
        return ::wield();
}

