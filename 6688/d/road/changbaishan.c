
inherit ROOM;

void create()
{
	set("short", "长白山");
	set("long", @LONG
这里是长白山的入口。长白山中碧溪淙淙，林木苍翠，有数不尽的珍禽异兽、
花草树木，进入山中，你可以从淳朴豪迈的鄂伦春人手中换到珍贵的人参、
鹿茸和貂皮，也可以自己去打猎，如果你受了内伤，长白山的药泉可是疗伤的
至宝。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
           "northwest":"/d/xanadu/inn",
	"south" : "/d/road/rfttocbs2",
        "east"  : "/d/xueshan/start",
]));

	setup();
	replace_program(ROOM);
}
