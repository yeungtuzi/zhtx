// sengmao.c

#include <ansi.h> 
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIR "僧帽" NOR, ({ "seng mao", "mao", "hat" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                set("long", "这是一顶藏僧戴的僧帽。\n");
                set("value", 100);
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("xueshan",1);
        }
        setup();
}
