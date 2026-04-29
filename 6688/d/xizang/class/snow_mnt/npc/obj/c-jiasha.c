// /d/xizang/class/snow_mnt/obj/c-jiasha.c
// c_jiasha.c 青色袈裟
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name( HIC "青色布喇嘛袍" NOR,({"cyan robe" ,"robe","cloth"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("value",100);
        }
        setup();
}
