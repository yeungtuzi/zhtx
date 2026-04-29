inherit ROOM;
void create()
{
        set("short", "波斯战船");
        set("long", @LONG
	这是一艘巨大雄伟的波斯战船，船头一面绣有光明圣火的白色旗帜随风猎猎做响，
舱内陈设华丽，供奉着光明圣火。正中是一张宝座朝向东方。正是波斯明教教教主的座船。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"south" : __DIR__"tiaoban13",
	"north" : __DIR__"tiaoban14",
]));
        set("objects", ([
//        __DIR__"npc/wang12" : 1,
	  __DIR__"npc/bosi-jiaozhong" : 4,
        ]) );

        setup();
        replace_program(ROOM);
}
