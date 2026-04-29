#include <ansi.h>

inherit ITEM;
//inherit F_UNIQUE;

string *worm = ({
	"/d/xingxiu/npc/spider",
	"/d/xingxiu/npc/wugong",
	"/d/xingxiu/npc/wa",
	"/d/xingxiu/npc/xiezi",
});

void create()
{
	set_name("神木王鼎", ({ "shengmu wangding", "ding" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", @LONG
这是一个深黄色的小木鼎，闻起来有一股异香，不知道有什么用(attract)？
LONG);
		set("value", 50);
		set("nopawnable", 1);
		set("material", "wood");
	}
	setup();
}

void init()
{
	add_action("do_attract", "attract");
}

int do_attract(string arg)
{
	object me, ob, *obs;
	int i;

	me = this_player();

	if( me->is_busy() )
		return notify_fail("你现在正忙着了。\n");
	if( environment(me)->query("valid_sleeproom") )
		return notify_fail("在这里捣乱会引起公愤的！\n");
	if( me->query("sen") < 15 )
		return notify_fail("你太累了，先休息一会吧！\n");

	obs = all_inventory(environment(me));

	for(i=0; i<sizeof(obs); i++){
		if( obs[i]->query("poison_available") )
			return notify_fail("你身边不是已经有了一条毒物了吗？\n");
		if( obs[i]->is_character() && obs[i] != me)
			return notify_fail("还是找个没人的地方吧！\n");
	}
			
	if( me->query_temp("is_attracting") )
		return notify_fail("你不是正在用神木王鼎吸引毒物吗？\n");
	
	me->start_busy(1);
	me->receive_damage("sen", 5);

	message_vision("$N将一些香料粉末放在神木王鼎里，顺势点燃香料隐藏在一边，静静地等待着毒虫的到来。\n", me);
	if( random(10) > 8 )
		return notify_fail("结果什么也没发生。\n");
	ob = new(worm[random(sizeof(worm))]);
	message_vision("过了不久，一条" + ob->name() + "闻到香味，爬了过来。\n", me);
	ob->move(environment(me));
	ob->set("poison_available", 30+random(70));
	me->delete_temp("is_attracting");

	return 1;
}
