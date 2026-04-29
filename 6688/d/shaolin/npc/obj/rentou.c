#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("成昆的人头", ({ "ren tou","tou" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "这是成昆的人头。\n");
                set("value", 0);
                set("unit","颗");
        }
	set("for_xiexun",1);
        init_hammer(49);
        setup();
}