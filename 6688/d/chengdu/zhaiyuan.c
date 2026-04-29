
inherit ROOM;

void init();
int do_search(object me);

void create()
{
	set("short", "破旧宅院");
	set("long", @LONG
	这是成都城内的一座破旧的宅院，四处尘土，似乎是已经久久无人
居住。但是你总是感觉有点不对劲，好象暗中有什么人在窥伺，可是你四处
张望搜寻(souxun)，并没有发现什么可疑的地方。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xidajie1",
	]));

	setup();
}      

void init()
{
	add_action("do_search", "souxun");
}
            
int do_search(object me)
{      
        me=this_player();                     
	if( !(me->query("marks/hou")) )
	{
		message_vision("$N在院中四处张望，东翻西找，可是什么都没有找到。\n",me);
	}
	else
	{
		message_vision("$N在院子的隐秘处找到了一条秘道，$N沉吟了一下，勇敢地走了进去。\n",me);
		me->move(__DIR__"mishi");
		me->set("marks/hou",0);
	}
	return 1;
}
           


