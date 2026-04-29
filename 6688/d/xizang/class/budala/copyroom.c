// /d/xizang/class/budala/copyroom.c

inherit ROOM;

void create()
{
        set("short", "抄经室");
        set("long", @LONG
这里是抄写佛经的房间,有许多青年弟子在这里工作(work).东边的几个房间
里整齐排放着布达拉宫保存的各种佛经,其中一些就是刚刚抄好从这里送去的.到
这里来请保持安静,切勿喧哗!
LONG
        );
        set("exits", ([
           "east" : __DIR__"storage2",
	  "south" : __DIR__"sj2",
]));
	set("objects", ([
		__DIR__"npc/yeqiu" : 1,
	]));
        setup();
//        replace_program(ROOM);
}
//here add working

void init()
{
        add_action("do_work", "work");
}

int do_work()
{
	object ob, me;
	me=this_player();
	if(!me->query_skill("literate", 1))
		return notify_fail("你是个文盲,这工作没法做.\n");
	if ((int)me->query("sen")<30 || (int)me->query("gin")<30)
		return notify_fail("你太累了,休息一下吧!\n");
	me->add("gin",-30);
	me->add("sen",-30);
	message_vision("$N辛苦的工作终于结束了，可人也累的要死\n", me);
	if ((int)me->query_skill("literate", 1) < 51)
		me->improve_skill("literate", 1+random(10));
	if ((int)me->query_skill("zang-buddhi", 1) <101)
		me->improve_skill("zang-buddhi", 1+random(10));
	ob = new(SILVER_OB);
	ob->move(me);
	write("这是你的工钱。\n");
	return 1;
}
