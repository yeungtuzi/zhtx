// sha.c
//by dwolf

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(MAG"纱"NOR, ({ "sha", "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 2); 
		set("value", 1000);
        }
        setup();
}

