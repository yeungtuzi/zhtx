// cloth.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIG"雨衣"NOR, ({ "rain coat" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",   "一件毫不起眼的雨衣，平时一般都被人丢在家里，但不要赶上阴天下雨的，少了它还真不行。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

