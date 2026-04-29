// /obj/toy/guancai.c

inherit ITEM;

void create()
{
	set_name("棺材", ({ "guancai", "guan", "box" }));
	set_weight(22000);
	set_max_encumbrance(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "口");
		set("long", "一见升官...一见发财...只是到时你已用不着啦!\n");
		set("value", 800);
	}
}

int is_container() { return 1; }
