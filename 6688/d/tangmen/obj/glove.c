// glove.c
//written by tang
      
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("鹿皮手套", ({ "glove" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("long", "这是唐门弟子发射毒蒺藜时必须戴的鹿皮手套。\n");
		set("no_sell", 1);                                                            
		set("armor_prop/armor", 5);
		set("armor_type","finger");
		}
}
      
int query_autoload()
{
    	if ( (string)this_player()->query("family/family_name")=="唐门" )	return 1;
	return 0;
}
