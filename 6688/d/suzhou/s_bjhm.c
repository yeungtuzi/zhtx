//by tlang

#include <ansi.h>
#include <room.h>
inherit ROOM;

int close_gate();
int do_knock(string arg);
int valid_leave(object me,string dir);

void create()
{
	set("short", HIC"镖局后门"NOR);
	set("long", @LONG
	这是镖局的后门，东北方向是一条阴森的小巷子，南边一大片建筑
，正是镖局，里面传来轻轻的吆喝声。门关着，里面有守门弟子的说话声，
看来镖局防守的挺严，以免外人擅自闯入镖局后院。镖局中的弟子想要进去
，大概也只能敲(knock)门了。
LONG
	);
	set("outdoors", "suzhou");

	set("exits", ([
		"south" : __DIR__"bjhyuan", 
		"northeast" : __DIR__"xx",
	]));
                                   
	setup();
}

void init()
{
    add_action("do_knock", "knock");
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"bjhyuan")) )
        room = load_object(__DIR__"bjhyuan");
    if(objectp(room))
    {
        delete("exits/south");
        message("vision", "乒地一声，里面有人把大门关上了。\n",
            this_object());
        room->delete("exits/north");
        message("vision", "守门弟子上前把大门关了起来。\n", room);
    }
    else message("vision", "ERROR: door not found(close).\n", room);
	  return 1;
}

int do_knock(string arg)
{
    object room;

    if (query("exits/south"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "south"))
        return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"bjhyuan")) )
        room = load_object(__DIR__"bjhyuan");
    if(objectp(room))
    {
        set("exits/south", __DIR__"bjhyuan");
        message_vision("$N轻轻地敲了敲门，只听吱地一声，"
            "一位镖局弟子应声打开大门，\n"
            "他用锐利的目光上上下下打量着$N。\n",
            this_player());
        room->set("exits/north", __FILE__);
        message("vision", "外面传来一阵敲门声，守门弟子应声上前把大门开。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }

    return 1;
}

int valid_leave(object me, string dir)
{
	if ( dir != "south" )
    	{
        	return ::valid_leave(me, dir);
    	}

	if (!::valid_leave(me, dir))
	        return 0;

        if( !me->query("biao_ju") )
        {
                return notify_fail("守门弟子说道：“外人不能由后门进镖局。”\n");
        }
        write("守门弟子侧身让开，说道：既然是同门，辛苦了，请进。\n");
            return 1;
}

