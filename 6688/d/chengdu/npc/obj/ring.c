#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name( HIW"冰玉戒指"NOR , ({ "ice ring", "ring" }) );
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 3000);
                set("material", "gold");
                set("armor_prop/dodge", 5);
                set("armor_prop/armor", 10);
                set("armor_prop/spells", 2);
        set("wear_msg", "$N将$n拿出戴在右手无名指上。\n");
        }
        setup();
}
