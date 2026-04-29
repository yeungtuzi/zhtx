// Filename : /u/ysgl/obj/clothes/hat.c
// Created by diablo (1997.10.31)
// The latest changed by diablo

#include <armor.h>           
inherit F_AUTOLOAD;            
inherit WAIST;
void create()
{
	set_name("订做的", ({ "order" , "belt" }));
	set("weight", 30);
        set("no_get",1);
        set("no_drop",1);
        set("owner","xkx");
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
//		set("value", 1);
		set("material", "leather");
		set("armor_prop/armor",10);
	}
	setup();
}	

void init()
{                  
 	seteuid(geteuid());                  
}                          

int query_autoload()
{
	if( this_player()->query("id") == "xkx" )
		return 1;
	return 0;
}
