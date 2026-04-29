// Room: /d/lingjiu/s_entrance.c

inherit ROOM;

void create()
{
	set("short", "地下密室入口");
	set("long", @LONG
这里通向灵鹫宫的地下密室，看管甚严，若非有童姥命令，是谁也
不允许进入的。你的面前是一道石门，石门的旁边有一个按钮。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"garden",
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
	if( !env->query("exits/down") ){
		message_vision("$N伸手在墙壁上的按钮按了一下，只听见哗地一声，石门升起来，露出一个向下的入口。\n", ob);
		env->set("exits/down", __DIR__"mi0");
	}
	else{
		message_vision("$N伸手在墙壁上的按钮按了一下，只听见哗地一声，石门又落了下来。\n", ob);
		env->delete("exits/down");
	}
	return 1;
}
