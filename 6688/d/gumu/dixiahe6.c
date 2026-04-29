// /d/xingxiu/dixiahe6.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "地下河");
        set("long", @LONG
    这是一条地下和，表面上看起来很平静。河里有许多
漩涡，游起来该注意一下，别走进漩涡里去了。
LONG
        );

        set("exits", ([
    /*    "northeast" : __FILE__,
        "southeast" : __FILE__,
        "southwest" : __FILE__,
        "northwest" : __FILE__,*/
        "north" : __DIR__"dixiahe4",
        "west" : __DIR__"dixiahe7",
        "south" : __DIR__"dixiahe",
        "east" : __DIR__"dixiahe3",
        ]));
        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_enter", "enter");
}


int valid_leave(object me, string dir)
{
        int current_kee;

        current_kee = me->query("kee");
        if (current_kee<50) {
          write("你已经感到不行了，冥冥中你觉得被水冲出暗河。\n");
          me->move(__DIR__"xidi");
          me->unconcious();
        }

        if (current_kee>0 && current_kee<=100) {
            write("你已经游得精疲力尽了。\n");
            me->set("water",0);
        }

        if (current_kee>50) {
            me->set("kee",current_kee-50);
        }
    //    if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
      //     return notify_fail("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
        return ::valid_leave(me, dir);
}

int do_enter(string arg)
{
	  object me;


        me = this_player();
 
        if
( !arg || ( arg != "xuanwo" ) )
{write("你要往哪儿去？\n",me);return 1;}
if (me->query_temp("zhenjing")!=1)
	{
  if (me->query("kee")>300)
	   {write("你用力向漩涡中钻去，结果被卷了出来。\n",me);
		 me->unconcious();
return 1;}
	else
		{write("你用力向漩涡中钻去，结果被卷入了其中，你拼命挣扎，还是不能从那儿出来。\n",me);
		me->die();
	return 1;}
	}
else
		{if (me->query("kee")<300)
			{write("你用力向漩涡中钻去，结果被卷入了其中，你拼命挣扎，还是不能从那儿出来。\n",me);
		me->die();
	return 1;}
		else
			{

write("你用力向漩涡中钻去，发现漩涡里有一个小洞，你一喜之下钻了进去。\n",me);
	me->add("kee",-300);
	  me->move(__DIR__"dong");
	 say("$N一下不见了\n",me);
	me->set_temp("zhenjing",0);
	return 1;
	}
	}
}