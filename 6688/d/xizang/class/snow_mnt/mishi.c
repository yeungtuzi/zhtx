//      mishi.c 密室
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/class/snow_mnt/mishi.c

inherit ROOM;

void create()
{
        set("short","密室");
        set("long",@LONG
这是一个小房间,北边墙上似乎有小窗口,用木板掩着.
LONG
        );

	set("objects", ([
		__DIR__"obj/shaolinb" : random(3)
	]));

        setup();
}

void init()
{
	add_action("do_out", "out");
}

int do_out(string arg)
{
	object me;
	if(arg && arg!="") return notify_fail("这里没有出口!\n");
	me=this_player();
	message_vision("$N掀开木板,从小窗口钻了出去.\n", me);
	me->move(__DIR__"backroad");
	return 1;
}
