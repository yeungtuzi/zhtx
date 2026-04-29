// /d/xizang/class/gold_wh/uroad3.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里是一条荒草迷漫的小路,往南延伸到西藏草原，北边据说通往昆仑山.西
边有座宏伟庄严的寺院,便是密宗金轮派札什伦布寺.
LONG
        );
        set("exits", ([
                "northup" : "/d/xizang/klroad1",
              "southdown" : __DIR__"uroad2",
		   "west" : __DIR__"qqroad",
]));
        set("outdoors", "xizang");

        setup();
	replace_program(ROOM);
}
