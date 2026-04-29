
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("锦衣", ({ "jin cloth", "cloth"}));
        set("long", "这是一件锦衣。\n");
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 300);
                set("armor_prop/armor", 20);
        }
        setup();
}


