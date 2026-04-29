
inherit ROOM;

void create()
{
	set("short", "嘉峪关");
        set("long", @LONG
嘉峪关是万里长城西端的险要关塞，因其雄峙祁连雪峰
与黑山之间，地势险峻，气势雄宏，被誉为"天下雄关"。
嘉峪关楼阁凌空，飞檐重叠，巍峨壮观，与"天下第一
关"的山海关遥相对峙，共同闻名於天下。 

入关之后再行东往,就是西夏国的都城了。
LONG
        );

	set("exits", ([ /* sizeof() == 3 */
	"west" : "/d/road/rjygtodh0",
         "east" : "/d/xixia/westroad1",
]));

	setup();
	replace_program(ROOM);
}
