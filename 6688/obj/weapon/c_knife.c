// /obj/weapon/c_knife.c

#include <weapon.h>

inherit BLADE;

void create()
{
    set_name("菜刀", ({ "kitchen knife", "knife", "cooking knife" }) );
    set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一把磨得锃亮的菜刀,发出可怕的金属光泽.\n");
        set("unit", "把");
                set("material", "steel");
        }
    init_blade(5);
        setup();
}
