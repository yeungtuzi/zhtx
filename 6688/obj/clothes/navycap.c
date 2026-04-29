// /obj/navycap.c

#include <armor.h>

inherit HEAD;

void create()
{
        set_name( "水兵帽", ({ "navycap", "cap" }) );
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", "大清帝国北洋水师\n");
                set("material", "cloth");
        }
        setup();
}
