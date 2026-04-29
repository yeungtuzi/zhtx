// pink_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIR"粉红绸衫"NOR, ({ "pink cloth", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这件粉红色的绸衫闻起来还有一股淡淡的清香。\n");
                set("unit", "件");
                set("value", 2000);
                set("material", "cloth");
                set("armor_prop/armor", 3);
                set("armor_prop/personality", 1);
                set("female_only", 1);
         }
         setup();
}
