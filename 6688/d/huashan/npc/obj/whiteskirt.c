#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name( HIW "白色长裙" NOR, ({ "white dress", "dress" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 4000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/dodge", 10);
        }
}
