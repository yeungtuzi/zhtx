// sword.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(MAG"夜梅枝"NOR, ({ "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 500);
                set("material", "tree");
                set("long",
                        "一枝小小的梅枝，但在高手手中则是杀人的利器。\n"
                     );
                set("wield_msg", "$N随手抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插在腰间的束带间。\n");

        }
	init_sword(45);
        setup();
}
