#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("藏刀", ({"zang dao", "blade"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "iron");
                set("long", "产自西藏的刀，份量较普通的刀重。\n");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
        }
        init_blade(25);
        setup();
}

