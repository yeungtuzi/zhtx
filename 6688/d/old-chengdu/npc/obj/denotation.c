#include <ansi.h>
                                                                      
inherit ITEM;

void create()
{
	set_name(HIC"功\德箱"NOR, ({ "denotation box", "box" }) );
	set("unit", "个");
	set("long",
		"这是妙香庵中接受善男信女捐献香油钱的功\德箱，你可以把想捐的钱\n"
		"放进去。\n");
	set("value", 1);
	set("no_get", 1);
	set_max_encumbrance(10000);
}

void insert_object(object ob)
{
	int val;
	object who,ling;
	
	if( !who = this_player() ) return;

	if( !val = ob->value() ) return;

	if( val > 10000 ) {
		tell_object(who,HIY"静清师太愉快地微笑着。\n");
		tell_object(who,"静清师太说：“难得这位" + RANK_D->query_respect(who) + "如此乐善好施，贫尼谨代表我峨嵋派谢谢施主了。\n但得有空，还请赴峨嵋山随喜。\n" NOR);
/*
		tell_object(who,"静清师太交给你一块峨嵋令\n"NOR);
		ling = new(__DIR__"baozi");
		ling->move(who);		
*/
		who->set_temp("invited_by_emei",1);
	}
	seteuid(getuid());
	destruct(ob);
}
