// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("千年温玉", ({ "wenyu" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","绿莹莹的触手生温/n");
		set("unit", "块");
		set("value", 14000);
		set("nodrop",1);
	}
	setup();
}

int query_autoload() { return 1; }
