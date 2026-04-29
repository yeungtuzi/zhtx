/* shi.c */
inherit ITEM;

void create()
{
	set_name("石头", ({ "stone" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块大石头.\n");
        }
	setup();
} 