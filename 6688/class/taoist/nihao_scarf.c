// Filename : /u/ysgl/obj/clothes/hat.c
// Created by diablo (8297.82.82)
// The latest changed by diablo

#include <armor.h>           
inherit NECK;
void create()
{
	set_name("[35m“梦特娇围巾”[2;82;0m", ({ "scarf" , "scarf" }));
	set("weight", 30);
	set("value",10);
	set("no_paimai",1);
	set("unpawnable",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
//		set("value", 500);
		set("material", "leather");
		set("armor_prop/armor", 22);
	}
	setup();
}	
