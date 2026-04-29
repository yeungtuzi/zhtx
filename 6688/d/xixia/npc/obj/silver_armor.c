#include <armor.h>
#include <ansi.h>

inherit ARMOR;
inherit F_AUTOLOAD;
int query_autoload()
{
        return query("armor_prop");
}

void create()
{
        set_name(HIW"银丝软甲"NOR,({ "silver armor", "armor" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
		set("long","这是用一根根银丝织成的，既抗击打又柔软。\n");
		set("material", "silver");
                set("value",70000);
                set("armor_prop/armor", 100);
		set("armor_prop/armor_vs_force", 80);
        }
        setup();
}
