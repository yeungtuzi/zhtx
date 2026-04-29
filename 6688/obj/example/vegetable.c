// /obj/example/vegetable.c

inherit ITEM;

void create()
{
	set_name("青菜", ({ "vegetable", "qingcai", "cai" }) );
	set_weight(350);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "普普通通的青菜有什么好看的?\n");
		set("unit", "捆");
		set("value", 150);
	}
	setup();
}

void init()
{
        if( this_player()==environment() )
                add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        return notify_fail("这是生的青菜,最好还是找个人炒(cook)熟了再吃.\n");
}

