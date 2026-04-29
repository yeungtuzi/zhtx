inherit ROOM;

void create()
{
        set("short", "秘道");
        set("long", @LONG
这是一条阴暗的地道，在黑暗之中，秘道似乎永无尽头。只有两旁
的油灯发着昏黄的灯光。墙壁上似乎有个开关(switch)可以推(push)。
LONG
        );
        set("exits", ([ 
  	"south" : __DIR__"tohtq4",
	]));
        
        setup();
}

void init()
{
        add_action("do_open","push");
}
int do_open(string arg)
{
        object me;
	
        if(!arg || arg=="")
        {
                write("你要往上(up)还是往下(down)扳开关？\n");
                return 1;
        }
        if( arg == "up" )
        {
        	me = this_player();
	        message_vision("$N试着往上扳了一下开关，一阵机括声过后，$N被送上了地面。\n", me);
		tell_room(__DIR__"tohtq2","一个身影从下面冒了出来");
		me->move(__DIR__"tohtq2");
	        return 1;
	}
        else 
	if( arg == "down" )
        {

        	me = this_player();
	        message_vision("$N试着往下扳了一下开关，一阵机括声过后，$N被送上了地面。\n", me);
		tell_room(__DIR__"htqdating","一个身影从下面冒了出来");
		me->move(__DIR__"htqdating");
                return 1;
        }
}
