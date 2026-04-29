//girth3.c
//by tlang for woman

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(YEL"彩裙"NOR, ({ "color girth","girth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 5);
        }
	set("value",200);
        setup();
}

