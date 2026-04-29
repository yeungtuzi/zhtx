// /d/weapon/fork.c

#include <weapon.h>

inherit FORK;
void create()
{
        set_name("猎叉", ({ "hunting fork", "fork" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "iron");
                set("long", "这是一柄寻常猎人用的钢叉.\n");
                set("wield_msg", "$N拿起一柄$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n放在一旁。\n");
        }
        init_fork(20);
        setup();
}
