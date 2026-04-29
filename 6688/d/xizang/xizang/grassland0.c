// /d/xizang/grassland0.c

inherit ROOM;

void create()
{
        set("short", "草原");
        set("long", @LONG
这里是一望无际的大草原。绿色的草地美丽得就象晴朗的蓝天。草原上
三三两两的羊群则是蓝天上飘浮的朵朵白云。东边不远是一座高耸的雪山,
山顶的积雪映着阳光闪闪发亮. 西边是通往拉萨的方向, 虽然也算是一条大
路, 但是因为走的人不多, 偶尔也有野兽出没. 北边据说是通往昆仑山的方
向.
LONG
        );
        set("exits", ([
    "east" : __DIR__"mroad2",
   "north" : __DIR__"klroad0",
    "west" : __DIR__"grassland1",
]));
        set("outdoors", "xizang");
	set("objects", ([
		__DIR__"npc/maoniu" : 1+random(2)
	]));
        setup();
        replace_program(ROOM);
}
