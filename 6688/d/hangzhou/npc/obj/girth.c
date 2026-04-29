//girth.c
//by tlang for girls

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIM"百叶裙"NOR, ({ "leaf girth","girth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "silk");
                set("armor_prop/armor", 5);
        }
	set("value",100);
        setup();
}

