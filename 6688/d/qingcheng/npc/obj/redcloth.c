#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(RED"红色劲服"NOR, ({ "rec cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件武者常穿的"+RED"红色劲服"NOR+"。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                        }
        setup();
}
 