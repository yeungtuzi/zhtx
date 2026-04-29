// cloud_armor

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name( "锁子连环甲",({ "army armor" }) );
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
		set("long","这是一套军人的铠甲,重量较轻\n");                
  		set("material", "iron");
                set("value",2000);
                set("armor_prop/armor", 15);
                set("armor_prop/dodge", -10);
        }
        setup();
}


