inherit ROOM;
void create()
{
        set("short", "波斯战船");
        set("long", @LONG
	这是一艘雄伟的波斯战船，船头插着一面绣金大旗，清风徐来，船身
随浪轻轻晃动。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"tiaoban0",
	"south" : __DIR__"tiaoban1",
	"north" : __DIR__"tiaoban7",
]));
        set("objects", ([
//        __DIR__"/class/mingjiao/juming" : 1,
//	__DIR__"npc/bosi-jiaozhong": 4,
        ]) );

        setup();
        replace_program(ROOM);
}
