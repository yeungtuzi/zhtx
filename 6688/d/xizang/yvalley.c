// /d/xizang/yvalley.c

inherit ROOM;

void create()
{
        set("short", "峡谷");
        set("long", @LONG
这里是一条宽阔的峡谷,轰鸣的水声就从下面那条大江传来,远远望去,只见
江水汹涌澎湃,两岸是葱绿的丛林和草地,宛如人间仙境.那就是藏人常说的母亲
河雅鲁藏布江.
LONG
        );
        set("exits", ([
  "southdown" : __DIR__"river",
    "northup" : __DIR__"y_road1",
       "east" : __DIR__"class/hama/yvalley0",
       "west" : __DIR__"yvalley1",
]));
	set("outdoors", "xizang");
        setup();
        replace_program(ROOM);
}
