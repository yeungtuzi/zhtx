#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name( HIY"黄金铠甲"NOR,({ "golden armor", "armor" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
  		set("material", "iron");
                set("value",10000);
                set("armor_prop/armor", 45);
                set("armor_prop/dodge", -10);
        }
        setup();
}
