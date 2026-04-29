#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(GRN"鳄鱼甲"NOR,({ "crocodile armor", "armor" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
		set("long","这是用鳄鱼皮做的，相当不错。\n");
		set("material", "crocodile");
                set("value",40000);
                set("armor_prop/armor", 50);
		set("armor_prop/armor_vs_force", 60);
        }
        setup();
}
