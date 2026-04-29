// boot.c

#include <armor.h>

inherit EQUIP;

void create()
{
        set_name("鲜红金乌冠", ({ "crimson hat","hat" }) );
        set_weight(400);
        if( clonep() )
               set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "顶");
                set("armor_type", "head");
                set("value", 100);
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", -2 );
        }
        setup();
}
                       