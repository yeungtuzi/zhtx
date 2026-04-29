#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
        set_name(HIM"纤缕娑纱"NOR, ({ "suo sha","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",HIW"这是一件用名贵丝料编织而成的罗衫，\n"
        "就算是再丑的女人，穿上它之后也会显得仪态万方。\n"NOR);
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 20);
                set("armor_prop/courage", 5);
                set("armor_prop/intelligence", 10);
                set("armor_prop/personality", 150);

                set("value",50000);
        }
        setup();
}

