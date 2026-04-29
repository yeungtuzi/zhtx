// tea_leaf.c

inherit ITEM;

void create()
{
	set_name( "毒药" , ({ "poison" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一包谁也不知道有什么用的毒药。\n");
		set("unit", "包");
		set("value", 0);
	}
	set("xiaoyao_du",1);
	setup();
}
