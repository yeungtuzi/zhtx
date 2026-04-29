
inherit ITEM;

void create()
{
	set_name("石桌", ({ "table" , "石桌" }) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","on");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "小巧的石桌\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


