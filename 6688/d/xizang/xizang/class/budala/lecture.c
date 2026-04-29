// /d/xizang/class/budala/lecture.c

inherit ROOM;

void create()
{
        set("short", "讲经房");
	set("long", @LONG
这里是布达拉宫讲经房,也是宫中最为尊贵的处所,因为至高无上的
达赖喇嘛就在此讲经说法.
LONG
        );
        set("exits", ([
		"northup" : __DIR__"ustair3",
	      "southdown" : __DIR__"ustair2",
		   "west" : __DIR__"west1",
		   "east" : __DIR__"east1",
]));
	set("objects", ([
                __DIR__"npc/dalai" : 1,
]));
	setup();
}

void init()
{
	add_action("do_listen", "listen");
}

int do_listen()
{
	object ob, me;
	
	me = this_player();
	if( me->is_busy() )
		return notify_fail("先休息一下吧.\n");

	if(!objectp(ob=present("da lai lama", this_object())) ||
		!living(ob))
		return notify_fail("没人讲经,你听个头\n");
	if((int)me->query("gin")<30 || (int)me->query("sen")<30)
		return notify_fail("你太累了,休息一会儿吧!\n");
	if((int)me->query_skill("zang-buddhi", 1)<10)
		return notify_fail("你听不懂那人咧咧些什么\n");
	if((int)me->query_skill("zang-buddhi", 1)>120)
		return notify_fail("你比讲经人还明白,不用听了\n");
	me->receive_damage("gin", 30);
	me->receive_damage("sen", 30);
	message_vision("$N正专心地听取达赖喇嘛讲解佛法要义.\n", me);
	me->improve_skill("zang-buddhi", me->query_int()+random(50));
	write("你觉得明白了不少道理.\n");
	me->start_busy(1);
	return 1;
}
