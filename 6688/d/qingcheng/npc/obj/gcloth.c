#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(CYN"青色道袍"NOR, ({ "green cloth", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件天青色的普普通通的道袍。\n");
                set("unit", "件");
                set("value", 600);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                       }
        setup();
}
 