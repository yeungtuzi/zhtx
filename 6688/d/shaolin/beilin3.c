// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19

inherit ROOM;

int do_study(string);

void create()
{
	set("short", "地下室");
	set("long", @LONG
这里是佛塔底下的地下密室。密室虽小，却也五脏俱全，
石桌石椅，石几石床，连室内放的几件器皿，也都是石制的。
看来似乎很久以前有人在这里住过。正中的石桌上平放着一块
薄薄的石板，上面好象刻着些什么。
LONG
	);

	set("objects",([
		"d/shaolin/obj/book-stone" : 1,
	]));

	set("item_desc", ([
		"table" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。\n",
	]));

	setup();
}

void init()
{
	add_action("do_study", "study");
}


int do_study(string arg)
{
	object me;
	int exp,level;

	me = this_player();

	if ( !arg || ( arg != "table" ) )
		return notify_fail("什么？\n");

	if ( (int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	if(me->query("gin")<10) return notify_fail("你的精力不够集中,没法研究了.\n");

	me->receive_damage("gin", random(40));

	message_vision("$N正专心研读石桌上的古怪图形。\n", me);

	exp = me->query("combat_exp");

	switch( random(5) ) 
	{
		case 0:
			level = me->query_skill("finger",1);
			if( level*level*level/10 > exp )	
			{
				write("你对着石桌琢磨了一回儿，发现上面所说的太过深奥，你看不懂。\n");
				return 1;
			}

			if ( level < 100 )
			{
				me->improve_skill("finger", me->query("int"));
				write("你对着石桌琢磨了一回儿，似乎对指法有点心得。\n");
			}
			else 
				write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
			break;
		case 1:
			level = me->query_skill("claw",1);
			if( level*level*level/10 > exp )	
			{
				write("你对着石桌琢磨了一回儿，发现上面所说的太过深奥，你看不懂。\n");
				return 1;
			}

			if ( level < 100 )
			{
				me->improve_skill("claw", me->query("int"));
				write("你对着石桌琢磨了一回儿，似乎对爪法有点心得。\n");
			}
			else
				write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
			break;
		case 2:
			level = me->query_skill("strike",1);
			if( level*level*level/10 > exp )	
			{
				write("你对着石桌琢磨了一回儿，发现上面所说的太过深奥，你看不懂。\n");
				return 1;
			}

			if ( level < 100 )
			{
				me->improve_skill("strike", me->query("int"));
				write("你对着石桌琢磨了一回儿，似乎对掌法有点心得。\n");
			}
			else
				write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
			break;
	    	case 3:
			level = me->query_skill("cuff",1);
			if( level*level*level/10 > exp )	
			{
				write("你对着石桌琢磨了一回儿，发现上面所说的太过深奥，你看不懂。\n");
				return 1;
			}

			if ( level < 100 )
			{
				me->improve_skill("cuff", me->query("int"));
				write("你对着石桌琢磨了一回儿，似乎对拳法有点心得。\n");
			}
			else
				write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
			break;
	    	case 4:
			level = me->query_skill("hand",1);
			if( level*level*level/10 > exp )	
			{
				write("你对着石桌琢磨了一回儿，发现上面所说的太过深奥，你看不懂。\n");
				return 1;
			}

			if ( level < 100 )
			{
				me->improve_skill("hand", me->query("int"));
				write("你对着石桌琢磨了一回儿，似乎对手法有点心得。\n");
			}
			else
				write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
	}


	return 1;
}

