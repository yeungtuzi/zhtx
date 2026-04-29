// zhengting.c

inherit ROOM;
void create()
{
        set("short", "正厅");
        set("long", @LONG
这里就是华山剑宗所在地华山别院的正厅。正中间
放着一张沉重的红木大方案，中间的墙上挂着华山剑宗
始祖----蔡子峰的画像，以纪念这位武学宗师。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zhongting",
]));

        set("objects", ([
                __DIR__"npc/dizi2" : 1,
                 __DIR__"npc/dizi" : 4]));
        setup();
        replace_program(ROOM);
}

