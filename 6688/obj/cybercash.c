// paper_seal.c

inherit COMBINED_ITEM;

void create()
{
        set_name("冥纸", ({"paper cash", "cash", "paper"}));
        set("long",
                "这是人们为不幸死去的亲朋好友上坟或者做法事所用的纸钱，\n"
		"大家相信这钱在阴间可以使用，能够给死去的亡魂花用。\n"
		"纸上印着各种花押和符号，还有大大的一行字：现银壹佰万两正\n");
        set("unit", "叠");
        set("base_unit", "张");
        set("base_weight", 5);
        set("value", 10000);
	set("unpawnable",1);
	set("no_sell",1);
        set_amount(1);
}

int do_burn(string arg)
{
	if(!arg || !id(arg)) return notify_fail("你要烧什么？\n");
        if( environment() != this_player() )
		return 0;
	write("burn....\n");
	return 1;	
}

void init()
{
	set("value",0);
	add_action("do_burn","burn");
}


