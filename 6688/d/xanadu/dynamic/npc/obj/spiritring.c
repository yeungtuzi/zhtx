#include <ansi.h>
#include "/ldg/std/adv_armor.h"

inherit ADV_FINGER;

void create()
{
    set_name( HIG"精灵魔戒"NOR, ({"magic ring of spirit","ring"}) );
    set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("value", 500);
                set("material", "diamond");
                set("rigidity", 170);
                set("adv_props/armor_vs_force",100);
                set("adv_props/armor",100);
                set("adv_props/add_max_sen",100);
                set("adv_props/add_max_gin",100);
                set("adv_props/spirituality",20);
                set("wear_msg", "$N将$n戴在右手中指上，立即感受到一种奇异的力量！\n");
        }
    setup();
}

void owner_is_killed(object killer)
{
        object owner;
        if(environment()->query("id")!="feng chuiyu")
        {
                destruct(this_object());
                return;
        }
        ::owner_is_killed(killer);
        return;
}

int wear()
{
        if( this_player()->query_skill("spells",1) < 180 )
                return notify_fail("你的咒术不够，无法驾御精灵魔戒强大的能量。\n");
        if( this_player()->query_skill("magic",1) < 180 )
                return notify_fail("你的法术不够，无法驾御精灵魔戒强大的能量。\n");
        return ::wear();
}

