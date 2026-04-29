// /d/xizang/small_r.c

inherit ROOM;

void create()
{
        set("short", "小路");
	set("long", @LONG
这里是一条弯弯曲曲的小路,不知道通向哪里.
LONG
        );
        set("exits", ([
                "west" : __DIR__"class/budala/trash",
		"east" : __DIR__"small_r0",
	]));
        set("outdoors", "xizang");
        setup();
}

int valid_leave(object me, string dir)
{
	if (dir=="west") {
		me->add_temp("wcount", 1);
		if(me->query_temp("wcount") >= 5) {
			me->delete_temp("wcount");
			return 1;
		}
		else {
			me->move(__FILE__);
			return 
		notify_fail("你不停地走着,小路好象没有尽头一样.\n");
		}
	}
	if (dir=="east"){
		me->add_temp("wcount", -1);
		if(me->query_temp("wcount") <= -5) {
                        me->delete_temp("wcount");
                        return 1;
                }
		else {
                        me->move(__FILE__);
		notify_fail("你不停地走着,小路好象没有尽头一样.\n");
                }
	}
	return 0;
}
