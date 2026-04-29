// /d/xizang/class/budala/stone2.c

inherit ROOM;

void create()
{
        set("short", "石经室");
	set("long", @LONG
这里是一栋石头小屋,墙上密密麻麻刻写着经文.
LONG
        );
        set("exits", ([
	       "south" : __DIR__"stone1",
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

        me = this_player();

        if ( !arg || ( arg != "stone" && arg != "wall" ) )
                return 0;

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

        if ( (int)me->query("gin") < 30)
                return notify_fail("你的精不够了，还是先好好修习一下吧。\n");

	if ( (int)me->query_skill("zang-buddhi", 1) < 100)
		return notify_fail("你根本看不懂墙上刻的经文是什么意思.\n");
	me->receive_damage("gin", 30);

        message_vision("$N正专心研读刻在墙上的佛经。\n", me);

        if ( (int)me->query_skill("zang-buddhi", 1) < 220)
        {
                me->improve_skill("zang-buddhi", me->query("int"));
                write("你对着刻在墙上的经文琢磨了一回儿，似乎对大乘佛法略有心得。\n");
                return 1;
        }
        write("你对着墙壁瞧了一回儿，发现上面所说的佛理太过浅显，对你来说已毫无意义了。\n");
        return 1;
}
