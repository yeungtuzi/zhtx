// pitiao.c
#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(WHT"批条"NOR, ({ "pitiao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("materials","cloth");
		set("long", "奉命取某某若干，见字放行！\n"+RED"              御膳监"NOR);
		
	}
}

