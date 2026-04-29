//RJQTING.C

inherit ROOM;

void create()
{
	set("short", "厚土旗大厅");
	set("long", @LONG
这里是厚土旗的大厅，放眼过去，只见四壁萧然，大概厚土旗
的家生都在地地下吧。正中两把椅子上的人正在下棋，不过似
乎有什么争执，大概是有人输了赖帐吧。
LONG
	);

	set("exits", ([
		"out" : __DIR__"tohtq2",
	]));

        set("objects",([
			__DIR__"npc/yanyuan":1,
			__DIR__"npc/zhoudian":1,
	]));
	
	setup();

}