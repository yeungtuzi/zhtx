//xifu.c
//by tlang for foreiger

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIW"西服"NOR, ({ "xi fu","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 5);
        }
	set("value",1000);
        setup();
}

