// zishan.c 紫色长衫

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
    set_name(MAG"紫色长衫"NOR, ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地轻软的紫色长衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 5);
    }
    setup();
}
