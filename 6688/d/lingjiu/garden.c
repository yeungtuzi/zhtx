// Room: /d/lingjiu/garden.c

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
走进后花园，一股花香扑面迎来，沁人心脾。花园里遍植奇花异
草，万紫千红，数不胜数，彩碟乱舞，夺人眩目。花园中央修一
小池，池中筑一假山，涓涓细流，终年不断。花丛中隐约许多倩
影，不时传来一阵嬉笑声，那定是宫中姐妹们在玩耍。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"floor2",
]));
	set("objects", ([
		__DIR__"npc/meijian" : 1,
		__DIR__"npc/dizi" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "lingjiu");

	setup();
}

void init()
{
	add_action("do_move", "move");
}

int do_move(string arg)
{
	object ob, *obs, env, guard;
	int i;

	ob = this_player();
	env = environment(ob);
	if( ob->query("family/family_name") != "灵鹫宫" )
		return notify_fail("你在这里搞破坏啊！太无聊了吧！\n");
	if( interactive(guard = present("mei jian", env)) && living(guard) )
		if( ob->query("faith") < 1200 )	
			return notify_fail("梅剑瞪了你一眼，一幅很生气的样子。\n");
	if( arg != "石头" && arg !="stone" )
		return notify_fail("你在这里搞破坏啊！太无聊了吧！\n");
	message_vision("$N移开假山中的一块石头，露出一个地下入口，$N一弯身钻了进去。\n", ob);
	obs = all_inventory(ob);
	for(i=0; i<sizeof(obs); i++)
		if( obs[i]->is_character() )
			return notify_fail("可惜你身上东西太多了，钻不进去！\n");		
	ob->move(__DIR__"s_entrance");
	return 1;
}
