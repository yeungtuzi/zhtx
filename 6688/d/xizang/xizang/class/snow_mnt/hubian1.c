//      hubian1.c 湖边小路
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/class/snow_mnt/hubian1.c

inherit ROOM;

void create()
{
        set("short","湖边小路");
        set("long",@LONG
    这是圣湖边的小路。
LONG
        );

        set("outdoors","xizang");

        set("exits",([
                "east" : __DIR__"hubian2",
                "west" : __DIR__"shenghu",
        ]));

        setup();
//        replace_program(ROOM);
}
// 由此进入雪山寺
// add swim here

void init()
{
	add_action("do_swim", "swim");
}

int do_swim(string arg)
{
	object me;
	if (arg && arg!="") return 0;
	me=this_player();
	if(!me->query_skill("swimming", 1))
		return notify_fail("你不会任何水性,会淹死的!\n");
	me->move(__DIR__"huzhong");
	message_vision("$N扑通一声跳进湖里!\n");
	return 1;
}
