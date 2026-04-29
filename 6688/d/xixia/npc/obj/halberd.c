// blade.c

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("长戟", ({ "halberd" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 700);
                set("material", "iron");
                set("long", "斤重。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_halberd(30);
        setup();
}
