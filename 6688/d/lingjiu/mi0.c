// Room: /d/lingjiu/mi0.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
沿着阶梯而下，你看到一条用青石板铺成的小路，两边的墙壁皆是
花岗岩所筑。墙上每隔十几步就挂着一盏油灯，用来照亮密室。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"mi1",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object ob, env; 

	ob = this_player();
	env = environment(ob);

	if( arg != "按扭" && arg != "button" )
		return notify_fail("你要按什么?\n");
	if( !env->query("exits/up") ){
		message_vision("$N伸手在墙壁上的按钮按了一下，只听见哗地一声，石门升起来，露出一个向上的入口。\n", ob);
		env->set("exits/up", __DIR__"s_entrance");
	}
	else{
		message_vision("$N伸手在墙壁上的按钮按了一下，只听见哗地一声，石门又落了下来。\n", ob);
		env->delete("exits/up");
	}
	return 1;
}
