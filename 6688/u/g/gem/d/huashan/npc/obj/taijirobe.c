// taijirobe.c 太极道袍
// 

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("太极道袍", ({"taiji daopao", "cloth", "pao"}) );
    set_weight(3000);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
	set("long", "一件太极道袍。\n");
        set("material", "cloth");
        set("armor_prop/armor", 10);
    }
    setup();
}
