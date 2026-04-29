// /d/xizang/w_house.c

inherit ROOM;

void create()
{
        set("short", "小木屋");
        set("long", @LONG
这是一座简陋的小木屋,似乎曾有人住在这里,还铺设了简单的床榻(bed),但
显然已经很久没人用过了.
LONG
        );
        set("exits", ([
	    "north" : __DIR__"xmly4",
]));
	set("item_desc", ([
		"bed" : "这是用茅草铺成的简易床铺,看上去有些乱.\n",
	]));
        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
	object paper, me;

	if(!arg ||(arg!="bed" && arg!="床"))
		return notify_fail("你要翻什么?\n");
	me=this_player();
	message_vision("$N在茅草铺成的床上一通乱翻,把床弄得更乱了.\n", me);
	if((int)me->query("kar") > random(31)) {
		paper=new(__DIR__"npc/obj/paper");
		paper->move(me);
		message_vision("$N找到一张小纸片!\n", me);
	}
	return 1;
}
