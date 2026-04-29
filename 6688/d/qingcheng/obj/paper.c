/* paper.c
writen by pock 98.04.04 */
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"白纸"NOR, ({ "white paper" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "叠");
		set("long", "一叠新的没有用过的白纸.\n");
        }
	setup();
} 
