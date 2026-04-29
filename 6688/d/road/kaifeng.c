
inherit ROOM;

void create()
{
	set("short", "开封");
	set("long", @LONG               
    这里是中原重镇之一－－开封，一条大道穿城而过，道路两旁有
不少的民居，据说许多已婚的武林人物居住在此。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"north" : "/d/road/rkftodk0",
	"south" : "/d/road/rhktokf4",
	"west" : "/d/road/rjdtoly0",
	"east" : "/d/road/rxztokf3",
]));
	set("objects", ([
//                "/obj/npc/saint" : 1,
                "/u/m/masterall/npc/saint" : 1,
        ]) );

	setup();
	replace_program(ROOM);
}
