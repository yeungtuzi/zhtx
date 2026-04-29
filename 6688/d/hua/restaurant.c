// Room: /d/hua/restaurant.c

inherit ROOM;

void create()
{
	set("short", "仙客来饭庄");
	set("long", @LONG
这是一家老字号饭庄，远近闻名。
    正中墙上挂着一个菜单(menu), 一个精明伶俐的店小二
正在忙里忙外的招呼客人，你可以点(order)你想吃的菜。
北面有一扇月门，从挂着布帘的缝隙中隐约可以看到里间
厨房中老板娘正忙着炒菜。
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kitchen",
  "southwest" : "/d/road/rfttocbs1",
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "menu" : "猪肉炖粉条，鱼香肉丝，酸菜白肉，油焖大虾，西湖醋鱼，香稣鸡，酸辣汤，鼋鱼蛋汤\n",
  "菜单" : "猪肉炖粉条，鱼香肉丝，酸菜白肉，油焖大虾，西湖醋鱼，香稣鸡，酸辣汤，鼋鱼蛋汤\n",
]));
//        set("no_fight", 1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/waiter" : 1,
]));
        set("no_clean_up", 0);
//        set("no_magic", 1);

	setup();
}

/*
void init()
{
        add_action("do_order", "order");
        add_action("do_leave", "go");
        add_action("do_leave1", "south");
	add_action("do_leave2", "north");
        add_action("no_quit", "quit");
}

int no_quit()
{
        object me;
        me = this_player();
        if (me->query("marks/点菜")) {
                tell_object(me, "你没交钱，还想溜吗? 没门儿! \n");
                message_vision("$N刚想溜，就被店小二师揪了回来! \n", me);
                return 1;
        }
        return 0;
}

int do_leave(string arg)
{
        object me;
        int i;
        string num;
        if (arg != "southwest" && arg != "north") return 0;
        me = this_player();
	if (arg == "southwest") {
        	if ((i = me->query("marks/点菜"))) {
                	num = sprintf("%d", i);
                	tell_object(me, "店小二笑着对你说：你点了" + num + "道菜，请你付" + num + "两银子再走。\n");
                	return 1;
		}
		else {
			me->move("/d/road/rfttocbs1");
			return 1;
		}
        }
        me->move(__DIR__"kitchen");
        return 1;
}

int do_leave1()
{
        object me;
        int i;
        string num;
        me = this_player();
        if ((i = me->query("marks/点菜"))) {
                num = sprintf("%d", i);
                tell_object(me, "店小二笑着对你说：你点了" + num + "道菜，请你付" + num + "两银子再走。\n");
                return 1;
        }
        me->move("/u/quicksand/huangyie0");
        return 1;
}

int do_leave2()
{
	object me;
	me = this_player();
	me->move(__DIR__"kitchen");
	return 1;
}

int do_order(string arg)
{
        object me, ob, foods, soup;
        int i;
        me = this_player();
        if (!arg || arg == "") {
                write("你要点什么?\n");
                return 1;
        }
	if (arg != "猪肉炖粉条" &&
	    arg != "鱼香肉丝" &&
	    arg != "酸菜白肉" &&
	    arg != "油焖大虾" &&
	    arg != "西湖醋鱼" &&
	    arg != "香稣鸡" &&
	    arg != "酸辣汤" &&
	    arg != "鼋鱼蛋汤") {
		write("店小二两手一摊说：本店没有这道菜。\n");
		return 1;
	}
	if (arg == "鼋鱼蛋汤" ||
	    arg == "酸辣汤") {
		soup = new("/d/hua/obj/soup");
		soup->set("liquid/name", arg);
		soup->set("long", "一只金边蓝底儿的大海碗。\n");
		soup->move(me);
	}
	else {
        	foods = new("/d/hua/obj/foods");
        	foods->set_name(arg, ({"food"}));
        	foods->set("long", "一碗色香味具全的" + arg + "。\n");
        	foods->move(me);
	}
        if (!me->query("marks/点菜")) 
                me->set("marks/点菜", 1);
        else
                me->add("marks/点菜", 1);
        message_vision("$N向店小二点了一道" + arg + "。\n", me);
        return 1;
}
*/
