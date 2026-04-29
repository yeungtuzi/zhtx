//      midao.c 密道
//      Designed by secret (秘密)
//      97/04/09
// /d/xizang/class/snow_mnt/midao.c

inherit ROOM;

void create()
{
        set("short","密道");
        set("long",@LONG
这是一条狭窄的暗道,通向一个密室.不过由于建造师动了手脚,谁也无法
打开通往密室的出口,也不知道里面藏了什么。
LONG
        );

        set("exits",([
                "east" : __DIR__"neidian",
        ]));

        setup();
}

void init()
{
	add_action("do_knock", "knock");
}

int do_knock(string arg)
{
	object me, room;
	if(!arg || arg!="conner")
		return notify_fail("你要敲什么地方?\n");
        if(query("exits/north"))
                return notify_fail("暗门开着呢.\n");
	if(!me->query("marks/secret")) {
		message_vision(
		"$N在密道上下左右各处敲打了一阵,但没能发现什么异常.\n", me);
		return 1;
	}
	message_vision("$N在密道西北角墙壁上轻轻敲了三下.\n", me);
	message("vision","随着机关动作的嘎吱声,北边墙上裂开一道口子.\n",
		this_object());
	set("exits/north", __DIR__"mishi");
	if( room = find_object(__DIR__"mishi") ){
		room->set("exits/south", __FILE__);
		message("vision",
		"随着机关动作的嘎吱声,南边墙上裂开一道口子.\n", room);
		}
	call_out("close_passage", 10);
}

void close_passage()
{
	object room;
	if( !query("exits/north")) return;
	message("vision",
	"随着机关动作的嘎吱声,墙上的裂缝合拢了,不留半点痕迹.\n", 
	this_object());
	if( room = find_object(__DIR__"mishi")){
		room->delete("exits/south");
		message("vision",
	"随着机关动作的嘎吱声,墙上的裂缝合拢了,不留半点痕迹.\n", room);
	}
	delete("exits/north");
}

