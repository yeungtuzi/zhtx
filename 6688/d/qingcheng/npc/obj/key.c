
/* key.c */

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIM"卧室钥匙"NOR, ({ "key" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这把钥匙已经被用的铮铮发亮了。\n");
        }
	setup();
} 