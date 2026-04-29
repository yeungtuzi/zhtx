// Room: /d/lingjiu/medicineroom.c

inherit ROOM;

void create()
{
	set("short", "药品房");
	set("long", @LONG
这里是灵鹫宫的药品房，一排排木架上整齐放着各种各样的药瓶。
童姥的武功固然令江湖中人闻风丧胆，难得的是她文才武略，无一
不精，不得不令人佩服。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"bookroom",
]));
	set("wan_count", 1);

	setup();
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	object me = this_player();

	if( me->is_busy() )
		return notify_fail("你正忙着了。\n");
	if( !arg || arg == "")
		return notify_fail("你要搜什么？\n");

	if( arg != "支架" && arg != "shelf" )
		return notify_fail("这里没有"+arg+"。\n");

	me->start_busy(1);
	if( !query("wan_count") )
		return notify_fail("你什么也没搜到。\n");
	add("wan_count", -1);
	new(__DIR__"obj/wan")->move(me);
	message_vision("$N在支架里左找右找，找到了一瓶药丸。\n", me);
	return 1;
}
