// luoyan.c 落雁峰

inherit ROOM;

void create()
{
        set("short", "落雁峰");
	set("long", 
@LONG
这里是华山的南峰之一--落雁峰，是由于这里山太高，大雁到这里也飞不
过去，必须在这里歇息，故取名。在这里向四处观望，真是山恋起伏，苍苍莽
莽。确有“西岳冷层竦处尊，诸峰罗立似儿孙”之感。
    南边就是五岳剑派之一--华山派的驻地，等闲人还是不要轻易去那里招惹
武林人事的好。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
		  "westdown" : __DIR__"jintian",
		  "south" :__DIR__"gate"
	]));


        set("outdoors", "huashan" );

        setup();
        replace_program(ROOM);
}
 
