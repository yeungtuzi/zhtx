/* shi.c */
inherit ITEM;

void create()
{
	set_name("石锁", ({ "shi suo","suo" }) );
	set_weight(50000);
	set("value",1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("long", "这是一副用来练力气的大石锁。\n");
        }
	setup();
} 