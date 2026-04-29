// /d/xizang/class/budala/obj/junk.c

inherit ITEM;

void create()
{
        set_name("材料", ({ "material", "cailiao", "junk"}));
	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
	else {
                set("unit", "些");
                set("long", "一些工匠们使用的原材料。\n");
                set("value", 0);
                set("material", "unknown");
		set("no_get","这些东西你拿走没什么用\n");
	}
}
