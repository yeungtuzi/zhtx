/* box.c */
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("被打开的铁箱", ({ "box" }) );
	set_weight(2000);
	set("value",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "铁箱已经被打开了，里边的东西已经被拿走了.\n");
        }
	setup();
} 
