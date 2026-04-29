inherit ROOM;
void create()
{
        set("short", "波斯战船");
        set("long", @LONG
	这是一艘雄伟的波斯战船，船头插着一面绣金大旗，下面一把虎皮交椅，一人端
坐其中。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"tiaoban5",
	"west" : __DIR__"tiaoban6",
]));
        set("objects", ([
        "/class/mingjiao/zhene" : 1,
 	__DIR__"npc/bosi-jiaozhong" : 2,
        ]) );

        setup();
        replace_program(ROOM);
}
