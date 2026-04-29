
inherit ROOM;

void create()
{
        set("short", "药房");
        set("long", @LONG
	这是一间小小的药房，房内弥漫着药香，到处都是大大小小的药柜。
胡青牛身为医仙，所备药物自然都是极品。
LONG
        );
	set("amount",3);
        set("exits", ([ 
  "east" : __DIR__"hdj",
]));
        set("objects", ([
               "/d/taishan/obj/tongtiancao" : 1,
        ]) );
        set("outdoors", "mingjiao");
        setup();
}

void init()
{
        add_action("do_open", "open");
}
int do_open(string arg)
{
	object medicine;

	if(!arg || arg != "closet")
		return notify_fail("你要打开什么？\n");
	else
	{
		if( this_player()->query("combat_exp") < 100000)
			return notify_fail("小心谷主看见了打死你。\n");
		if( !query("amount") )
			return notify_fail("药已经被取光了。\n");
		if( this_player()->query_temp("get_medicine") )
			return notify_fail("贪心！贪心！！\n");
		if( random(10) == 0 ) 
		{
			message_vision("$N打开药柜，趁人不备，从中掏出一剂药藏入怀中，慌乱中也没有看到是哪一味药。\n",this_player());
			if( random(2) == 0 )
				medicine = new(__DIR__"obj/medicine");
			else
				medicine = new(__DIR__"obj/poison");								
			medicine->move(this_player());
			add("amount",-1);
			if( query("amount") <= 0)
				delete("amount");
			this_player()->set_temp("get_medicine",1);
			return 1;
		}

		return  notify_fail("你打开药柜，伸手进去一阵乱摸。\n");
	}

}



